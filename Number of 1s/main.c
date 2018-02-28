#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , counter = 0 , num = 0;
    while(scanf("%d" , &i) != EOF){
        counter = 0;
        num = 1;
        if(i & num) {
            counter++;
        }
        for(int a = 1 ; a < 32 ; a++ ){
            if(i & (num <<= 1)) {
                counter++;
            }
        }
        printf("%d\n" , counter);
    }
    return 0;
}
