#include <stdio.h>
#include <stdlib.h>


int rec(int sum , int a , int b , int c , int A , int B , int C , int contb){

    //printf("sum: %d , a: %d , b: %d , c: %d , A: %d , B: %d , C: %d\n" , sum , a , b , c , A , B , C);

    if(A > sum && B > sum && C > sum){
        return 0;
    }
    if((sum % A == 0 || sum % B == 0 || sum % C == 0) && (sum / A <= a || sum / B <= b || sum / C <= c)){
        return 1;
    }
    int sign = 0;
    int ide = sum - b * B - c * C;
    if((ide) % A == 0 && ide >= 0 && b >= 0 && ide / A < a){
        return 1;
    }
    else{
        if(c - 1 < 0){
            return 0;
        }
        if(b >= 0){
            sign = rec(sum , a , b-1 , c , A , B , C , contb);
        }
        else{
            b = contb;
            sign = rec(sum , a , b , c-1 , A , B , C , contb);
        }

    }
    return sign;



}



int main()
{
    int times = 0 , sum = 0 , a = 0 , b = 0 , c = 0 , A = 0 , B = 0 , C = 0;
    scanf("%d" , &times);
    int sign = 0;

    for(int i = 0 ; i < times ; i++){
        scanf("%d%d%d%d%d%d%d" , &sum , &a , &b , &c , &A , &B , &C);
        int maxC = sum / C;
        maxC = maxC * C;
        if(maxC > c){
            maxC = c;
        }
        int maxB = sum / B;
        maxB = maxB * B;
        if(maxB > b){
            maxB = b;
        }
        int contb = maxB;
        sign = rec(sum , a , maxB , maxC , A , B , C , contb);
        if(sign == 1){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }

    return 0;
}
















