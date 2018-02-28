#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

typedef struct{
    int start;
    int length;
    int ending;
    struct record_node *next;
}record_node;


typedef struct{
    int length;
    record_node *nodes;
}Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);
#endif
