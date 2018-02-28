#include <stdio.h>
#include <stdlib.h>

void fill_array(int *ptr[], int n){
    int *init = ptr[0];
    //printf("check\n");
    while(init != ptr[n-1]){
        *init = -1;
        //printf("%d\t" , *init);
        init++;
        if(init == ptr[n-1]){
            //printf("fuck you\n");
        }
    }
    //printf("\ncheck2\n");
    int save[10000];
    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        *ptr[i] = i;
        //printf("i: %d , ptr:%d\n" , i , *ptr[i]);
    }
    init = ptr[0];
    //printf("check3\n");
    while(init != ptr[n-1]){
        if(*init != -1){
            save[counter] = *init;
            //printf("save:%d , init:%d\n" , save[counter] , *init);
            counter++;
        }
        init++;
    }
    save[counter] = *ptr[n-1];
    //printf("save:%d , init:%d\n" , save[counter] , *ptr[n-1]);
    counter = -1;
    int *tmp = ptr[0]++;
    //printf("check4\n");
    while(tmp != ptr[n-1]){
        if(*tmp == -1){
           *tmp = save[counter] + save[counter + 1];
           //printf("tmp: %d\n" , *tmp);
        }
        else{
            counter++;
        }
        tmp++;
    }
};
