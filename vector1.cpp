#include <immintrin.h>
#include <iostream>
#include <cstdlib>
#include "helper.h"
using namespace std;

int main()
{
    int N = 8;
    alignas(32) float arr1[N][N];
    alignas(32) float arr2[N][N];
    alignas(32) float arr3[N][N];
    fillMatrix(&arr1[0][0], N);
    fillMatrix(&arr2[0][0], N);

    for (int test = 0; test < 1000; test++)
    {

        for (int i = 0; i < N; i++)
        {
            __m256 result = _mm256_setzero_ps();
            for (int j = 0; j < N; j++)
            {
                __m256 row = _mm256_load_ps(arr1[i]);
                __m256 col = _mm256_set_ps(
                    arr2[7][j], arr2[6][j], arr2[5][j], arr2[4][j],
                    arr2[3][j], arr2[2][j], arr2[1][j], arr2[0][j]);
                result = _mm256_fmadd_ps(row, col, result);
            }
            _mm256_store_ps(&arr3[i][0], result);
        }
    }

    printMatrix(&arr3[0][0], N);

    return 0;
}
