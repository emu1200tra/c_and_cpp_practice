

#include <iostream>
#include<stdlib.h>


using namespace std;

struct linked_list{
    int value;
    linked_list *next;
    linked_list *prev;
};
/*
struct linked_list{
    int size;
    int *array;
    //int array[10];
}


*/



int main()
{
    linked_list *first;
    linked_list *second;
    linked_list *third;

    first->value = 0;
    first->next = second;
    first->prev = third;

    second->value = 1;
    second->next = third;
    second->prev = first;

    third->value = 2;
    third->next = first;
    third->prev = second;

    cout<<first->next->next->value<<endl;

    return 0;
}
