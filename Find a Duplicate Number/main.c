#include <stdio.h>
#include <stdlib.h>

long long findsame(long long array[] , long long arraysize);


int main()
{
    long long N = 0;
    long long array[100000];
    int i = 0;
    scanf("%lld" , &N);
    for(; i < N ; i++){
        scanf("%lld" , &array[i]);
    }
    long long result = findsame(array , N);
    printf("%lld\n" , result);
    return 0;
}

long long findsame(long long array[] , long long arraysize){
    long long i = 0;
    long long a = 0;
    long long b = 0;
    long long result = 0;
    for(a ; a < arraysize ; a++){
        for(b = arraysize - 1 ; b > a ; b--){
            if(array[a] == array[b]){
                result = array[a];
            }
        }
    }
    return result;
}
