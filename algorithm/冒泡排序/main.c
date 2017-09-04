#include <stdio.h>
int* bubbleSort(int* A, int n) {
        int m = 0;
        for(int i = n; i > 0; i--)
        {
            for(int j = 0; j < (i-1); j++)
            {
                if(A[j] > A[j+1])
                {
                    m = A[j];
                    A[j] = A[j+1];
                    A[j+1] = m;
                }
            }
        }
    return A;
};
int main(int argc, char const *argv[])
{
    printf("hello world\n");
    int A[28] = {32,103,24,88,95,70,97,15,102,6,79,46,51,37,93,108,9,58,53,58,79,36,58,91,78,58,61,81};
    bubbleSort(A,28);
    for(int i = 0; i < 28; i++)
    {
        printf("%d,", A[i]);
    }
    return 0;
}