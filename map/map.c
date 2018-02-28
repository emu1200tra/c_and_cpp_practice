#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debug = 0;

void init(Map *map){
    if (debug) {
        printf("init start\n");
        printf("first loop starts\n");
    }
    for(int i = 0 ; i < 1024 ; i++){
        map->key[i] = NULL;
        if (debug) {
            printf("second loop starts\n");
        }
        for(int a = 0 ; a < 127 ; a++){
            map->value[a] = NULL;
        }
        if (debug) {
            printf("second loop ends\n");
        }
    }
    if (debug) {
        printf("first loop ends\n");
    }
    map->num = 0;
    if (debug) {
        printf("init end\n");
    }
}

int counter = 0;

int map(Map *map, const int key, const char *value){
    for(int a = 0 ; a < 1024 ; a++){
        if(map->key[a] == key){
            strcpy(&map->value[0][counter] , value);

            return 0;
        }
    }
    map->key[counter] = key;
    strcpy(&map->value[0][counter] , value);
    map->num++;
    counter ++;
    return 1;
}
int numPairs(Map *map){
    int num = 0 , Nulltimes = 0;
    for(int a = 0 ; a < 1024 ; a++){
        if(map->key[a] != NULL){
            num++;

        }
        else{
            Nulltimes++;
        }
        if(Nulltimes > 5){
            break;
        }
    }
    return num;
}
void print(Map *map){
    Map result;
    init(&result);
    int times = 0;
    for(int a = 0 ; a < 1024 ; a++){
        if(map->key[a] != NULL){
            result.key[times] = map->key[a];
            strcpy(&result.value[0][times] , map->value[a]);
            times++;
        }
    }


    for(int a = 0 ; a < times ; a++){
        for(int b = 0 ; b < times ; b++){
            if(result.key[b] > result.key[b+1]){
                int trans = result.key[b];
                result.key[b] = result.key[b+1];
                result.key[b+1] = trans;
                char transtring[127];
                strcpy(transtring , &result.value[0][b]);
                strcpy(&result.value[0][b] , &result.value[0][b+1]);
                strcpy(&result.value[0][b+1] , transtring);
            }
        }
    }
    printf("----- map begin -----\n");
    for(int a = 0 ; a < times ; a++){
        printf("%d %s" , result.key[a] , result.value[0][a]);
    }
    printf("----- end       -----\n");



}
const char *getValue(Map *map, const int key){
    return "";
}
int unmap(Map *map, int key){
    return 0;
}
int reverseMap(Map *map, const char *value, int keys[]){
    return 0;
}
