#include <stdio.h>

int main(void)
{
    int i;

    i = 1;
    printf("i:%i %c\n", i, (char)i);
    i = 0;
    printf("i:%i %c\n", i, i);
    i = '\0';
    printf("i:%i %c\n", i, i);
}