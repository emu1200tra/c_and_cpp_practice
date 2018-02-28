#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <signal.h>
#include <time.h>
#include <sched.h>
#include <sys/resource.h>




void time_unit(){ 
  volatile unsigned long i; 
  for(i=0;i<1000000UL;i++); 
}
//RR單位時間

typedef struct{
  char job_name[32];
  int ready_time;
  int exe_time;
  int already_exe_time;
  int start_time;
  int end_time;
}job;
//job資訊

int arc = 0;  //儲存修改前的priority

void sig_handle(int unused){
    //喚醒chld提高權限
    arc = getpriority(PRIO_PROCESS , getpid());
    if(nice(sched_get_priority_max(SCHED_RR))<0){
        perror("nice:");
    }
}

void sig_handle2(int unused){
    //block child
    if(nice(arc) < 0){
    	perror("nice2:");
    }
    pause();
}

int sign = 0;
//避免chld或parent任何一個先走發送signal住的狀況

void sig_handle3(int unused){
    //確認chld可以開始工作
    sign = 1;
}


int main(){
  cpu_set_t my_set;       
  CPU_ZERO(&my_set);       
  CPU_SET(1, &my_set);     
  sched_setaffinity(0, sizeof(cpu_set_t), &my_set); 
  //放到0號CPU

  int num_job;
  scanf("%d" , &num_job);
  job *job_list = malloc(sizeof(job) * num_job);
  for(int i = 0 ; i < num_job ; i++){
    scanf("%s %d %d" , job_list[i].job_name , &job_list[i].ready_time , &job_list[i].exe_time);
    job_list[i].already_exe_time = 0;
    job_list[i].start_time = -1;
    job_list[i].end_time = -1;
  }
  //吃入工作資訊

  int done = 0;                                   //完成工作數量
  int *job_pin = malloc(sizeof(int) * num_job);   //job所用的pid
  
  struct sigaction sa_usr1;
  sa_usr1.sa_flags = SA_RESTART;
  sa_usr1.sa_handler = sig_handle;
  struct sigaction sa_usr2;
  sa_usr2.sa_flags = SA_RESTART;
  sa_usr2.sa_handler = sig_handle3;
  sigaction(SIGUSR1, &sa_usr1, NULL);
  sigaction(SIGUSR2, &sa_usr2, NULL);
  int *job_que = malloc(sizeof(int) * num_job);   //可執行的job
  int job_que_index = 0;                          //已生成的job數量
  int job_que_now = -1;                           //現在執行的job位置
  int prev = 0 , now = 0 , jobcount = 0;          //prev:本次工作開始執行時間 now:現在時間 jobcount:目前有的可工作job數量
  
  while(done != num_job){
    //主要排程區域
    for(int i = 0 ; i < num_job ; i++){
      if(now == job_list[i].ready_time){
        //ready時間到，生成job
        jobcount++;
        job_pin[i] = fork();
        if(job_pin[i] == 0){  
          sched_setaffinity(0, sizeof(cpu_set_t), &my_set);  ////確認chld到在0號core  
          sa_usr2.sa_handler = sig_handle2;
          sigaction(SIGUSR2, &sa_usr2, NULL);
          kill(getppid() , SIGUSR2);              //通知parent可以開始做事
          pause();                                //等待開始的signal
          while(1);
          exit(0);
        }
        else if(job_pin[i] == -1){
          perror("fork error!");
          exit(-1);
        }
        else{
          //parent先等chld發送確認signal
          if(sign == 0){
            pause();
          }
          else{
            sign = 0;
          }
          job_que[job_que_index] = job_pin[i];    //把job放入可執行工作的que
          job_que_index++;                        //que中的job數量
        }
      }
      else if(job_list[i].already_exe_time == job_list[i].exe_time && job_que[i] != -1){
        //job已到完成時間，踢出scheduler
        kill(job_pin[i] , SIGKILL);
        wait(NULL);                               //收掉chld
        jobcount--;                               //可工作數量減少
        job_que[i] = -1;                          //在que中標示該job已完成，自動忽略
        done++;                                   //紀錄完成的工作數量
        job_list[i].end_time = now;               //紀錄完成時間
        if(done == num_job){
          goto jump;                              //若所有工作皆已完成，跳出while
        }
      }
    }
    if(job_que_index != 0 && jobcount != 0){
      if(job_que_now == -1){                      //第一個開始執行的工作
        job_que_now = (job_que_now + 1) % job_que_index;    //將job_que_now指向現在在做的job
        if(job_list[job_que_now].start_time == -1){         //紀錄工作開始時間
          job_list[job_que_now].start_time = now;
        }
        struct sched_param param;                           //提高工作的權限
        param.sched_priority =  sched_get_priority_max(SCHED_RR);
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        kill(job_que[job_que_now] , SIGUSR1);               //准許工作開始執行
        prev = now;                                         //紀錄本次開始工作時間
      }
      else if(job_que_now != -1 && job_que[job_que_now] == -1){   //遇到已完成的工作
        while(job_que[job_que_now] == -1){                        //將job_que_now指向下一個可開始做的工作
          job_que_now = (job_que_now + 1)% job_que_index;
        }
        if(job_list[job_que_now].start_time == -1){               //紀錄工作起始時間
          job_list[job_que_now].start_time = now;
        }
        struct sched_param param;                                 //提升工作權限
        param.sched_priority =  sched_get_priority_max(SCHED_RR);
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        kill(job_que[job_que_now] , SIGUSR1);               //喚醒該工作
        prev = now;                                         //紀錄本次工作開始時間
      }
      else if(job_que_now != -1 && job_que[job_que_now] != -1 && (now-prev)%500 == 0){    //一般時間到的context switch
        struct sched_param param;                                                         //降低前一次工作的權限
        param.sched_priority =  99;
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        kill(job_que[job_que_now] , SIGUSR2);               //block該工作
        if(job_que[(job_que_now+1)%job_que_index] == -1){   //切到下一個可執行的工作
          job_que_now = (job_que_now + 1)%job_que_index;
          while(job_que[job_que_now] == -1){
            job_que_now = (job_que_now + 1)% job_que_index;
          }
        }
        else{
          job_que_now = (job_que_now + 1) % job_que_index;  
        }
        if(job_list[job_que_now].start_time == -1){         //紀錄工作起始時間
          job_list[job_que_now].start_time = now;
        }
        param.sched_priority =  sched_get_priority_max(SCHED_RR);                         //提升工作權限
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        kill(job_que[job_que_now] , SIGUSR1);               //喚醒該工作
        prev = now;                                         //紀錄本次工作開始時間
      }
    }
    time_unit();                                            //間隔一單位時間
    if(job_que_now != -1){                                  //增加該工作的已完成時間
      job_list[job_que_now].already_exe_time++;  
    }
    now++;                                                  //更新現在時間
    jump:
      continue;
  }
  for(int i = 0 ; i < num_job ; i++){
    printf("%s %d %d\n", job_list[i].job_name , job_list[i].start_time , job_list[i].end_time);   //輸出各工作開始時間和最後的完成時間
  }

  return 0;
}
