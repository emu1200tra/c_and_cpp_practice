#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0 , counter = 0 , max = 0;
    int sign = 0;
    while(scanf("%d" , &i) != EOF){
        counter = 0;
        sign = 0;
        max = 0;
        for(int a = 0 ; a < 32 ; a++){
            sign = 0;
            if(i & (1 << a)){
                sign = 1;

            }
            if(sign == 1){
                counter++;

            }
            else{
                if(counter > max){

                    max = counter;

                }
                counter = 0;
            }
        }

        printf("%d\n" , max);

    }
    return 0;
}
