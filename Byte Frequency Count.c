#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter[65536] = {0};

int main(){
    char file_name[256];
    scanf("%s" , file_name);
    FILE* fop = fopen(file_name , "rb");
    int size = 0;
    short int buff;
    fread(&size , 4 , 65536 , fop);
    printf("size:%d\n" , size);
    for(int i = 0 ; i < size ; i++){
        fread(&buff , 2 , 65536 , fop);
        printf("into buffer:%d\n" , buffer);
        counter[buff]++;
    }
    int max_num = 0 , max_times = 0;
    for(int i = 0 ; i < 65536 ; i++){
        if(counter[i] >= max_times){
            max_times = counter[i];
            max_num = i;
        }
    }
    printf("%d\n%d" , max_num , max_times);

    return 0;
}
