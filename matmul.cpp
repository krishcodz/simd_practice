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
