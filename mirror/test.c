#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}place;

int main(){
    int room[101][101];
    int indicate[101][101];
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            room[i][j] = -1;
            indicate[i][j] = -1;
        }
    }
    int W , D;
    scanf("%d %d" , &W , &D);
    int counting = 0;
    for(int i = 1 ; i <= W ; i++){
        indicate[D+1][i] = counting;
        counting++;
    }
    for(int i = D ; i > 0 ; i--){
        indicate[i][W+1] = counting;
        counting++;
    }
    for(int i = W ; i > 0 ; i--){
        indicate[0][i] = counting;
        counting++;
    }
    for(int i = 1 ; i < D + 1 ; i++){
        indicate[i][0] = counting;
        counting++;
    }
    /*for(int i = 0 ; i <= D+1 ; i++){
        for(int j = 0 ; j <= W+1 ; j++){
            printf("%d /" , indicate[i][j]);
        }
    }*/
    //printf("\n");
    //printf("yee");
    for(int i = 1 ; i <= D ; i++){
        for(int j = 1 ; j <= W ; j++){
            scanf("%d" , &room[i][j]);
            //printf("%d /" , room[i][j]);
        }
    }
    place start;
    start.x = D;
    start.y = 1;
    for(int counter = 0 ; counter < W ; counter++){
        place clone = start;
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        int i = 0 , j = 0 , sign = 0;
        while(room[clone.x][clone.y] != -1){
            if(room[clone.x][clone.y] == 1){
                //printf("yee\n");
                if(sign == 0){
                    sign = 1;
                }
                else if(sign == 1){
                    sign = 0;
                }
            }
            if(sign == 0){
                clone.x--;
            }
            else if(sign == 1){
                clone.y++;
            }
        }
        int number = indicate[clone.x][clone.y];
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        printf("%d\n" , number);
        start.y++;
    }

    start.x = D;
    start.y = W;
    for(int counter = 0 ; counter < D ; counter++){
        place clone = start;
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        int i = 0 , j = 0 , sign = 0;
        while(room[clone.x][clone.y] != -1){
            if(room[clone.x][clone.y] == 1){
                //printf("yee\n");
                if(sign == 0){
                    sign = 1;
                }
                else if(sign == 1){
                    sign = 0;
                }
            }
            if(sign == 1){
                clone.x++;
            }
            else if(sign == 0){
                clone.y--;
            }
        }
        int number = indicate[clone.x][clone.y];
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        printf("%d\n" , number);
        start.x--;
    }

    start.x = 1;
    start.y = W;
    for(int counter = 0 ; counter < W ; counter++){
        place clone = start;
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        int i = 0 , j = 0 , sign = 0;
        while(room[clone.x][clone.y] != -1){
            if(room[clone.x][clone.y] == 1){
                //printf("yee\n");
                if(sign == 0){
                    sign = 1;
                }
                else if(sign == 1){
                    sign = 0;
                }
            }
            if(sign == 0){
                clone.x++;
            }
            else if(sign == 1){
                clone.y--;
            }
        }
        int number = indicate[clone.x][clone.y];
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        printf("%d\n" , number);
        start.y--;
    }

    start.x = 1;
    start.y = 1;
    for(int counter = 0 ; counter < D ; counter++){
        place clone = start;
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        int i = 0 , j = 0 , sign = 0;
        while(room[clone.x][clone.y] != -1){
            if(room[clone.x][clone.y] == 1){
                //printf("yee\n");
                if(sign == 0){
                    sign = 1;
                }
                else if(sign == 1){
                    sign = 0;
                }
            }
            if(sign == 1){
                clone.x--;
            }
            else if(sign == 0){
                clone.y++;
            }
        }
        int number = indicate[clone.x][clone.y];
        //printf("clone.x : %d\n" , clone.x);
        //printf("clone.y : %d\n" , clone.y);
        if(counter == D - 1){
            printf("%d" , number);
        }
        else{
            printf("%d\n" , number);
        }
        start.x++;
    }

    return 0;
}
