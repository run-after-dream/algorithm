#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Element
{
    int data[MAX];
    int length;
}MyElement;
// 初始化线性表
void InitElement(MyElement *&L)
{
    L = (MyElement *)malloc(sizeof(MyElement));
    L->length = 0;
}
// 销毁线性表
void DestroyList(MyElement *&L)
{
    free(L);
    L = NULL;
}
// 返回线性表长度
int ListLength(MyElement *L)
{
    return(L->length);
}
// 判断线性表是否为空
bool ListEmpty(MyElement *L)
{
    if(L->length > 0)
    {
        return true;
    }
    return false;
}
// 显示线性表的内容
void DispList(MyElement *L)
{
    int i;
    if(!(ListEmpty(L)))
    {
        printf("DispList return\n");
        return;
    }
    for(i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
// 插入数据元素,i为位置，e为待插入元素
bool ListAdd(MyElement *&L, int i, int &e)
{
    if((i < 0) || (i > L->length))
    {
        return false;
    }
    else
    {
        for(int j = L->length; j > i; j--)
        {
            L->data[j] = L->data[j-1];
        }
        L->data[i] = e;
        L->length++;
        return true;
    }
}
// 删除一个数据
bool ListDelete(MyElement *&L, int i, int &e)
{
    if((i < 0) || (i >= L->length))
    {
        return false;
    }
    else
    {
        e = L->data[i];
        for(int j = i; j < (L->length-1); j++)
        {
            L->data[j] = L->data[j+1];
        }
        L->length--;
        return true;
    }
}

// 删除所有值为x的元素


int main()
{
    MyElement *p;
    int length = 0;
    int element;
    InitElement(p);
    // 插入10个数
    for(int i = 0; i < 10; i++)
    {
        ListAdd(p, i, i);
    }
    printf("%d\n",p->length);
    DispList(p);
    ListDelete(p,2,element);
    printf("%d\n",element);
    DispList(p);
    return 0;
}