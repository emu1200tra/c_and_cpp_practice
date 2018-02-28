#include <stdio.h>
#include <stdlib.h>
#include "subset.h"




int subset(int numbers[], int n, int K, int S){
    if(K == 0 && S == 0){
        return 1;
    }
    if(S <= 0){
        return 0;
    }
    if(n <= 0){
        return 0;
    }
    if(S > n){
        return 0;
    }



    int result = 0;
    int tmp_n = 0;
    int tmp_K = 0;
    int tmp_S = 0;
    int tmp_numbers[n-1];
    for(int a = 0 ; a < n ; a++){
        for(int b = 0, tmp_a = 0 ; b < n - 1 ; b++, tmp_a++){
            if(b == a){
                tmp_a++;
            }
            tmp_numbers[b] = numbers[tmp_a];
        }

        tmp_n = n - 1;
        tmp_K = K - numbers[a];
        tmp_S = S - 1;
        result = subset(tmp_numbers , tmp_n , tmp_K , tmp_S);

        if(result){
            return 1;
        }
    }
    return 0;
}
