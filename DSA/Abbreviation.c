#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(char string_sequence[127]){
    if(strcmp(string_sequence , "of") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "and") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "the") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "at") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "of.") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "and.") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "the.") == 0){
        return -1;
    }
    else if(strcmp(string_sequence , "at.") == 0){
        return -1;
    }
    else{
        return 1;
    }
}

int check(char string_squence[127]){
    int i = 0;
    while(string_squence[i] != '\0'){
        if(string_squence[i] == '.'){
            return 1;
        }
        i++;
    }
    return 0;
}


int main(){
    char sequences[127];
    char result[127];
    int counter = 0;
    int sign = 0;
    while(scanf("%s" , sequences) != EOF){
        if(cmp(sequences) == 1){
            result[counter] = sequences[0] - 32;
            counter++;
        }
        if(check(sequences) == 1){
            result[counter] = '\0';
            if(sign == 0){
                printf("%s" , result);
                sign++;
            }
            else{
                printf("\n%s" , result);
            }
            counter = 0;
        }
    }
    //有無可能at之類的在最後?
    return 0;
}
