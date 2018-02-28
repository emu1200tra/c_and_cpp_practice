#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char lastname[80];
    char firstname[80];
    char ID[80];
    int salary;
    int age;
}database;

int cmpfield(char condition[]){

    if(strcmp(&condition[0] , "lastname") == 0){
        return 0;
    }
    else if(strcmp(&condition[0] , "firstname") == 0){
        return 1;
    }
    else if(strcmp(&condition[0] , "ID") == 0){
        return 2;
    }
    else if(strcmp(&condition[0] , "salary") == 0){
        return 3;
    }
    else if(strcmp(&condition[0] , "age") == 0){
        return 4;
    }
    else{
        return 5;
    }
}

int cmpope(char operate[]){
    if(strcmp(&operate[0] , "==") == 0){
        return 0;
    }
    else if(strcmp(&operate[0] , "!=") == 0){
        return 1;
    }
    else if(strcmp(&operate[0] , ">") == 0){
        return 2;
    }
    else if(strcmp(&operate[0] , "<") == 0){
        return 3;
    }
    else{
        return 4;
    }
}


int main()
{
    int num = 0;
    scanf("%d" , &num);
    database data[50];
    for(int a = 0 ; a < num ; a++){
        scanf("%s" , &data[a].lastname[0]);
        scanf("%s" , &data[a].firstname[0]);
        scanf("%s" , &data[a].ID[0]);
        scanf("%d" , &data[a].salary);
        scanf("%d" , &data[a].age);
    }
    int times = 0;
    scanf("%d" , &times);
    char select[7];
    scanf("%s" , &select[0]);
    char field[10][20];
    for(int a = 0 ; a < 10 ; a++){
        scanf("%s" , &field[a][0]);
        if(strcmp(&field[a][0] , "where") == 0){
            break;
        }
    }
    char condition[20];
    char operat[3];
    char edi[80];
    scanf("%s" , &condition[0]);
    scanf("%s" , &operat[0]);
    scanf("%s" , &edi[0]);
    int sign1 = cmpfield(condition);
    int sign2 = cmpope(operat);





    return 0;
}
