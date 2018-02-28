#include <stdio.h>
#include "fraction.h"
#include <time.h>

void test(int *cmd , int *x , int *y , int *z , int *w){
    *cmd = rand() % 4 + 1;
    *x = rand();
    *y = rand() + 1;
    *z = rand();
    *w = rand() + 1;

}


int main() {
    int i, cmd, x, y, z, w;
    Frac a, b, c;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        test(&cmd , &x , &y , &z , &w);
        printf("cmd: %d\nx: %d\ny: %d\nz: %d\nw:%d\n" , cmd , x , y , z , w);
    //    scanf("%d", &cmd);
    //    scanf("%d %d %d %d", &x, &y, &z, &w);
        a = normal(x, y), b = normal(z, w);
        if (cmd == 1) {
            c = add(a, b);
        } else if (cmd == 2) {
            c = subtract(a, b);
        } else if (cmd == 3) {
            c = multipy(a, b);
        } else if (cmd == 4) {
            c = divide(a, b);
        }
        printf("%lld / %lld\n", c.a, c.b);
    }
    return 0;
}
