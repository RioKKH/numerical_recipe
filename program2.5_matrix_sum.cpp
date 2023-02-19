#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "matrix.hpp"

const int ROW    = 3; /*行の要素数*/
const int COLUMN = 4; /*列の要素数*/

int main(void)
{
    double **a, **b, **c;
    
    a = matrix::dmatrix(1, ROW, 1, COLUMN); /*行列 a[1...ROW][1...COLUMN]*/
    b = matrix::dmatrix(1, ROW, 1, COLUMN); /*行列 b[1...ROW][1...COLUMN]*/
    c = matrix::dmatrix(1, ROW, 1, COLUMN); /*行列 c[1...ROW][1...COLUMN]*/

    /* 行列の定義 */
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COLUMN; ++j)
        {
            a[i][j] = 2.0 * (i + j);
            b[i][j] = 3.0 * (i + j);
        }
    }

    matrix::matrix_sum(a, b, c, 1, ROW, 1, COLUMN);

    /* 結果の表示 */
    std::cout << "行列Aと行列Bの和は次の通りです" << std::endl;
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COLUMN; ++j)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    matrix::free_dmatrix(a, 1, ROW, 1, COLUMN);
    matrix::free_dmatrix(b, 1, ROW, 1, COLUMN);
    matrix::free_dmatrix(c, 1, ROW, 1, COLUMN);

    return 0;
}
