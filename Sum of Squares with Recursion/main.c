#include <stdio.h>
#include <stdlib.h>

int rec(int a){

    if(a == 1){
        return 1;
    }
    return a * a + rec(a-1);

}



int main()
{
    int input = 0;
    scanf("%d" , &input);
    printf("%d" , rec(input));


    return 0;
}
