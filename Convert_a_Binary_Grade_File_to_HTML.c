#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;


int main(){
    char inputname[128] , outputname[128];
    scanf("%s %s" , inputname , outputname);
    //printf("%s %s\n" , inputname , outputname);
    FILE* fop = fopen(inputname , "rb");
    FILE* fout = fopen(outputname , "a+");
    Student info;
    //fprintf(fout , "<table border="1">\n<tbody>\n");
    char buff[256];
    strcpy(buff , "<table border=");
    buff[14]='"';
    buff[15]='1';
    buff[16]='"';
    buff[17]='\0';
    strcat(buff , ">\n<tbody>\n");
    //printf("title:%s" , buff);
    fprintf(fout , "%s" , buff);
    fflush(fout);
    int size_n = 0;
    while((size_n = fread(&info , sizeof(info) , 1 , fop)) != 0){
        //printf("into loop\n");
        fprintf(fout , "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n" ,
                info.name , info.id , info.phone , info.grade[0] , info.grade[1] , info.grade[2] , info.grade[3] , info.birth_year , info.birth_month , info.birth_day);
        fflush(fout);
    }
    fprintf(fout , "</tbody>\n</table>\n");
    fflush(fout);

    fclose(fop);
    fclose(fout);

    return 0;
}
