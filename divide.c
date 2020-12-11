/*
 * Description of internal details in the module.
 */
#include <stdio.h>
#include <stdlib.h>
#include "divide.h"

int main(void)
{
    double quota = 0;

    quota = divide(10 , 6);

    printf("quota = %.2lf\n", quota);
    
    return 0;
}

double divide(int num, int denom)
{
    double quota = 0;

    quota = (double) num / denom;

    return quota;
}