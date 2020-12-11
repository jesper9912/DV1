#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *random_array(int n);

int main(void)
{   
    srand(time(NULL));

    int *array = random_array(100);

    for (int i = 0; i < 100; i++) {

        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}

int *random_array(int n)
{
    int *array;
    array = calloc(n, sizeof(array));

    if (array != NULL) {

        for (int i = 0; i < n; i++) {

            array[i] = rand()%100;
        }

    }

    return array;
}