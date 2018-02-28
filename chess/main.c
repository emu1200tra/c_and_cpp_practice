#include <stdio.h>
#include <stdlib.h>



typedef struct{
    long long  x , y;
}Point;

long long manhdis(Point p , Point q);
long long findmin(Point p , Point q[] , long long i);



int main()
{
    Point arrayp[50000];
    Point arrayq[50000];
    long long N = 0;
    scanf("%lld" , &N);
    long long i = 0;
    long long x =0 , y = 0 , p = 0 , q = 0;
    long long result[50000];
    for(; i < 2*N ; i++){
        if(i % 2){
            scanf("%lld%lld" , &arrayq[q].x , &arrayq[q].y);
            Point trans = arrayq[q];
            result[i] = findmin(trans , arrayp , p);
            q++;

        }
        else{
            scanf("%lld%lld" , &arrayp[p].x ,&arrayp[p].y);
            if(i != 0){
                result[i] = findmin(arrayp[p] , arrayq , q);
            }
            p++;

        }
    }
    long long count;
    for(count = 1 ; count < N * 2  ; count++){
        printf("%lld\n" ,result[count]);
    }
    return 0;
}


//counting Manhattan distance
long long manhdis(Point p , Point q){
   return abs(p.x - q.x) + abs(p.y - q.y);
}

long long findmin(Point p , Point q[] , long long i){
    long long min = 65600;
    long long a = i - 1;
    for(a ; a >= 0 ; a--){
        long long distance = manhdis(p , q[a]);
        if(min > distance){
            min = distance;
        }
    }
    return min;

}
