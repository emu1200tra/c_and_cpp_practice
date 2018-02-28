#include <stdio.h>
#include <stdlib.h>


void printBlock(unsigned long long int *block){
    int counter = 0;
    for(int a = 0 ; a < 64 ; a++){
        if(counter % 8 == 0 && counter != 0){
            printf("\n");
        }
        if(*block & ((unsigned long long)1 << a)){
            printf("1");
        }
        else{
            printf("0");
        }
        counter++;
    }


}
void initialize(unsigned long long int *block, int row, int column, int size){

    int start = (row) * 8 + column;

    unsigned long long int sum = 0 ;
    int counter = 0;
    for(int a = start ; a < 64 ; a++){

        if(counter < size){

            sum = sum | ((unsigned long long)1 << a);

            counter++;
        }
        else{

            counter = 0;
            start = start + 8;

            a = start - 1;

        }

    }
    *block = sum;





}
int moveLeft(unsigned long long int *block){

    int sign = 1;


    /*for(int a = 0 ; a < 64 ; a++){
        if(*block & ((unsigned long long)1 << a)){
            array[i][j] = 1;
        }

        if(j == 7){
            i++;
            j = 0;

        }
        else{
            j++;
        }
    }

    for(int a = 0 ; a < 8 ; a++){
        if(array[a][0] == 1){
            sign = 0;
            break;
        }
        else{
            sign = 1;
        }
    }
    */

    for(int a = 0 ; a <= 56 ; a = a+8){
        if(*block & (unsigned long long)1 << a){

            sign = 0;
            break;
        }
    }



    if(sign == 0){
        return sign;
    }
    else{
        unsigned long long int result = *block;

        result = result >> 1;
        *block = result;

        return 1;
    }

}
int moveRight(unsigned long long int *block){
    int sign = 1;


    /*for(int a = 0 ; a < 64 ; a++){
        if(*block & ((unsigned long long)1 << a)){
            array[i][j] = 1;
        }
        if(j == 7){
            i++;
            j = 0;
        }
        else{
            j++;
        }
    }
    for(int a = 0 ; a < 8 ; a++){
        if(array[a][7] == 1){
            sign = 0;
            break;
        }
        else{
            sign = 1;
        }
    }
    */
     for(int a = 7 ; a <= 63 ; a = a+8){
        if(*block & (unsigned long long)1 << a){

            sign = 0;
            break;
        }
    }
    if(sign == 0){
        return sign;
    }
    else{
        unsigned long long int result = *block;
        result = result << 1;
        *block = result;
        return 1;
    }

}
int moveUp(unsigned long long int *block){
    int sign = 1;

    /*
    for(int a = 0 ; a < 64 ; a++){
        if(*block & ((unsigned long long)1 << a)){
            array[i][j] = 1;
        }
        if(j == 7){
            i++;
            j = 0;
        }
        else{
            j++;
        }
    }
    for(int a = 0 ; a < 8 ; a++){
        if(array[0][a] == 1){
            sign = 0;
            break;
        }
        else{
            sign = 1;
        }
    }
    */
     for(int a = 0 ; a <= 7 ; a++){
        if(*block & (unsigned long long)1 << a){
            sign = 0;
            break;
        }
    }
    if(sign == 0){
        return sign;
    }
    else{
        unsigned long long int result = *block;
        result = result >> 8;
        *block = result;
        return 1;
    }


}
int moveDown(unsigned long long int *block){
    int sign = 1;


    /*for(int a = 0 ; a < 64 ; a++){
        if(*block & ((unsigned long long)1 << a)){
            array[i][j] = 1;
        }
        if(j == 7){
            i++;
            j = 0;
        }
        else{
            j++;
        }
    }
    for(int a = 0 ; a < 8 ; a++){
        if(array[7][a] == 1){
            sign = 0;
            break;
        }
        else{
            sign = 1;
        }
    }*/
     for(int a = 56 ; a <= 63 ; a++){
        if(*block & (unsigned long long)1 << a){
            sign = 0;
            break;
        }
    }
    if(sign == 0){
        return sign;
    }
    else{
        unsigned long long int result = *block;
        result = result << 8;
        *block = result;
        return 1;
    }
}
