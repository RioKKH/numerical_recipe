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
