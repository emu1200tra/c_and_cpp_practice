#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char final_string[127] , input[127];
    scanf("%s" , final_string);
    while(scanf("%s" , input) != EOF){
        int inputnum  = strlen(input);
        int final_stringnum = strlen(final_string);
        int a = final_stringnum , b = 0 , counter = 0;
        int sign = 0;
        if(final_stringnum > inputnum){
            a = inputnum;
        }
        else if(final_stringnum < inputnum){
            a = final_stringnum;
        }
        int d = final_stringnum-a , i = 1;
        while(d < final_stringnum  ){

            if(final_string[d] == input[b] && b < inputnum){

                d++;
                b++;
                counter++;
                sign = 0;
            }
            else{
                d = final_stringnum-a+i;
                b = 0;
                counter = 0;
                i++;


                /*if(sign == 0){
                    printf("jizz1: %c , %c\n" , final_string[d] , input[b]);
                    b = 0;
                    sign++;
                    counter = 0;
                }
                else{
                    printf("jizz2: %c , %c\n" , final_string[d] , input[b]);
                    d++;
                    b = 0;
                    counter = 0;
                    sign = 0;

                }*/
            }


        }




        for(int c = counter  ; c < inputnum ; c++){
            final_string[final_stringnum] = input[c];
            final_stringnum++;

        }
        final_string[final_stringnum] = '\0';


    }

    printf("%s" , final_string);

    return 0;
}
