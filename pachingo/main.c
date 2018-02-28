#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int left , right;

}node;

void normal(int up , int down){
    int a = 0;
    for(a = up ; a > 1 ; a--){
        if(up % a == 0 && down % a == 0){
            up = up / a;
            down = down / a;
            break;
        }
    }

}


int main()
{
//    int i = 0 , array[120][2] = {0};
//    scanf("%d" , &i);
//    int count = (1 + i) * i / 2;
//    int a = 0 , b = 0;
//    for(a = 0 ; a < count ; a++){
//        scanf("%d%d" , &array[a][0] , &array[a][1]);
//    }
    int N = 0;
    node array[120];
    int i = 0;
    scanf("%d" , &N);
    for(i = 0; i < (1+N)N/2 ; i++){
        scanf("%d %d" , &array[i].left , &array[i].right);
    }



    return 0;
}
