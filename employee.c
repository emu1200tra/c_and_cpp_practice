#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

/*
struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
};*/


void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.

    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}

void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id ){
    for(int i = 0 ; i < n ; i++){
        if(set[i].id == id){
            return set[i];
            break;
        }
    }
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i = 0 ; i < n ; i++){
        if(strcmp(set[i].first_name , first_name) == 0 && strcmp(set[i].last_name , last_name) == 0){
            return set[i];
            break;
        }
    }
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    if(employee->id == employee->boss_id){
        return employee;
    }
    else{
        return find_root_boss(set , n , set[employee->boss_id]);
    }
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){






}
