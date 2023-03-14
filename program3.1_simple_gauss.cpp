#include <cstdio>
#include <cstdlib>
#include "matrix.hpp"

const int N = 4;

int main(void)
{
    FILE *fin, *fout;
    double **a, *b;
    int i;

    /* 行列およびベクトルの領域確保 */
    a = matrix::dmatrix(1, N, 1, N); /* 行列 a[1...N][1...N] */
    b = matrix::dvector(1, N); /* ベクトル b[1...N] */

    /* ファイルのオープン */
    if ((fin = fopen("input.dat", "r")) == NULL)
    {
        printf("ファイルが見つかりません : input.dat\n");
        exit(1);
    }

    if ((fout = fopen("output.dat", "w")) == NULL)
    {
        printf("ファイルが作成できません : output.dat\n");
        exit(1);
    }

    matrix::input_matrix(a, 'A', fin, fout, N); // 行列Aの入出力
    matrix::input_vector(b, 'b', fin, fout, N); // ベクトルbの入出力
    b = matrix::simple_gauss(a, b, N); // ガウスの消去法
    
    /* 結果の出力 */
    fprintf(fout, "Ax = bの解は次の通りです\n");
    for (i = 1; i <= N; ++i)
    {
        fprintf(fout, "%f\n", b[i]);
    }

    /* ファイルのクローズ */
    fclose(fin);
    fclose(fout);

    /* 領域の開放 */
    matrix::free_dmatrix(a, 1, N, 1, N);
    matrix::free_dvector(b, 1);

    return 0;
}

