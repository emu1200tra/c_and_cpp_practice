#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/*
typedef struct{
    int start;
    int length;
    int ending;
    record_node *next;
}record_node;
*/

/*typedef struct{
    int length;
    record_node nodes;
}Memory;*/

void initMemory(Memory *memory, int length){
    memory = (Memory*)malloc(sizeof(Memory));
    memory->length = length;
    //printf("init:%d\n" , memory->length);
    //memory->nodes = NULL;
}

void printMemory(Memory *memory){
    //printf("%d\n" , memory->length);
    printf("==========\n");
    if(memory->nodes == NULL){
        printf("start 0, length %d\n" , memory->length);
    }
    else{
        printf("start 0, length %d\n" , memory->nodes->start);
    }
    record_node* tmp = memory->nodes;
    //record_node* tmp2 = tmp->next;
    while(tmp->next != NULL){
        record_node* tmp2 = tmp->next;
        printf("start %d, length %d\n" , tmp->ending , tmp2->start - tmp->ending);
        tmp = tmp2;
    }
    printf("start %d, length %d\n" , tmp->ending , memory->length - tmp->ending);
}

void allocateMemory(Memory *memory, int start, int length){
    record_node *node = (record_node*)malloc(sizeof(record_node));
    node->start = start;
    node->ending = start + length;
    node->length = length;
    node->next = NULL;
    //printf("chekc: %d %d %d\n" , node->start , node->length , node->ending);
    if(memory->nodes == NULL){
        memory->nodes = node;
    }
    else{
        record_node *tmp = memory->nodes;
        //printf("check tmp:%d %d %d\n" , tmp->start , tmp->ending , tmp->length);
        //record_node *tmp2 = tmp->next;
        while(tmp->next != NULL){
            record_node *tmp2 = tmp->next;
            //printf("check tmp2:%d %d %d\n" , tmp2->start , tmp2->ending , tmp2->length);
            if((tmp->ending <= node->start) && (tmp2->start >= node->ending)){
                node->next = tmp->next;
                tmp->next = node;
                //printf("check here\n");
                break;
            }
            tmp = tmp2;
            //tmp2 = tmp->next;
        }
        //printf("break out\n");
        tmp->next = node;
//        printf("tmp:%d %d %d\n" , tmp->next->start , tmp->next->length , tmp->next->ending);
    }
}
void freeMemory(Memory *memory, int start, int length){
    /*skip*/
}



