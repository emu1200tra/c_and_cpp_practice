#include <stdio.h>
#include <stdlib.h>

void print(int array[6][6])
{
    int a = 0 , b = 0;
    for(a = 1 ; a < 5 ; a++)
    {
        for(b = 1 ; b < 5 ; b++)
        {
            if(b == 4)
            {
                printf("%d\n" , array[a][b]);
            }
            else
            {
                printf("%d " , array[a][b]);
            }
        }
    }
}


int mach(int array[6][6])
{
    int counter = 0;
    int fin[16] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 ,14 , 15 , 0};
    int i;
    for(i = 0; i<16; i++)if(array[i/4+1][i%4+1]==fin[i])counter++;
    if(counter == 16)
        return 1;
    else
        return 0;
}



int main()
{
    int array[6][6];
    int a = 0 , b = 0;
    int j , k;
    for( j = 0 ; j < 6 ; j++)
    {
        for(k = 0 ; k < 6 ; k++)
        {
            array[j][k]=-1;
        }
    }
    for(a = 1 ; a < 5 ; a++)
    {
        for(b = 1 ; b < 5 ; b++)
        {
            scanf("%d" , &array[a][b]);
        }
    }

    int step[100]  , counter = 1;
    scanf("%d" , &step[0]);
    while(scanf("%d" , &step[counter]))
    {
        if(step[counter] == 0)
        {
            break;
        }
        counter++;
    }
    a = 0 , b = 0 , counter = 0;
    int i = 0 , trans = 0 , sig = 0;
    if(step[counter] != 0)
    {
        while(step[counter] != 0)
        {
            sig=0;
            for(a = 1 ; a < 5 ; a++)
            {
                for(b = 1 ; b < 5 ; b++)
                {
                    if(array[a][b] == step[counter] && sig == 0)
                    {

                        if(array[a-1][b] == 0)
                        {

                            trans = array[a-1][b];
                            array[a-1][b] = step[counter];
                            array[a][b] = trans;
                            sig++;
                        }
                        else if(array[a][b-1] == 0)
                        {

                            trans = array[a][b-1];
                            array[a][b-1] = step[counter];
                            array[a][b] = trans;
                            sig++;
                        }
                        else if(array[a+1][b] == 0)
                        {

                            trans = array[a+1][b];
                            array[a+1][b] = step[counter];
                            array[a][b] = trans;
                            sig++;

                        }
                        else if(array[a][b+1] == 0)
                        {

                            trans = array[a][b+1];
                            array[a][b+1] = step[counter];
                            array[a][b] = trans;
                            sig++;
                        }
                        if(sig)break;
                    }
                    if(sig)break;
                }
            }


            i = mach(array);
            if(i == 1)
            {
                printf("1 2 3 4\n5 6 7 8\n9 10 11 12\n13 14 15 0\n");
                printf("1 %d" , step[counter]);
                return 0;
            }
            counter++;
        }
        print(array);
        printf("0");
    }
    else
    {
        int a = 0 , b = 0;
        for(a = 1 ; a < 5 ; a++)
        {
            for(b = 1 ; b < 5 ; b++)
            {
                if(b == 4)
                {
                    printf("%d\n" , array[a][b]);
                }
                else
                {
                    printf("%d " , array[a][b]);
                }

            }
        }
        printf("0");
        return 0;
    }



    return 0;
}
