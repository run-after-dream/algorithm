#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int KeyType;

typedef struct{
    KeyType key;
    int data;
}RecType;

// 两数交换
void swap(RecType &a, RecType &b)
{
    RecType temp;
    temp = a;
    a = b;
    b = temp;
}

// 希尔排序
void ShellSort(RecType R[], int n)
{
    int i, j, gap;
    gap = n/2;
    RecType temp;//增量置初值
    while(gap > 0)
    {
        // 对每一组进行插入排序
        for(int i = gap; i < n; i++)
        {
            temp = R[i];
            j = i-gap;
            while(j>=0 && temp.key<R[i].key)
            {
                R[j+gap] = R[j];
                j=j-gap;
            }
            R[j+gap]=temp;
            j = j-gap;
        }
        gap=gap/2;//减小增量
    }
}

// 插入排序
void InsertSort(RecType R[], int n)
{
    int i,j;
    RecType temp;
    for(int i = 1; i < n; i++)
    {
        j = i-1;
        temp = R[i];
        while((j >= 0)&&(R[j].key > temp.key))
        {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = temp;
    }
}

// 冒泡排序
void BubbleSort(RecType R[], int n)
{
    bool exchange;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = n-1; j > i; j--)
        {
            exchange = false;
            if(R[j].key < R[j-1].key)
            {
                swap(R[j],R[j-1]);
                exchange = true;
            }
        }
        if(exchange == false)//未发生交换，直接返回
        {
            return;
        }
    }
}

// 快速排序
void QuickSort(RecType R[], int s, int t)
{
    KeyType i = s, j = t;
    RecType temp = R[s];
    printf("%d %d\n", s,t);
    if(s < t)
    {
        while(i < j)
        {
            while((j>i)&&(R[j].key >= temp.key))
            {
                j--;
            }
            R[i] = R[j];
            while((i<j)&&(R[i].key <= temp.key))
            {
                i++;
            }
            R[j] = R[i];
            printf("%d %d\n",i,j);
            printf("%d %d\n",R[i].key,R[j].key);
        }
        R[j] = temp;
        QuickSort(R,s,j-1);
        QuickSort(R,j+1,t);
    }
}

// 直接选择排序
void SelectSort(RecType R[], int n)
{
    KeyType min = 32768;
    int k = -1;
    for (int i = 0; i < n-1; ++i)
    {
        /* code */
        for(int j = i; j < n; ++j)
        {
            if(min > R[j].key)
            {
                min = R[j].key;
                k = j;
            }
        }
        if(k != -1)
        {
            swap(R[i], R[k]);
            k = -1;
            min = 32768;
        }
    }
}

int main()
{
    int n = 10;
    RecType R[MaxSize];
    KeyType a[] = {0,8,7,2,9,6,5,1,3,4};
    //KeyType a[] = {5,6,4,3,5};
    for (int i = 0; i < n; ++i)
    {
        R[i].key  = a[i];
        printf("%d ", R[i].key);
    }
    putchar('\n');
    //BubbleSort(R,10);
    //QuickSort(R,0,n-1);
    SelectSort(R,n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", R[i].key);
    }
    putchar('\n');
    return 0;
}