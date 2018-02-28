#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int width1 , length1 , width2 , length2 ;
    char first , second;

    unsigned long int input = 0;
    scanf("%d" , &width1);
    scanf("%d" , &length1);
    width2 = width1;
    length2 = length1;
    scanf("%s" , &first);
    scanf("%s" , &second);

    int counter = 0;

    int sum = 1;

    sum = width2 * length2;
    scanf("%lu" , &input);
    while(counter != sum)
    {

        for(int i = 31 ; i >= 0 ; i--)
        {
            if(counter == sum)
            {
                break;
                return 0;
            }
            if(counter % width2 == 0 && counter != 0)
            {
                printf("\n");
            }
            if(input & ((unsigned long int)1 << i))
            {
                printf("%c" , first);
            }
            else
            {
                printf("%c" , second);
            }
            counter++;
        }
        if(counter != sum)
        {
            scanf("%lu" , &input);
        }
    }







    return 0;
}
