#include <stdio.h>
#include <stdlib.h>
#include "eval.h"


int printarray(int array[] , int i)
{
    for(int a = 0 ; a <= i ; a++)
    {


        printf("%d " , array[a]);
    }
    printf("\n");

}



int eval(int exp[])
{
    int num = exp[0];
    int a = 0 , counter1 = 0 , result = 0 , counter2 = 0;
    for(a = 1 ; a <= num ; a++)
    {

        if((counter1 + 1) % 2 == 1 && (exp[a+1] > 4 || exp[a+1] < 1) && (counter1 + 1 <= num) && (a + 1 <=num))
        {

            return -2147483646;
        }
        if((counter1 + 1) % 2 == 1 && (exp[a+1] == 3 || exp[a+1] == 4))
        {
            if(exp[a+1] == 3)
            {
                exp[a+2] = exp[a] * exp[a+2];
                exp[a] = 0;
                if(exp[a-1] == 1 && a!= 2)
                {
                    exp[a+1] = 1;
                }
                else if(exp[a-1] == 2 && a!=2)
                {
                    exp[a+1] = 2;
                }
                else
                {
                    exp[a+1] = 1;
                }

                //printf("%d %d %d %d\n" , array[counter1] , a , exp[a] , exp[a+2]);
            }
            else if(exp[a+1] == 4)
            {
                if(exp[a+2] != 0)
                {
                    exp[a+2] = exp[a] / exp[a+2];
                    exp[a] = 0;
                    if(exp[a-1] == 1 && a!= 2)
                    {
                        exp[a+1] = 1;
                    }
                    else if(exp[a-1] == 2 && a!=2)
                    {
                        exp[a+1] = 2;
                    }
                    else
                    {
                        exp[a+1] = 1;
                    }

                    //printf("%d %d %d %d\n" , array[counter1] , a , exp[a] , exp[a+2]);
                }
                else
                {
                    return -2147483647;
                }
            }

        }
        counter1++;

    }
    a = 0;
    result = exp[1];
    for(a = 1 ; a < counter1 ; a++)
    {

        if(counter2 % 2 == 1)
        {
            if(exp[a] == 1)
            {
                result = result + exp[a + 1];

            }
            else if(exp[a] == 2)
            {
                result = result - exp[a + 1];

            }
        }
        counter2++;

    }

    return result;


}




