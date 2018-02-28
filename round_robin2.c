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


typedef struct{
  char job_name[32];
  int ready_time;
  int exe_time;
  int already_exe_time;
  int start_time;
  int end_time;
}job;

//int arc = 0;

void sig_handle(int unused){
    //arc = getpriority(PRIO_PROCESS , getpid());
    //if(nice(sched_get_priority_max(SCHED_RR))<0){
    //    perror("nice:");
    //}
}

void sig_handle2(int unused){
    //if(nice(arc) < 0){
    //  perror("nice2:");
    //}
    pause();
}

int sign = 0;

void sig_handle3(int unused){
    sign = 1;
}

int main(){
  cpu_set_t my_set;       
  CPU_ZERO(&my_set);       
  CPU_SET(1, &my_set);     
  sched_setaffinity(0, sizeof(cpu_set_t), &my_set); 

  int num_job;
  scanf("%d" , &num_job);
  job *job_list = malloc(sizeof(job) * num_job);
  for(int i = 0 ; i < num_job ; i++){
    scanf("%s %d %d" , job_list[i].job_name , &job_list[i].ready_time , &job_list[i].exe_time);
    //printf("check: %s %d %d\n" , job_list[i].job_name , job_list[i].ready_time , job_list[i].exe_time);
    job_list[i].already_exe_time = 0;
    job_list[i].start_time = -1;
    job_list[i].end_time = -1;
  }
  int done = 0;
  int *job_pin = malloc(sizeof(int) * num_job);
  //printf("check 1\n");
  struct sigaction sa_usr1;
  sa_usr1.sa_flags = SA_RESTART;
  sa_usr1.sa_handler = sig_handle;
  struct sigaction sa_usr2;
  sa_usr2.sa_flags = SA_RESTART;
  sa_usr2.sa_handler = sig_handle3;
  sigaction(SIGUSR1, &sa_usr1, NULL);
  sigaction(SIGUSR2, &sa_usr2, NULL);
  //printf("check 2\n");
  int *job_que = malloc(sizeof(int) * num_job);
  int job_que_index = 0;
  int job_que_now = -1;
  int prev = 0 , now = 0 , jobcount = 0;
  //printf("check 3\n");
  while(done != num_job){
    for(int i = 0 ; i < num_job ; i++){
      if(now == job_list[i].ready_time){
        jobcount++;
        job_pin[i] = fork();
        if(job_pin[i] == 0){   
          //printf("check 4\n");
          sched_setaffinity(0, sizeof(cpu_set_t), &my_set); 
          sa_usr2.sa_handler = sig_handle2;
          sigaction(SIGUSR2, &sa_usr2, NULL);
          kill(getppid() , SIGUSR2);
          pause();
          //printf("check 5\n");
          while(1);
          exit(0);
        }
        else if(job_pin[i] == -1){
          perror("fork error!");
          exit(-1);
        }
        else{
          //printf("check 6, pid:%d\n" , job_pin[i]);
          if(sign == 0){
            pause();
          }
          else{
            sign = 0;
          }
          //printf("check 7\n");
          job_que[job_que_index] = job_pin[i];
          job_que_index++;
          //printf("check 8\n");
        }
      }
      else if(job_list[i].already_exe_time == job_list[i].exe_time && job_que[i] != -1){
       // printf("check 9, i:%d , already_exe_time:%d , pid:%d\n" , i , job_list[i].already_exe_time , job_pin[i]);
        kill(job_pin[i] , SIGKILL);
        wait(NULL);
        jobcount--;
        job_que[i] = -1;
        done++;
        job_list[i].end_time = now;
       // printf("check 10 , now:%d , done:%d\n" , now , done);
        if(done == num_job){
          //printf("inter!!!\n");
          goto jump;
          //break;
        }
      }
    }
    //printf("check 11\n");
    if(job_que_index != 0 && jobcount != 0){
      if(job_que_now == -1){
        job_que_now = (job_que_now + 1) % job_que_index;
        if(job_list[job_que_now].start_time == -1){
          job_list[job_que_now].start_time = now;
        }
        //printf("check 12\n");
        struct sched_param param;
        param.sched_priority =  sched_get_priority_max(SCHED_RR);
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        //printf("check 13\n");
        kill(job_que[job_que_now] , SIGUSR1);
        prev = now;
      }
      else if(job_que_now != -1 && job_que[job_que_now] == -1){
        while(job_que[job_que_now] == -1){
          job_que_now = (job_que_now + 1)% job_que_index;
        }
        //printf("check 14\n");
        if(job_list[job_que_now].start_time == -1){
          job_list[job_que_now].start_time = now;
        }
        struct sched_param param;
        param.sched_priority =  sched_get_priority_max(SCHED_RR);
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        //printf("check 15\n");
        kill(job_que[job_que_now] , SIGUSR1);
        prev = now;
        //printf("check 16\n");
      }
      else if(job_que_now != -1 && job_que[job_que_now] != -1 && (now-prev)%500 == 0){
        //printf("check 17\n");
        struct sched_param param;
        param.sched_priority =  99;
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        //printf("check 18\n");
        kill(job_que[job_que_now] , SIGUSR2);
        if(job_que[(job_que_now+1)%job_que_index] == -1){
          job_que_now = (job_que_now + 1)%job_que_index;
          while(job_que[job_que_now] == -1){
            job_que_now = (job_que_now + 1)% job_que_index;
          }
        }
        else{
          job_que_now = (job_que_now + 1) % job_que_index;  
        }
        if(job_list[job_que_now].start_time == -1){
          job_list[job_que_now].start_time = now;
        }
        //printf("check 19, job que:%d\n , index:%d\n" , job_que[job_que_now] , job_que_now);
        param.sched_priority =  sched_get_priority_max(SCHED_RR);
        if (sched_setscheduler(job_que[job_que_now], SCHED_RR, &param) != 0) {
          perror("sched_setscheduler");
          exit(EXIT_FAILURE);  
        }
        kill(job_que[job_que_now] , SIGUSR1);
        prev = now;
        //printf("check 20\n");
      }
    }
    

    time_unit();
    //printf("check 21\n");
    if(job_que_now != -1){
      job_list[job_que_now].already_exe_time++;  
      //printf("already:%d , index:%d\n", job_list[job_que_now].already_exe_time , job_que_now);
    }
    now++;
    printf("now:%d\n", now);
    jump:
      continue;
  }
  //printf("check 22\n");
  for(int i = 0 ; i < num_job ; i++){
    printf("%s %d %d\n", job_list[i].job_name , job_list[i].start_time , job_list[i].end_time);
  }



  return 0;
}
