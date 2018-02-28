#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long Set;
void init(Set *set){
    *set = 0;
}

void add(Set *set, int i){
    *set = *set | ((unsigned long long)1 << i);
}
void has(Set set, int i){
    if(set & (unsigned long long)1 << i){
        printf("set has %d\n" , i);
    }
    else{
        printf("set does not have %d\n" , i);
    }
}
Set setUnion(Set a, Set b){
    Set result = 0;
    result = a | b;
    return result;
}
Set setIntersect(Set a, Set b){
    Set result = 0;
    result = a & b;
    return result;
}
Set setDifference(Set a, Set b){
    Set result = 0;
    result = a ^ b;
    return result;
}
