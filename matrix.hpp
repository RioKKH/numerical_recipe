#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <cstdio>

namespace matrix
{
    // ベクトルの領域確保
    double* dvector(int i, int j);
    // ベクトルのメモリ解放
    void free_dvector(double *a, int i);
    // ベクトルの入力
    void input_vector(double *b, char c, FILE *fin, FILE *fout, int N);
    // ベクトルのL1ノルムの計算
    double vector_norm_L1(double *a, int m, int n);
    // ベクトルのL2ノルムの計算
    double vector_norm_L2(double *a, int m, int n);
    // ベクトルの最大値ノルムの計算
    double vector_norm_max(double *a, int m, int n);

    // 行列の領域確保
    double **dmatrix(int nr1, int nr2, int nl1, int nl2);
    // 行列のメモリ解放
    void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
    // 行列の入力
    void input_matrix(double **a, char c, FILE *fin, FILE *fout, int N);
    // 内積
    double inner_product(int m, int n, double *a, double *b);
    // 和
    void matrix_sum(double **a, double **b, double **c,
                    int m1, int m2, int n1, int n2);
    // 積
    void matrix_product(double **a, double **b, double **c,
                        int l1, int l2, int m1, int m2, int n1, int n2);
    // 行列のL1ノルム
    double matrix_norm_L1(double **a, int m1, int m2, int n1, int n2);
    // 行列の最大値ノルム
    double matrix_norm_max(double **a, int m1, int m2, int n1, int n2);
    // ソート
    int double_comp(const void *s1, const void *s2);
}

#endif // _MATRIX_HPP
