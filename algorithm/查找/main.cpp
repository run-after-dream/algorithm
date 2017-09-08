#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct{
    int data;
}ElemType;

typedef struct{
    ElemType value;
    int key;
}SeqType;

// 二叉排序树的存储结构
typedef struct node{
    int data;
    int key;
    struct node *lchild, *rchild;
}BSTNode;

// 二分查找
int BinSearch(SeqType *R, int begin, int end, int k)
{
    int mid = 0;
    if(begin <= end)
    {
        mid = (begin+end)/2;
        if(R[mid].key == k)
        {
            return mid;
        }
        if(R[mid].key > k)
        {
            return BinSearch(R, begin, mid-1, k);
        }
        else
        {
            return BinSearch(R, mid+1, end, k);
        }
    }
    else
    {
        return -1;
    }
}

// 二叉排序树上的查找
BSTNode *SearchBST(BSTNode *bt, int k)
{
    if(bt==NULL || bt->key==k)
    {
        return bt;
    }
    if(k < bt->key)
    {
        return SearchBST(bt->lchild,k);
    }
    else
    {
        return SearchBST(bt->rchild,k);
    }
}

int InsertBST(BSTNode *&p, int k)
{
    if(p == NULL)
    {
        p = (BSTNode*)malloc(sizeof(BSTNode));
        p->key = k;
        p->lchild = NULL;
        p->rchild = NULL;
    }
    else
    {
        if(k == p->key)
        {
            return 0;
        }
        if(k > p->key)
        {
            return InsertBST(p->rchild, k);
        }
        else
        {
            return InsertBST(p->lchild, k);
        }
    }
    return 1;
}

BSTNode *CreateBST(int *a, int num)
{
    BSTNode *b = NULL;
    for(int i = 0; i < num; i++)
    {
        InsertBST(b, a[i]);
    }
    return b;
}

void DispBST(BSTNode *b)
{
    if(b == NULL)
    {
        return;
    }
    else
    {
        DispBST(b->lchild);
        printf("%d ", b->key);
        DispBST(b->rchild);
    }
}

// 删除节点——删除叶子节点或双叶子节点
void Delete1(BSTNode *&bt)
{
    BSTNode *p = bt;
    BSTNode *q = NULL;
    while(p->rchild != NULL)
    {
        p = p->rchild;
    }
    bt->key = p->key;
    bt->data = p->data;
    q = p;
    p = p->lchild;
    free(q);
}

// 删除节点——删除叶子节点或单叶子节点
void Delete(BSTNode *&bt)
{
    BSTNode*q = NULL;
    if(bt->lchild == NULL)
    {
        q = bt;
        bt = bt->rchild;
        free(q);
    }
    else
    {
        if(bt->rchild == NULL)
        {
            q = bt;
            bt = bt->lchild;
            free(q);
        }
        else
        {
            Delete1(bt);
            return;
        }
    }
}

// 删除节点——寻找待删除的节点
int DeleteBST(BSTNode *&bt,int k)
{
    if(bt == NULL)
    {
        return 0;
    }
    if(k == bt->key)
    {
        Delete(bt);
        return 1;
    }
    if(k < bt->key)
    {
        return DeleteBST(bt->lchild,k);
    }
    else
    {
        return DeleteBST(bt->rchild,k);
    }
}

int main()
{
    SeqType R[MaxSize] = {0};
    int num = 0;
    int a[] = {15,12,56,23,46,11,7};
    BSTNode *b;
    b = CreateBST(a, (sizeof(a)/sizeof(a[0])));
    DispBST(b);
    putchar('\n');
    DeleteBST(b,56);
    DispBST(b);
    putchar('\n');
    return 0;
}