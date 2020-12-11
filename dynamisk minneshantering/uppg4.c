#include <stdio.h>
#include <stdlib.h>

int *copy_array(int n, const int a[n]);

int main(void)
{
    int n = 9;
    const int a[] = {1,2,3,4,5,6,7,8,9}; 
    int *new_a = NULL;

    new_a = copy_array(n, a);

    for (int i = 0; i < n; i++) {

        printf("new_a[%d] = %d\n", i, new_a[i]);
    }

    free(new_a);
    return 0;
}

int *copy_array(int n, const int a[n])
{

    int *new_a;

    new_a = calloc(n, sizeof(int));

    if (new_a != NULL) {

        for (int i = 0; i < n; i++) {

            new_a[i] = a[i];
        }
    }

    return new_a;
}