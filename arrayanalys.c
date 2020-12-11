/* This program is intended to be run on a Linux-based operating system. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "array.h"


/* Return the current time in seconds with high precision. */
static double get_time(void)
{
  struct timeval tv;
  gettimeofday(&tv, 0); 	/* Defined in POSIX (not standard C). */
  return tv.tv_sec + tv.tv_usec * 1e-6;
}


int main(void)
{
  /* Print information about the program. */

    Array *arr = array_create(5, 20);
  /* Print table header. */
  printf("%10s\t%10s\n", "n", "tid");

    int rows = array_rows(arr);
    int cols = array_columns(arr);
    int cnt = 1;
  /* Loop over problem sizes. */
  for (int r = 0; r < rows; r++) {
    /* Insert n values at the beginning of the list. */
    double T = get_time();
    for (int c = 0; c < cols; c++) {

        array_set(arr, r, c, cnt++);
        
        T = get_time() - T;

        printf("%10d\t%10.6lf\n", cnt - 1, T);
    }
    

    /* Print the results for this problem size. */
    

    /* Abort when the time is starting to get significant. */
    if (T > 1)
      break;
  }
}