#include <immintrin.h>
#include <iostream>
using namespace std;

int main()
{
    alignas(32) float arr1[8][8] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8}};

    alignas(32) float arr2[8][8] = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1}};

    alignas(32) float arr3[8][8];

    int N = 8;
    for (int test = 0; test < 1000; test++)
    {
        for (int i = 0; i < N; i++)
        {
            __m256 result = _mm256_setzero_ps();
            for (int j = 0; j < N; j++)
            {
                __m256 rowA = _mm256_broadcast_ss(&arr1[i][j]);
                __m256 rowB = _mm256_load_ps(arr2[j]);
                result = _mm256_fmadd_ps(rowA, rowB, result);
            }
            _mm256_store_ps(&arr3[i][0], result);
        }
    }
    cout << "Result :" << "\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
