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

            for (int j = 0; j < N; j++)
            {
                arr3[i][j] = 0;
                for (int k = 0; k < N; k++)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }
    printMatrix(&arr3[0][0], N);

    return 0;
}
