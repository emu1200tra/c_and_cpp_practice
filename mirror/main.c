#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W = 0 , D = 0;
    scanf("%d%d" , &W , &D);
    int room[100][100];
    int a , b ;
    for(a = 0 ; a < W ; a++){
        for(b = 0 ; b < D ; b++){
            scanf("%d" , &room[a][b]);
            printf("%d  " , room[a][b]);
        }
    }
    return 0;
}
