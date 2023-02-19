#ifndef _MATRIX_HPP
#define _MATRIX_HPP

namespace matrix
{
    // ベクトルの領域確保
    double* dvector(int i, int j);
    // ベクトルのメモリ解放
    void free_dvector(double *a, int i);

    // 行列の領域確保
    double **dmatrix(int nr1, int nr2, int nl1, int nl2);
    // 行列のメモリ解放
    void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
}

#endif // _MATRIX_HPP
