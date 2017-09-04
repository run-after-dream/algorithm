#include <stdio.h>

int main()
{
    int k = 0;
    int a[100] = {0};
    int len = 0;//数组长度
    char c = 0;//获取一个回车符
    int temp = 0;
    int max_k = 0;//第K大的数
    // 输入一组数，以回车结尾
    while(1)
    {
        scanf("%d",&a[len++]);
        c = getchar();
        if(c == '\n')
        {
            break;
        }
    }

    scanf("%d",&k);

    for(int i = len-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    max_k = a[len-k];
    printf("max_k = %d\n", max_k);

    return 0;
}