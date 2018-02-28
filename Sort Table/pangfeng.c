#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dim_n;
    char name[31];
    int score[];
}ExamTable;

void init(ExamTable *self, int n){
    *self.score[n] = {0};
}
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);
