#include <stdio.h>
int* insertionSort(int* A, int n) {
        int m = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = i-1; j >= 0; --j)
            {
                if(A[j] > A[j+1])
                {
                    m = A[j+1];
                    A[j+1] = A[j];
                    A[j] = m;
                }
                else
                {
                    break;
                }
            }
        }
        return A;
    }
int main()
{
    int A[13] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    insertionSort(A,13);
    for (int i = 0; i < 13; ++i)
    {
        printf("%d ",A[i]);
    }
    return 0;
}