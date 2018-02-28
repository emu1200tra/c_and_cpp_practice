#include "subset.h"
#include <stdio.h>
#include <stdlib.h>

//°®ªL¦Ñ¤ì
//get the fuck up


int subset(int numbers[], int n, int K, int S){
        if(S > n){
            return 0;
        }

        if(S == 0){
            return 0;
        }
        if(S == 1){
            int a = 0;
            for(a = 0 ; a < n ; a++){
              //  printf("a: %d\n" , a);
                if(numbers[a] == K){
                    return 1;
                }
            }
            return 0;
        }
        if(S == 2){
            int a = 0 , b = 0;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                 //   printf("a: %d , b: %d\n" , a , b);
                    if(numbers[a] + numbers[b] == K){
                        return 1;
                    }
                }
            }
            return 0;
        }
        else if(S == 3){
            int a , b , c;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                    for(c = b+1 ; c < n ; c++){
                      //  printf("a:%d , b: %d , c: %d\n"  , a , b , c);
                        if(numbers[a] + numbers[b] + numbers[c] == K){
                            return 1;
                        }
                    }
                }
            }
            return 0;
        }
        else if(S == 4){
            int a = 0 , b = 0 , c = 0 , d = 0;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                    for(c = b+1 ; c < n ; c++){
                        for(d = c+1 ; d < n ; d++){
                          //  printf("a: %d , b: %d , c: %d , d: %d\n" , a , b , c , d);
                            if(numbers[a] + numbers[b] + numbers[c] + numbers[d] == K){
                                return 1;
                            }
                        }

                    }
                }
            }
            return 0;
        }
        else if(S == 5){
            int a = 0 , b = 0 , c = 0 , d = 0 , e = 0;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                    for(c = b+1 ; c < n ; c++){
                        for(d = c+1 ; d < n ; d++){
                            for(e = d+1 ; e < n ; e++){
                             //   printf("a: %d , b: %d , c: %d , d: %d , e: %d\n" , a , b , c , d , e);
                                if(numbers[a] + numbers[b] + numbers[c] + numbers[d] +numbers[e]== K){
                                    return 1;
                                }
                            }

                        }

                    }
                }
            }
            return 0;
        }
        else if(S == 6){
            int a = 0 , b = 0 , c = 0 , d = 0 , e = 0 , f = 0;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                    for(c = b+1 ; c < n ; c++){
                        for(d = c+1 ; d < n ; d++){
                            for(e = d+1 ; e < n ; e++){
                                for(f = e+1 ; f < n ; f++){
                                   // printf("a: %d , b: %d , c: %d , d: %d , e: %d , f: %d\n" , a , b , c , d , e , f);
                                    if(numbers[a] + numbers[b] + numbers[c] + numbers[d] +numbers[e] + numbers[f]== K){
                                        return 1;
                                    }
                                }

                            }

                        }

                    }
                }
            }
            return 0;
        }
        else if(S == 7){
            int a = 0 , b = 0 , c = 0 , d = 0 , e = 0 , f = 0 , g = 0;
            for(a = 0 ; a < n ; a++){
                for(b = a+1 ; b < n ; b++){
                    for(c = b+1 ; c < n ; c++){
                        for(d = c+1 ; d < n ; d++){
                            for(e = d+1 ; e < n ; e++){
                                for(f = e+1 ; f < n ; f++){
                                    for(g = 0 ; g < n ; g++){
                                        //printf("a: %d , b: %d , c: %d , d: %d , e: %d , f: %d , g: %d\n" , a , b , c , d , e , f , g);
                                        if(numbers[a] + numbers[b] + numbers[c] + numbers[d] +numbers[e] + numbers[f] + numbers[g] == K){
                                            return 1;
                                        }
                                    }

                                }

                            }

                        }

                    }
                }
            }
            return 0;
        }
        else{
            return 1;
        }

}


