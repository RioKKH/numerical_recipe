#include <cstdio>

int main(void)
{
    double a, b, c, d;
    a =  1.0 / 0.0; // プラスinfの生成
    b = -1.0 / 0.0; // マイナスinfの生成
    printf("符号付き +inf a = %f\n", a);
    printf("符号付き -inf b = %f\n", b);

    c = 1.0 / a; // 符号付ゼロの生成 +0.0000
    d = 1.0 / b; // 符号付ゼロの生成 -0.0000
    printf("c = %f d = %f\n", c, d);
    printf("ans1 = %f, ans2 = %f\n", 1.0/c, 1.0/d);

    return 0;
}
