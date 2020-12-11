#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
int *p = malloc(sizeof(int));
*p = 42;
p = calloc(4, sizeof(int));
p[1] = 3;
free(p);
}