#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(void)
{
    int i;

    printf("シード無し\n");
    for (i = 1; i <= 2; i++)
    {
        printf("%d\t", rand());
    }
    printf("\n");

    printf("シード有り\n");
    srand((unsigned)time(NULL));
    for (i = 1; i <= 2; i++)
    {
        printf("%d\t", rand());
    }
    printf("\n");

    return 0;
}
