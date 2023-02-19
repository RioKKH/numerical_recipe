#include <exception>
#include <iostream>
#include "matrix.hpp"

double* matrix::dvector(int i, int j)
{
    try
    {
        double *a;
        a = static_cast<double *>(malloc( ((j-i+1)*sizeof(double))));

        return (a-i);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

void matrix::free_dvector(double *a, int i)
{
    free( static_cast<void *>(a + i) );
}

double** matrix::dmatrix(int nr1, int nr2, int nl1, int nl2)
{
    try {
        int i, nrows, ncols;
        double **a;

        nrows = nr2 - nr1 + 1; // 行の数
        ncols = nl2 - nr1 + 1; // 列の数

        // 行の確保
        a = static_cast<double **>(malloc(nrows * sizeof(double *)));

        a = a - nr1; // 行をずらす

        // 列の確保
        for (i = nr1; i <= nr2; i++) a[i] = static_cast<double *>(malloc(ncols * sizeof(double)));
        for (i = nr1; i <= nr2; i++) a[i] = a[i] - nl1; // 列をずらす

        return (a);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

void matrix::free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2)
{
    // メモリの開放
    for (int i = nr1; i <= nr2; i++) free((void *)(a[i] + nl1));
    free((void *)(a + nr1));
}

// a[1...N][1...N]の入力
void matrix::input_matrix(double **a, char c, FILE *fin, FILE *fout, int N)
{
    try
    {
        fprintf(fout, "Matrix %c\n", c);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                fscanf( fin,  "%lf",    &a[i][j]);
                fprintf(fout, "%5.2f\t", a[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

// b[1...N]の入力
void matrix::input_vector(double *b, char c, FILE *fin, FILE *fout, int N)
{
    try
    {
        fprintf(fout, "Vector %c\n", c);
        for (int i = 1; i <= N; i++)
        {
            fscanf(fin, "%lf", &b[i]);
            fprintf(fout, "%5.2f\t", b[i]);
            fprintf(fout, "\n");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

// ベクトルa[m...n]とb[m...n]の内積を計算する
double matrix::inner_product(int m, int n, double *a, double *b)
{
    double s = 0.0;
    for (int i = m; i <= n; i++)
    {
        s += a[i] * b[i];
    }

    return s;
}

// 行列の和の計算
// a[m1...m2][n1...n2]とb[m1...m2][n1...n2]の和を求める。結果はcへ
void matrix::matrix_sum(double **a, double **b, double **c,
                        int m1, int m2, int n1, int n2)
{
    for (int i = m1; i <= m2; ++i)
    {
        for (int j = n1; j <= n2; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// 行列の積の計算
void matrix::matrix_product(double **a, double **b, double **c,
                            int l1, int l2, int m1, int m2, int n1, int n2)
{
    for (int i = l1; i <= l2; ++i)
    {
        for (int j = n1; j <= n2; ++j)
        {
            c[i][j] = 0.0; /* 変数の初期化 */
            for (int k = m1; k <= m2; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
