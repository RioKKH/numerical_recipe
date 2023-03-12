#include <cstdio>
#include <cstdlib>
#include "matrix.hpp"

const int ROW = 3;
const int COL = 4;
const double c = 2.0;

int main(void)
{
    double **a, *b;
    a = matrix::dmatrix(1, ROW, 1, COL);
    b = matrix::dvector(1, COL);

    /* 行列Aの定義 */
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COL; ++j)
        {
            a[i][j] = 1.0 * (i + j);
        }
    }
    /* ベクトルbの定義 */
    for (int i = 1; i <= COL; ++i)
    {
        b[i] = 1.0 * i;
    }

    printf("スカラー倍前の行列\n");
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COL; ++j)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }

    printf("スカラー倍前のベクトル\n");
    for (int i = 1; i <= COL; ++i)
    {
        printf("%f\t", b[i]);
    }
    printf("\n");

    matrix::matrix_scalar_multiple(a, c, 1, ROW, 1, COL);
    matrix::vector_scalar_multiple(b, c, 1, COL);

    printf("スカラー倍後の行列\n");
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COL; ++j)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }

    printf("スカラー倍後のベクトル\n");
    for (int i = 1; i <= COL; ++i)
    {
        printf("%f\t", b[i]);
    }
    printf("\n");

    matrix::free_dmatrix(a, 1, ROW, 1, COL);
    matrix::free_dvector(b, 1);

    return 0;
}



