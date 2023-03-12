#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
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

void matrix::vector_scalar_multiple(double *b, double c, int m, int n)
{
    for (int i = m; i <= n; i++)
    {
        b[i] *= c;
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

void matrix::matrix_scalar_multiple(double **a, double c, int m1, int m2, int n1, int n2)
{
    for (int i = m1; i <= m2; ++i)
    {
        for (int j = n1; j <= n2; ++j)
        {
            a[i][j] *= c;
        }
    }
}

// L1ノルムの計算 a[m...n]
double matrix::vector_norm_L1(double *a, int m, int n)
{
    double norm = 0.0;
    for (int i = m; i <= n; ++i)
    {
        norm += fabs(a[i]);
    }

    return norm;
}

// L2ノルムの計算 a[m...n]
double matrix::vector_norm_L2(double *a, int m, int n)
{
    double norm = 0.0;
    for (int i = m; i <= n; ++i)
    {
        norm += a[i] * a[i];
    }
    norm = sqrt(norm);

    return norm;
}

// 最大値ノルムの計算 a[m...n]
double matrix::vector_norm_max(double *a, int m, int n)
{
    int tmp = n - m + 1; // 全要素数の計算
    for (int i = m; i <= n; ++i)
    {
        a[i] = fabs(a[i]);
    }

    /* 並び変え 先頭アドレスがmだけずれていることに注意 */
    qsort(a + m, tmp, sizeof(a[0]), double_comp);

    return a[n];
}

// 行列のL1ノルムの計算
// |A|_{L1} = \max_{1 <= j <= n}\sum_{i=1}^{n}|a_{ij}|
double matrix::matrix_norm_L1(double **a, int m1, int m2, int n1, int n2)
{
    double *work = matrix::dvector(n1, n2); // ベクトルwork[n1...n2]

    // 列和の計算
    for (int j = n1; j <= n2; ++j)
    { // 列を固定して、各列において...
        work[j] = 0.0;
        for (int i = m1; i <= m2; ++i)
        { // 行方向に和をとる
            work[j] += fabs(a[i][j]);
        }
    }

    int tmp = n2 - n1 + 1; // 列数の計算

    /* 並べ替え 先頭アドレスがn1だけずれている事に注意 */
    qsort(work + n1, tmp, sizeof(work[0]), double_comp);

    /* 列和の中で最大のものを行列のL1ノルムとして返す */
    double norm = work[n2];
    
    matrix::free_dvector(work, n1);

    return norm;
}

// 行列の最大値ノルムの計算
// |A|_{\infty} = \max_{1 <= i <= n}\sum_{j=1}^{n}|a_{ij}|
double matrix::matrix_norm_max(double **a, int m1, int m2, int n1, int n2)
{
    double *work = matrix::dvector(m1, m2); /* ベクトル work[m1...m2] */

    // 行和の計算
    for (int i = m1; i <= m2; ++i)
    {
        for (int j = n1; j <= n2; ++j)
        {
            work[i] += fabs(a[i][j]);
        }
    }

    int tmp = m2 - m1 + 1; // 行数の計算
    /* 並べ替え 先頭アドレスがm1だけずれている事に注意 */
    qsort(work + m1, tmp, sizeof(work[0]), double_comp);

    /* 行和の中で最大のものを行列の最大値ノルムとして返す */
    double norm = work[m2];

    matrix::free_dvector(work, m1);

    return norm;
}

// 比較関数
int matrix::double_comp(const void *s1, const void *s2)
{
    const double a1 = *((double *)s1); /* (double *)へキャスト */
    const double a2 = *((double *)s2); /* (double *)へキャスト */

    if (a1 < a2)
    {
        return -1;
    }
    else if (a1 == a2)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}


// 行列の生成 a[nr1...nr2][nl1...nl2]
double** matrix::produce_matrix(double **a, int nr1, int nr2, int nl1, int nl2)
{
    int i, j;
    srand((unsigned)time(NULL)); /* シードを与える */
    for (i = nr1; i <= nr2; i++)
    {
        for (j = nl1; j <= nl2; j++)
        {
            a[i][j] = (double)rand() / (double)RAND_MAX;
        }
    }

    return a;
}

