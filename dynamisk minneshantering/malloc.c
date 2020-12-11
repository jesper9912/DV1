#include <stdio.h>
#include <stdlib.h>

char *read_line(void);

int main(void) 
{
    printf("Enter a string: ");

    char *str = read_line();

    printf("*str = '%s'\n", str);
 
    return 0;
}

char *read_line(void)
{
    int capacity = 4;
    char *str = malloc(capacity * sizeof(char));
    int size = 0;

    char c = getchar();

    while (c != '\n') {
        if (size + 1 == capacity) {

            char *tmp = malloc(capacity * sizeof(char));
            for (int i = 0; i < size; i++) {

                tmp[i] = str[i];
            }
            
            realloc(str, capacity *= 2);
            str = tmp;
        }

    str[size] = c;
    size++;
    c = getchar();
    }

    return str;
}