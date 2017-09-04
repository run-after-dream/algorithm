#include <stdio.h>

int main()
{
    int value = 0;
    int a[100] = {0};
    int sum[100][100] = {0};
    int max = 0;
    int max_i = 0;
    int max_j = 0;
    int len = 0;
    char c = 0;
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

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            for(int k = i; k <= j; k++)
            {
                sum[i][j] += a[k];
            }
            if(sum[i][j] > max)
            {
                max = sum[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("the max is %d to %d, its value is %d \n", max_i, max_j, max);

    return 0;
}