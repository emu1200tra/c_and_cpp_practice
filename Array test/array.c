#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*
typedef struct{
    int start;
    int end;
    int value[2048];
}ARRAY;
*/

void init(ARRAY *a,  int left, int right){
    (*a).start = left;
    (*a).end = right;
    for(int i = 0 ; i < 2048 ; i++){
        (*a).index[i] = right + 1;
        (*a).value[i] = -2147483647;


    }
}


int set(ARRAY *a, int index, int value){
    if(index > (*a).end || index < (*a).start){
        return -2147483648;
    }
    else{
        int i = index - (*a).start;
        (*a).index[i] = index;

        (*a).value[i] = value;

        return 1;
    }

}


int get(ARRAY *a, int index){

    if(index > (*a).end || index < (*a).start){
        return -2147483648;
    }
    int times = (*a).end - (*a).start;
    for(int j = 0 ; j <= times ; j++){
        if((*a).index[j] == index){
            return (*a).value[j];
        }
    }
    return -2147483647;







}


void print(ARRAY *a){
    int times = (*a).end - (*a).start;
    for(int i = 0 ; i <= times ; i++ ){
        if((*a).index[i] == 0 && (*a).value[i] == 0){
            printf("%d\n" , (*a).value[i]);
        }
        else if((*a).index[i] == (*a).end+1){
            printf("No value\n");
        }
        else{
            printf("%d\n" , (*a).value[i]);
        }

    }

}
void sort(ARRAY *a){
    int times = (*a).end - (*a).start;
    for(int i = 0 ; i < times ; ++i){
        for(int j = 0 ; j < times - i ; ++j){
            if((*a).value[j] > (*a).value[j+1]){
                //printf("1:%d 2:%d\n" , (*a).value[j] , (*a).value[j+1]);
                int trans = (*a).index[j];
                (*a).index[j] = (*a).index[j+1];
                (*a).index[j+1] = trans;
                trans = (*a).value[j];
                (*a).value[j] = (*a).value[j+1];
                (*a).value[j+1] = trans;

            }
        }

    }

}
