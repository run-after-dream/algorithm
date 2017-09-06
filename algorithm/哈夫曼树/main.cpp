#include <stdio.h>
#include <stdlib.h>

#define N 5
typedef struct{
    int data;
    float weight;
    int parent;
    int lchild;
    int rchild;
}HTNode;

// 构造哈夫曼树
void createHT(HTNode array[], int n)
{
    int min1, min2, lnode, rnode, length;
    min1 = min2 = 32768;
    length = n;
    //构造表
    while(length < 2*N-1)
    {
        for(int i = 0; i < length; i++)
        {
            if(array[i].parent == -1)//对叶子节点进行操作
            {
                if(array[i].weight < min1)
                {
                    min1 = array[i].weight;
                    lnode = i;
                }
            }
        }
        array[length].lchild = lnode;
        array[lnode].parent = length;
        for(int i = 0; i < length; i++)
        {
            if(array[i].parent == -1)//对叶子节点进行操作
            {
                if(array[i].weight < min2)
                {
                    min2 = array[i].weight;
                    rnode = i;
                }
            }
        }
        array[length].rchild = rnode;
        array[rnode].parent = length;
        array[length].weight = min1 + min2;
        min1 = min2 = 32768;
        length++;
    }
}

int main()
{
    HTNode array[2*N-1];
    for(int i = 0; i < (2*N-1); i++){
        array[i].parent = -1;
        array[i].lchild = -1;
        array[i].rchild = -1;
    }
    array[0].weight = 2;
    array[1].weight = 9;
    array[2].weight = 7;
    array[3].weight = 4;
    array[4].weight = 5;
    createHT(array,N);
    for(int i = 0; i < 2*N-1; i++){
        printf("%f %d %d %d\n", array[i].weight, array[i].parent, array[i].lchild, array[i].rchild);
    }


    return 0;
}