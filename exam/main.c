#include <stdio.h>
#include <stdlib.h>


int event(int array[3][3])
{
    int i, j , sum = 0;
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            sum += array[i][j];
        }
    }
    sum -= array[1][1];
    if(sum < 2 || sum > 3)
    {
        return 0;
    }
    else if(sum == 3)
    {
        return 1;
    }
    else if(sum == 2 && array[1][1] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void print(int array[102][102] , int bian)
{
    int i = 1 , j = 1;
    for(i = 1 ; i < bian + 1 ; i++)
    {
        for(j = 1 ; j < bian + 1 ; j++)
        {
            if(j == bian)
            {
                printf("%d\n" , array[i][j]);
                continue;
            }
            printf("%d " , array[i][j]);
        }
    }
}





int main()
{
    int bian = 0 , step = 0;
    scanf("%d%d" , &bian , &step);
    int array[102][102] = {{0} , {0}};
    int counter[100][100] = {{0} , {0}};
    int livedied[102][102] = {{0} , {0}};
    int a , b;
    for(a = 1 ; a < bian + 1 ; a++)
    {
        for(b = 1 ; b < bian + 1 ; b++)
        {
            scanf("%d" , &array[a][b]);
        }
    }
    int c;
    //step = 0 will WA.
    if(step == 0)
    {
        print(array , bian);
        for(a = bian ; a > 0 ; a--)
        {
            for(b = bian ; b > 0 ; b--)
            {
                if(array[a][b] == 1)
                {
                    printf("%d %d" , a , b);
                    return 0;
                }
            }
        }

    }
    else
    {
        int flag = 0;
        for(a = 0 ; a < bian ; a++)
        {
            for(b = 0 ; b < bian ; b++)
            {
                counter[a][b] = array[a+1][b+1];
            }
        }
        for(c = 0 ; c < step ; c++)
        {
            int trans[3][3];
            if(flag == 0)
            {
                for(a = 1 ; a < bian + 1 ; a++)
                {
                    for(b = 1 ; b < bian + 1 ; b++)
                    {
                        trans[0][0] = array[a - 1][b - 1];
                        trans[0][1] = array[a - 1][b];
                        trans[0][2] = array[a - 1][b + 1];
                        trans[1][0] = array[a][b - 1];
                        trans[1][1] = array[a][b];
                        trans[1][2] = array[a][b + 1];
                        trans[2][0] = array[a + 1][b - 1];
                        trans[2][1] = array[a + 1][b];
                        trans[2][2] = array[a + 1][b + 1];
                        livedied[a][b] = event(trans);
                        if(livedied[a][b])
                        {
                            counter[a-1][b-1]++;
                        }
                    }
                }
                flag = 1;
                continue;
            }
            for(a = 1 ; a < bian + 1 ; a++)
            {
                for(b = 1 ; b < bian + 1 ; b++)
                {
                    trans[0][0] = livedied[a - 1][b - 1];
                    trans[0][1] = livedied[a - 1][b];
                    trans[0][2] = livedied[a - 1][b + 1];
                    trans[1][0] = livedied[a][b - 1];
                    trans[1][1] = livedied[a][b];
                    trans[1][2] = livedied[a][b + 1];
                    trans[2][0] = livedied[a + 1][b - 1];
                    trans[2][1] = livedied[a + 1][b];
                    trans[2][2] = livedied[a + 1][b + 1];
                    array[a][b] = event(trans);
                    if(array[a][b])
                    {
                        counter[a-1][b-1]++;
                    }
                }
            }
            flag = 0;

        }
        if(flag == 1)
        {
            print(livedied , bian);
        }
        else
        {
            print(array , bian);
        }
    }
    int max[3] = {0};
    for(a = 0 ; a < bian ; a++)
    {
        for(b = 0 ; b < bian ; b++)
        {
            if(max[0] <= counter[a][b])
            {
                max[0] = counter[a][b];
                max[1] = a + 1;
                max[2] = b + 1;
            }
        }
    }
    printf("%d %d" , max[1] , max[2]);


    return 0;
}
