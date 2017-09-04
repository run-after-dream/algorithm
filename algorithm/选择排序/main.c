#include <stdio.h>
int* selectionSort(int* A, int n) {
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if(A[j] < A[i])
                {
                    m = A[j];
                    A[j] = A[i];
                    A[i] = m;
                }
            }
        }
        return A;
    }
int main(int argc, char const *argv[])
{
    int A[6] = {1,2,3,5,2,3};
    selectionSort(A,6);
    for(int i = 0; i < 6; ++i)
    {
        printf("%d \n",A[i]);
    }
    return 0;
}