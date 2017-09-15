#include <iostream>
using namespace std;

void sift(int a[], int low, int high)
{
    int i = low, j = 0;
    int temp = a[i];
    if(2*low > high)
    {
        return;
    }
    if((2*i+1) <= high)
    {
        j = (a[2*i] > a[2*i+1])?(2*i):(2*i+1);
    }
    else
    {
        j = 2*i;
    }

    while(j <= high)
    {
        if(a[j] > a[i])
        {
            a[i] = a[j];//大数上浮
            i = j;
            if((2*i+1) <= high)
            {
                j = (a[2*i] > a[2*i+1])?(2*i):(2*i+1);
            }
            else
            {
                j = 2*i;
            }
        }
        else
        {
            break;
        }
    }
    a[i] = temp;
}

int main()
{
    int a[] = {7,3,4,8,2,1};
    int len = (sizeof(a)/sizeof(int));
    int b[len+1] = {0};

    for(int i = 0; i < len; i++)
    {
        b[i+1] = a[i];
    }

    for(int i = 1; i < len+1; i++)//排序前
    {
        cout << b[i] << " ";
    }
    cout << endl;

    for(int i = (len)/2; i >= 1; i--)//堆排序
    {
        sift(b,i,len);
    }
    //获得由小到大排序的数组
    b[len] = b[len] + b[1];//交换b[len]和b[1]
    b[1] = b[len] - b[1];
    b[len] = b[len] - b[1];
    for(int i = len-1; i > 1; i--)
    {
        sift(b,1,i);
        b[i] = b[i] + b[1];//交换b[len]和b[1]
        b[1] = b[i] - b[1];
        b[i] = b[i] - b[1];
    }

    for(int i = 1; i < len+1; i++)//排序后
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}