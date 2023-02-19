#include <iostream>
#include "matrix.hpp"

const int N = 4;

int main(void)
{
    FILE *fin, *fout;
    double **a, *b;

    a = matrix::dmatrix(1, N, 1, N);
    b = matrix::dvector(1, N);

    // ファイルのオープン
    if ((fin = fopen("input.dat", "r")) == NULL)
    {
        std::cerr << "No file found" << std::endl;
        exit(1);
    }
    if ((fout = fopen("output.dat", "w")) == NULL)
    {
        std::cerr << "No file found" << std::endl;
        exit(1);
    }

    matrix::input_matrix(a, 'A', fin, fout, N);
    matrix::input_vector(b, 'b', fin, fout, N);

    fclose(fin);
    fclose(fout);

    matrix::free_dmatrix(a, 1, N, 1, N);
    matrix::free_dvector(b, 1);

    return 0;
}
