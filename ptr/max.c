#include <stdlib.h>
#include <stdio.h>


int max(int *iptr[], int n){
    int max = *iptr[0];
    int a = 0;
    for(a = 0 ; a < n ; a++){
        if(max < *iptr[a]){
            max = *iptr[a];
        }
    }
    return max;

}
