#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int i = 0;
    int counter = 0;
    while(scanf("%llu" , &i) != EOF){
        counter = 0;
        for(int a = 0 ; a < 64 ; a++){
            if(i & ((unsigned long long) 1 << a)){
                counter++;
                //printf("%d\n" , a);
            }

        }
        printf("%d\n" , counter);
    }
    return 0;
}
