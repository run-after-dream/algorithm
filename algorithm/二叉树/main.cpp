#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode;

// 创建二叉树
void CreateBTNode(BTNode *&b, ElemType *str)
{
    ElemType ch;
    BTNode *p = NULL;
    BTNode *st[MaxSize];
    b = NULL;
    int k = 0;
    int top = -1;
    int j = 0;
    while((ch = str[j]) != '\0')
    {
        switch(ch)
        {
            case '(':
                top++;
                st[top] = p;//双亲节点入栈
                k = 1;//左子节点标记位
                break;
            case ',':
                k = 2;//右子节点标记位
                break;
            case ')':
                top--;
                break;
            default:
                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if(b == NULL)//栈顶元素
                {
                    b = p;
                }
                else//栈中元素
                {
                    switch (k)
                    {
                        case 1:
                            st[top]->lchild = p;
                            break;
                        case 2:
                            st[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
    }
}

// 查找节点
BTNode *FindNode(BTNode *b, ElemType x)
{
    BTNode *ch;
    if(b == NULL)
    {
        return NULL;
    }
    else if(b->data == x)
    {
        return b;
    }
    else
    {
        ch = FindNode(b->lchild, x);
        if(ch != NULL)
        {
            return ch;
        }
        else
        {
            return FindNode(b->rchild, x);
        }
    }
}

// 获取二叉树的深度
int BTNodeDepth(BTNode *b)
{
    int depth = 1;
    if(b == NULL)
    {
        return 0;
    }
    else
    {
        if(BTNodeDepth(b->lchild) > BTNodeDepth(b->rchild))
        {
            depth += BTNodeDepth(b->lchild);
        }
        else
        {
            depth += BTNodeDepth(b->rchild);
        }
        return depth;
    }
}

// 用括弧法显示二叉树
void DispBTNode(BTNode *b)
{
    if(b != NULL)
    {
        printf("%c",b->data);
    }
    if((b->lchild != NULL)||(b->rchild != NULL))
    {
        printf("(");
        if(b->lchild != NULL)
        {
            DispBTNode(b->lchild);
        }
        if(b->rchild != NULL)
        {
            printf(",");
            DispBTNode(b->rchild);
        }
        printf(")");
    }
}

// 先序遍历
void preOrder(BTNode *b)
{
    if(b != NULL)
    {
        printf("%c",b->data);
        preOrder(b->lchild);
        preOrder(b->rchild);
    }
}

// 中序遍历
void midOrder(BTNode *b)
{
    if(b != NULL)
    {
        midOrder(b->lchild);
        printf("%c",b->data);
        midOrder(b->rchild);
    }
}

// 后序遍历
void afterOrder(BTNode *b)
{
    if(b != NULL)
    {
        afterOrder(b->lchild);
        afterOrder(b->rchild);
        printf("%c",b->data);
    }
}

// 计算二叉树中节点的个数
int count(BTNode *b)
{
    int num = 0;
    if(b != NULL)
    {
        num++;
        num += count(b->lchild);
        num += count(b->rchild);
    }
    return num;
}

// 遍历所有的叶子节点
void DispLeafNode(BTNode *b)
{
    if(b != NULL)
    {
        if((b->lchild == NULL)&&(b->rchild == NULL))
        {
            printf("%c ",b->data);
            return;
        }
        else
        {
            DispLeafNode(b->lchild);
            DispLeafNode(b->rchild);
        }
    }
    else
    {
        return;
    }
}

// 计算节点在二叉树中的层次
int Level(BTNode *b, ElemType x, int h)
{
    if(b == NULL)
    {
        return 0;
    }
    else if(b->data == x)
    {
        return h;
    }
    else
    {
        if(Level(b->lchild,x,h+1))
        {
            return Level(b->lchild,x,h+1);
        }
        else
        {
            return Level(b->rchild,x,h+1);
        }
    }
}

// 相似二叉树判断
bool similiar(BTNode *b1, BTNode *b2)
{
    bool left = false;
    bool right = false;
    if((b1==NULL)&&(b2==NULL))
    {
        return true;
    }
    else
    {
        if((b1!=NULL)&&(b2!=NULL))
        {
            if(similiar(b1->lchild,b2->lchild))
            {
                left = true;
            }
            if(similiar(b1->rchild,b2->rchild))
            {
                right = true;
            }
            if(left && right)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

// 先序遍历非递归算法
void preOrder1(BTNode *b)
{
    BTNode *st[MaxSize],*p;
    int top = -1;
    top++;
    st[top] = b;//根节点入栈
    while(top>-1)//栈不为空时循环
    {
        p = st[top];//栈顶元素出栈,并访问该元素
        top--;
        printf("%c ",p->data);
        if(p->rchild != NULL)//右孩子节点入栈（把握好后入先出的规则）
        {
            top++;
            st[top] = p->rchild;
        }
        if(p->lchild != NULL)//左孩子节点入栈
        {
            top++;
            st[top] = p->lchild;
        }
    }
}

// 层次遍历，队列方式实现
void LevelOrder(BTNode *b)
{
    BTNode *p;
    BTNode *qu[MaxSize];
    int front,rear;
    front = rear = -1;//环形队列
    rear++;//根节点入队
    qu[rear] = b;
    while(front != rear)
    {
        front++;
        p = qu[front];
        printf("%c ",p->data);
        if(p->lchild != NULL)
        {
            rear = (rear+1)%MaxSize;
            qu[rear] = p->lchild;
        }
        if(p->rchild != NULL)
        {
            rear = (rear+1)%MaxSize;
            qu[rear] = p->rchild;
        }
    }
}

// 路径之逆，采用层次遍历+队列；
void reverseLink(BTNode *b)
{
    typedef struct NodeNew{
        BTNode* pst;
        int front;
    }BTNodeNew;

    BTNodeNew st[MaxSize], p;
    int rear, stave;
    rear = -1;
    rear++;
    st[rear].pst = b;
    st[rear].front = -1;
    p = st[rear];
    stave = rear;

    // 层次遍历，入队
    while((p.pst->lchild!=NULL)||(p.pst->rchild!=NULL))
    {
        if(p.pst->lchild!=NULL)
        {
            rear++;
            st[rear].pst = p.pst->lchild;
            st[rear].front = stave;
        }
        if(p.pst->rchild!=NULL)
        {
            rear++;
            st[rear].pst = p.pst->rchild;
            st[rear].front = stave;
        }
        stave++;
        p = st[stave];
    }

    for(int i = st[rear].front+1; i <= rear; i++)
    {
        int j = i;
        printf("%c ", st[j].pst->data);
        do{
            j = st[j].front;
            printf("%c ", st[j].pst->data);
        }while(st[j].front != -1);
        putchar('\n');
    }

}

int main()
{
    char a[] = "A(B(D(,G)),C(E,F))";
    char a2[] = "A(B(D),C(E,F))";
    BTNode *b = NULL;
    BTNode *b2 = NULL;
    BTNode *get = NULL;
    int depth = 0;
    int level = 0;
    CreateBTNode(b,a);
    CreateBTNode(b2,a2);
    get = FindNode(b,'G');
    if(get != NULL)
    {
        printf("%c\n",get->data);
    }
    // 获取二叉树的深度
    depth = BTNodeDepth(b);
    printf("depth = %d\n",depth);
    // 遍历所有的叶子节点
    DispBTNode(b);
    putchar('\n');//由于函数中没有加回车，所以此处需要额外加上回车
    // 前序递归遍历
    preOrder(b);
    putchar('\n');
    // 中序递归遍历
    midOrder(b);
    putchar('\n');
    // 后序递归遍历
    afterOrder(b);
    putchar('\n');
    // 结点计数
    printf("%d\n",count(b));
    // 显示所有的叶子结点
    DispLeafNode(b);
    putchar('\n');
    level = Level(b,'G',1);
    // 确定对应元素所在的层
    printf("%d",level);
    putchar('\n');
    // 判断两个树是否相似
    if(similiar(b,b2))
    {
        printf("they are similiar!");
    }
    // 前序非递归遍历:
    preOrder1(b);
    putchar('\n');
    // 层次遍历，队列方式实现
    LevelOrder(b);
    putchar('\n');
    //层次遍历，用队列实现路径之逆
    reverseLink(b);

    return 0;
}