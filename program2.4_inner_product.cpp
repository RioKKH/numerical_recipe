#include <cstdio>
#include <cstdlib>
#include <iostream>

const int N = 5; // 要素数の指定

// 行列の入力
void input_matrix(double **a, char c, FILE *fin, FILE *fout);

// ベクトルの入力
void input_vector(double *b, char c, FILE *fin, FILE *fout);

// 行列の領域確保
double **dmatrix(int nr1, int nr2, int nl1, int nl2);

// 行列の領域解放
void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
double *dvector(int i, int j); // ベクトル領域の確保
void free_dvector(double *a, int i); // 領域の開放


int main(void)
{
    double *a, *b;
    int i;

    // ベクトルの定義、配列a, bの添え字は1 ~ N
    a = dvector(1, N);
    b = dvector(1, N);
    for (i = 1; i <= N; ++i)
    {
        a[i] = (double)i/20.0;
        b[i] = (double)i/10.0;
    }

    return 0;
}

// a[1....N][1...N]の入力
void input_matrix(double **a, char c, FILE *fin, FILE *fout)
{
    int i, j;

    fprintf(fout, "行列%cは次の通りです\n", c);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            fscanf(fin, "%lf", &a[i][j]);
            fprintf(fout, "%5.2f\t", a[i][j]);
        }
        fprintf(fout, "\n");
    }
}

// b[1...N]の入力
void input_vector(double *b, char c, FILE *fin, FILE *fout)
{
    int i;

    fprintf(fout, "ベクトル%cは次の通りです\n", c);
    for (i = 1; i <= N; i++)
    {
        fscanf(fin, "%lf", &b[i]);
        fprintf(fout, "%5.2f\t", b[i]);
        fprintf(fout, "\n");
    }
}

double **dmatrix(int nr1, int nr2, int nl1, int nl2)
{
    int i, nrow, ncol;
    double **a;

    nrow = nr2 - nr1 + 1;
    ncol = nl2 - nl1 + 1;

    if ((a = (double **)malloc(nrow * sizeof(double *))) == NULL)
    {
        printf("メモリが確保できません\n");
        exit(1);
    }

    std::cout << "before: " << a << std::endl;
    a = a - nr1; // 行をずらす --> この処理の意味が分からない。
    // --> 恐らく確保する領域の始点に応じてシフトさせる必要がある、
    //     ということだと思う。
    std::cout << "after:  " << a << std::endl;

    for (i = nr1; i <= nr2; i++)
    {
        a[i] = (double *)malloc(ncol * sizeof(double));
    }
    for (i = nr1; i <= nr2; i++)
    {
        a[i] = a[i] - nl1; // 列をずらす --> この処理の意味が分からない
    }

    return(a);
}

void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2)
{
    int i;
    for (i = nr1; i <= nr2; i++)
    {
        free((void *)(a[i] + nl1));
    }
    free((void *)(a + nr1));
}

double *dvector(int i, int j) // a[i] ~ a[j]の領域を確保する
{
    double *a;
    if ((a = (double *)malloc((j - i + 1) * sizeof(double))) == NULL)
    {
        printf("メモｒいが確保できません\n");
        exit(1);
    }

    return (a-i);
}

void free_dvector(double *a, int i)
{
    free((void *)(a + i));
}
    





