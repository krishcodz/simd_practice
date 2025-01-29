#include <iostream>
#include <cstdlib>
using namespace std;

void fillMatrix(float *matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i * N + j] = static_cast<float>(rand() % 10);
        }
    }
}

void printMatrix(const float *matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i * N + j] << " ";
        }
        cout << "\n";
    }
}

bool checkMatrix(const float *matrix1, const float *matrix2, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix1[i * N + j] != matrix2[i * N + j])
            {
                return false;
            }
        }
    }
    return true;
}