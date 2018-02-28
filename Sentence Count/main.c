#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char article[1000000];
    int i = 0;
    int counter = 0;
    while(scanf("%c" , &article[i]) != EOF)
    {
        i++;
    }
    for(int a = 0 ; a < i ; a++)
    {
        if(article[a] == '.')
        {
            if(article[a+1] == ' ' && article[a+2] == ' ')
            {
                counter++;
            }
            else if(article[a+1] == '\n')
            {
                counter++;
            }
            else if(article[a+1] == '\0'){
                counter++;
            }
            int sign = 0 , b = a;
            while(b < i){
                if(article[b] != ' ' || article[b] != '\n'){
                    sign++;
                }
                b++;
            }
            if(sign == 0){
                counter++;
            }

        }

    }
    printf("%d" , counter);
    return 0;
}
