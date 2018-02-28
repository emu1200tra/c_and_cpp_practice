#include <stdio.h>
#include <stdlib.h>

int main(){
    long long int length = 0 , width = 0;
    scanf("%lld" , &length);
    scanf("%lld" , &width);
    char one , zero , trash;
    scanf("%c" , &trash);
    scanf("%c" , &one);
    scanf("%c" , &trash);
    scanf("%c" , &zero);
    //printf("zero:%c" , zero);
    unsigned long int first , second;
    scanf("%ul" , &first);
    scanf("%ul" , &second);
    int sum = length * width;
    for(int i = sum - 1 ; i >= 0 ; i--){
        if((i - sum + 32) >= 0){
            if(first & ((unsigned long long int)1 << (i - sum + 32))){
                printf("%c" , one);
            }
            else{
                printf("%c" , zero);
            }
            if(i % length == 0){
                printf("\n");
            }
        }
        else{
            if(second & ((unsigned long long int)1 << (i + 64 - sum))){
                printf("%c" , one);
            }
            else{
                printf("%c" , zero);
            }
            if(i % length == 0){
                printf("\n");
            }
        }
    }

    return 0;
}
