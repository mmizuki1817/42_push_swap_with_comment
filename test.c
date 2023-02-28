#include <stdio.h>


int main()
{
    int argc = 9;

    int num = argc - 1;
    int count = 0;
    while (num > 3)
    {
        num = num - (num / 2); // num/2:bに移す分 num-(num/2):aに残っている分
        count++;
        printf("num%i count%i\n", num, count);
    }
}