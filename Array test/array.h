
#ifndef _ARRAY_H
#define _ARRAY_H


typedef struct{
    long start;
    long end;
    long index[2048];
    long value[2048];
}ARRAY;


void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);

#endif
