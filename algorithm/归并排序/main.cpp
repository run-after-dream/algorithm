#include <iostream>
using namespace std;

void merge(int R[], int low, int mid, int high)
{
    int R1[high+1];
    int i = 0, j = mid, k = 0;
    while(k <= high)
    {
        if((i < mid)&&(j <= high))
        {
            if(R[i] < R[j])
            {
                R1[k] = R[i];
                i++;
                k++;
            }
            else
            {
                R1[k] = R[j];
                j++;
                k++;
            }
        }
        else
        {
            if(i >= mid)
            {
                R1[k] = R[j];
                j++;
                k++;
            }
            else
            {
                R1[k] = R[i];
                i++;
                k++;
            }
        }
    }
    for(int i = 0; i <= high; i++)
    {
        R[i] = R1[i];
    }
}

void merge_pass(int R[], int n, int len)
{
    cout << "begin" << endl;
    for (int i = 0; i < len-n; i += n)
    {
        merge(R, i, i+n, i+2*n-1);
        cout << i+2*n-1 << endl;
    }
}

void merge_process(int R[], int len)
{
    for(int i = 1; i <= len/2; i *= 2)
    {
        merge_pass(R, i, len);
    }
}

int main()
{
    int R[] = {3,5,6,8,1,2,4,9};
    int len = sizeof(R)/sizeof(int);
    cout << len << endl;
    merge_process(R, len);
    for(int i = 0; i < len; i++)
    {
        cout << R[i] << " ";
    }
    cout << endl;
    return 0;
}