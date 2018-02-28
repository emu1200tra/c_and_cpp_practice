#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key[1024];
    char value[1024][127];
    int num;
}Map;

void test_all(Map *map) {
    map->value[0][0] = 's';
    printf("value:%c\n", map->value[0][0]);
}

int main()
{
    int map_n = 1;
    Map *maps = (Map *) malloc(sizeof(Map) * map_n);
    test_all(maps);
    free(maps);

    return 0;
}
