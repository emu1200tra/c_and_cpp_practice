#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze(char array[] , int i )
{
    long long sum = 0;
    for(int a = 0 ; a < i ; a++)
    {
        sum = sum + (array[a] - '0');
    }
    int sum2 = 0 , evenpositioned = 0 , oddpositioned = 0;
    for(int a = 0 ; a < i ; a++)
    {
        if(a % 2 == 1)
        {
            oddpositioned = oddpositioned + (array[a] - '0');
        }
        else
        {
            evenpositioned = evenpositioned + (array[a] - '0');
        }
    }
    sum2 = abs(evenpositioned - oddpositioned);
    if((array[i-1] - '0') % 2 == 0)
    {
        printf("yes ");

    }
    else
    {
        printf("no ");
    }
    if(sum % 3 == 0)
    {
        printf("yes ");
    }
    else
    {
        printf("no ");
    }
    if((array[i-1] - '0') % 5 == 0)
    {
        printf("yes ");

    }
    else
    {
        printf("no ");
    }
    if(sum2 % 11 == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

}




int main()
{
    char number[1000];
    int length = 0;
    char endpoint = '0';
    scanf("%s" , &number[0]);
    while(endpoint != '-')
    {
        length = strlen(number);
        analyze(number , length);
        scanf("%s" , &number[0]);
        endpoint = number[0];
    }


    return 0;
}
