#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char astring[100];
    scanf("%s" , &astring[0]);
    int length = strlen(astring);
    int digits = 0 , letters = 0 , vowels = 0 , consonants = 0;
    for(int a = 0 ; a < length ; a++){
        if((astring[a]>= 65 && astring[a]<=90) || (astring[a] >=97 && astring[a]<=122) ){
            letters++;
            if(astring[a] == 'a' || astring[a] == 'e' || astring[a] == 'i' || astring[a] == 'o' ||astring[a] == 'u' ||astring[a] == 'A' ||astring[a] =='E'||astring[a] =='I'||astring[a] =='O'||astring[a] =='U'){
                vowels++;
            }
            else{
                consonants++;
            }
        }
        if(astring[a]>=48 && astring[a]<=57){
            digits++;
        }
    }
    printf("%d %d %d %d" , digits , letters , vowels , consonants);
    return 0;
}
