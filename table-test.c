#include <stdio.h>
#include "table.h"

int main(void)
{   
    // Create an empty table with a capacity for 100 buckets.
    Table *tab = table_create(100);
    char *check = "PASS";

    //Insert the value -n at position n in the table.
    for (int n = 1; n <= 10; n++) {
        int m = -n;
        table_insert(tab, n, m);
        table_insert(tab, n + 100, m - 100);
    }

    //Verify that the values have been inserted at the correct position.
    for (int i = 1; i <= 10; i++) {
        int j = -i;

        if (!(table_lookup(tab, i, &j))) {
            check = "FAIL";
        }
        j = -i - 100;
        
        if (!(table_lookup(tab, i + 100, &j))) {
            check = "FAIL";
        }
    }

    //Print the result of the verification.
    printf("Test the presence of added key/value pairs ... %s\n", check);

    check = "PASS";

    //Verify that the other keys havent been assigned a value.
    for (int n = 11; n < 101; n++) {
        int m = -n;

        if(table_lookup(tab, n, &m)) {
            check = "FAIL";
        }
    }

    for (int n = 111; n <= 200; n++) {
        int m = -n;

        if(table_lookup(tab, n, &m)) {
            check = "FAIL";
        }
    }

    //Print the result of the verification
    printf("Test the absence of non-added keys ... %s\n", check);

    //Deallocate the table.
    table_destroy(tab);

    return 0;
}