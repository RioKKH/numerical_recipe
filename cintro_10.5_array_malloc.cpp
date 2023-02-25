#include <iostream>
#include <cstdio>
#include <cstdlib>

const int M = 2; // 行の要素数
const int N = 3; // 列の要素数

int main(void)
{
    double **a;
    int i, j;

    if ((a = (double **)malloc(M * sizeof(double *))) == NULL)
    {
        printf("メモリが確保できません(行列a)\n");
        exit(1);
    }

    /* 行を１つずらす 
     * この結果, b[1] = a[0]となる
     * 実際にはbと置き換える必要がないのでa = a -1とすれば、
     * a[1]がもともとのa[0]へのアクセスに相当することになる。
     * ずらした後はa[0]には実体がないので、ここにアクセスするような
     * 処理を書いてはいけない
     * */
    a = a - 1;
    for (i = 1; i <= M; i++)
    {
        // 列の確保。一列ずつmallocを用いて確保する
        a[i] = (double *)malloc(N * sizeof(double));
    }

    for (i = 1; i <= M; i++)
    {
        // 列を一つずつずらす
        // ここでも同様にずらした後はa[i][0]には実体がないので、
        // ここにアクセスするような処理を書いてはいけない
        a[i] = a[i] - 1;
    }

    for (i = 1; i <= M; i++)
    {
        for (j = 1; j <= N; j++)
        {
            a[i][j] = (i + j) / 2.0;
            printf("a[%d][%d] = %f \n", i, j, a[i][j]);
        }
    }
    
    // なので以下のコードはsegmentation faultになってしまう
    // std::cout << a[0][0];

    /* メモリの開放 */
    for (i = 1; i <= M; i++)
    {
        // 解放するときには1つずらしたことを考慮して、1つ足してやる
        free((void *)(a[i] + 1));
    }
    free((void *)(a + 1));

    return 0;
}
