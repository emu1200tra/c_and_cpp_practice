#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int num = 0;
    scanf("%d" , &num);
    char string1[100] , string2[100];
    for(int a = 0 ; a < num ; a++){
        scanf("%s" , string1);
        scanf("%s" , string2);
        int len1 = strlen(string1);
        int len2 = strlen(string2);
        int flag1 = 0 , flag2 = 0 , flag3 = 0;
        if(len1 == len2){

            for(int b = 0 ; b < len1 ; b++){
                for(int c = 0 ; c < len1 ; c++){
                    if(string1[b] == string2[c]){
                        flag1++;
                        break;
                    }
                }
            }
            for(int b = 0 ; b < len1 ; b++){
                if(string1[b] == string2[b]){
                    flag2++;
                }
            }
            if((flag1 == len1) && (flag2 == len1-2)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        else if(abs(len1 - len2) == 1){
            if(len1 > len2){
                int a = 0 , b = 0;
                while(a < len1){
                    if(string1[a] == string2[b]){
                        flag3++;
                    }
                    else{
                        b--;
                    }
                    a++;
                    b++;
                }
                if(flag3 == len2){
                    printf("yes\n");
                }
                else{
                    printf("no\n");
                }
            }
            else if(len1 < len2){
                int a = 0 , b = 0;
                while(a < len1){
                    if(string1[a] == string2[b]){
                        flag3++;
                    }
                    else{
                        a--;
                    }
                    a++;
                    b++;
                }
                if(flag3 == len1){
                    printf("yes\n");
                }
                else{
                    printf("no\n");
                }
            }

        }
        else{
            printf("no\n");
        }


    }


    return 0;
}
