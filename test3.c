#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int min;
    int max;
    int i;
    int num_cpy[100];
    if (argc < 3)
        return 0;
    // if (argc = 2)
    // {

    // }
    i = 0;
//    num_cpy[i] = atoi(argv[i + 1]);
    while (i < 5)
    {
        num_cpy[i] = atoi(argv[i + 1]);
        i++;
    }
     
    min = num_cpy[0];
    max = num_cpy[0];
    i = 1;
    
    while (i < argc - 2)
    {
        if (max < num_cpy[i])
            max = num_cpy[i];
        if (min > num_cpy[i])
            min = num_cpy[i];
        i++;
    }
    printf("%i %i", max, min);
    //find_min_and_max();

    //return (true);
}