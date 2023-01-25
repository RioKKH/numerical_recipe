#include <cstdio>

int main(void)
{
    char x = 123;  // 01111011
    char y;
    char z = 0xf0; // 11110000

    y = x & z;
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
