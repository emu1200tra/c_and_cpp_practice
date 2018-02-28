#include <stdio.h>
#include <stdlib.h>

int counter = 0;

int find(int array[] , int n , int k){
    if(n < 0){
        return 0;
    }
    if(k == 0){
        counter++;
        return 1;
    }
    if(k < 0){
        return 0;
    }

    int tmp_array[15] = {0};
    int tmp_n = 0;
    int tmp_k = 0;
    for(int i = 0 ; i < n ; i++){
        for(int a = 0 , tmp_a = 0 ; a < n-1 ; a++ , tmp_a++){

            if(a == i){
                tmp_a++;
            }
            tmp_array[a] = array[tmp_a];
        }
        tmp_k = k - array[i];
        tmp_n = n - 1;
        int result = find(tmp_array , tmp_n , tmp_k);
        //printf("tmpk: %d , tmpn: %d , counter: %d\n" , tmp_k , tmp_n , counter);
        if(result){
           break;
       }

    }
    return 0;
}


int main()
{
    int n = 0 , array[15] = {0} , k = 0;
    scanf("%d" , &n);
    for(int a = 0 ; a < n ; a++){
        scanf("%d" , &array[a]);
    }
    while(scanf("%d" , &k) != EOF){
        int result = find(array , n , k);
        if(counter > 0){
            counter--;
        }
        printf("%d\n" , counter);
        counter = 0;
    }
    return 0;
}
