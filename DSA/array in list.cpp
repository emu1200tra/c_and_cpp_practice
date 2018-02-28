#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct array_in_linked_list{
    int size_of_array;
    int *array_of_linkedlist;
    array_in_linked_list *address;
};


int main(){
    array_in_linked_list test;
    test.size_of_array = 5;
    int i = 0 , j = 0;
    for(i = 0 ; i < 5 ; i++)
    {
        test.array_of_linkedlist = &i;
        test.array_of_linkedlist++;

    }
    array_in_linked_list test_2;
    test.size_of_array = 5;

    for(j = 5 ; j < 10 ; j++)
    {
        test_2.array_of_linkedlist = &j;
        test_2.array_of_linkedlist++;

    }
    return 0;
}
