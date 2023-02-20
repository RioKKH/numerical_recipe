#include <iostream>
#include <cstdio>

/**
 * 埋め合わせ法のアルゴリズム
 * s = 0; e = 0;
 * For i = 1, 2, ..., n
 *   tmp = s
 *   y = a_i + e
 *   s = tmp + y
 *   e = (tmp - s) + y
 * end for
 */
const std::int32_t N = 1'000'000;

int main(void)
{
    double s, e, y, tmp;
    int i;
    /* Recursive summation */
    s = 0.0;
    for (i = 1; i <= N; i++)
    {
        s += 0.1;
    }
    printf("Recursive summationの結果は\t %30.20f \n", s);

    /* Compensated summation */
    s = 0.0; e = 0.0;
    for (i = 1; i <= N; ++i)
    {
        tmp = s;
        y = 0.1 + e;
        s = tmp + y;
        e = (tmp -s) + y;
    }

    printf("Compensated summationの結果は\t %30.20f \n", s);
    return 0;
}
