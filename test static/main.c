#include <stdio.h>

void static_function(int as)
{
    static int a = 0;
    printf("a before assign:%d\n", a);
    a = as;
    printf("a after assign:%d\n", a);
}

void main()
{
    static_function(1);
    static_function(2);
    static_function(3);

}
