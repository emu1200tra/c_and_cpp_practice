#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d" , &n);
    int array[1000] = {0};
    int a = 0;
    for(; a < n ; a++){
        scanf("%d" , &array[a]);
    }
    for(a = n - 1 ; a > 0 ; a--){
        printf("%d " , array[a]);
    }
    printf("%d" , array[0]);
    return 0;
}
