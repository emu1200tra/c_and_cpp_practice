#include <stdio.h>
#include <stdlib.h>
int fianl[10000];
void shuffle(int *deck[]){
    int counter = 0;
    while(deck[counter] != NULL){
        counter++;
    }


    int second = counter / 2;
    int first = counter - second;

    int a = 0 , i = 0 , j = first;
    for(a = 0 ; a < counter ; a++){
        if(a % 2 == 0){
            fianl[a] = *deck[i];

            i++;
        }
        else{
            fianl[a] = *deck[j];

            j++;
        }
    }
    a = 0;
    for(a = 0 ; a < counter ; a++){
        deck[a] = &(fianl[a]);
    }
    deck[a] = NULL;


}

void print(int *deck[]){
    int i = 0;
    while(deck[i] != NULL){
        if(deck[i+1] != NULL){
            printf("%d " , *deck[i]);
        }
        else{
            printf("%d" , *deck[i]);
        }
        i++;
    }
}

