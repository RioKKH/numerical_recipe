#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
    int i;
    printf("シード無し\n");
    for (i = 1; i <= 2; i++)
    {
        printf("%d\n", rand());
    }
    printf("シード無し\n");
