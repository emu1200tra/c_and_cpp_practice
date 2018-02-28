typedef struct{
    int dim_n;
    char name[31];
    int score[256];
}ExamTable;

void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);
