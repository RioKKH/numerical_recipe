#include <cstdio>

int main(void)
{
    double a, b;
    a = 0.0/0.0; // NaNの生成
    printf("a = %f\n", a); // nanがプリントアウトされる。エラー終了はしていない

    b = 1.0 + a; // NaNを含む演算
    printf("b = %f\n", b);

    return 0;
}
