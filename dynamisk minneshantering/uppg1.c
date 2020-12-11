#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char *p;
} s;

int main(void)
{   
    s *array;

    array = calloc(3, sizeof(s));

    for (int i = 0; i < 3; i++) {

        array[i].n = i;
        array[i].p = "x";
    }

    printf("array[1].n = %d\n", array[0].n);
    printf("array[1].n = %s\n", array[1].p);

    free(array);
    array = NULL;

    return 0;
}