#include <iostream>
#include <cstdio>
#include <cstdlib>

const int N = 8; // ベクトルの要素数

// ベクトルを0オフセットではなくて、1オフセットにするための方法を
// このコードでみる。将来的に数値計算の中でこの手法を用いてベクトルの
// メモリ領域を確保する。
int main(void)
{
    double *a, *aa;
    int i;

    if ((aa = (double *)malloc(sizeof(double)*N)) == NULL)
    {
        printf("メモリが確保できません(ベクトルaa)\n");
        exit(1);
    }

    for (i = 0; i < N; i++)
    {
        aa[i] = 2.0 * (i + 1);
    }

    // aはaaより一つ前の位置を指すのでa[i + 1] == aa[i]という関係が成り立つ
    // a[0]の実体はないので、a[0]を参照するようなことをしてはいけない。
    // つまりfree(a)のようなことをすると、実体の無いa[0]を開放しようとしてしまう為、
    // メモリは解が起きる可能性が有る。
    a = aa - 1;

    printf("ベクトルaとaaの内容は次の通りです\n");
    for (i = 0; i < N; i++)
    {
        printf("a[%d]=%f \t aa[%d]=%f \n", i + 1, a[i+1], i, aa[i]);
    }

    // 実際に領域が確保されているのはaa[0] ~ aa[N-1]なので、メモリを解放するときには
    // free(aa)だけで十分である
    free(aa);
    return 0;
}
