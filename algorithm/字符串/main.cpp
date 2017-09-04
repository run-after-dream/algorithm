#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct
{
    char data[MaxSize];
    int length;
} sqString;

// 串赋值，将字符串cstr中的值赋值给s
void StrAssign(sqString &s, char cstr[])
{
    int i;
    for(i = 0; cstr[i] != '\0'; i++)
    {
        s.data[i] = cstr[i];
    }
    s.length = i;
}

// 串复制，将t串赋值给s串
void StrCopy(sqString &s, sqString t)
{
    int i;
    for(i = 0; i < t.length; i++)
    {
        s.data[i] = t.data[i];
    }
    s.length = t.length;
    s.data[s.length] = '\0';//最后一位字符要手动赋值为\0
}

// 串连接，将串s和t拼接在一起，并返回。
sqString StrConcat(sqString s, sqString t)
{
    sqString str;
    int i = 0;
    int j = 0;
    str.length = s.length + t.length;
    for (i = 0; i < s.length; ++i)
    {
        str.data[j] = s.data[i];
        ++j;
    }
    for (i = 0; i < t.length; ++i)
    {
        str.data[j] = t.data[i];
        ++j;
    }
    str.data[j] = '\0';
    return str;
}

int main()
{
    sqString *p = (sqString *)malloc(sizeof(sqString));
    sqString *p2 = (sqString *)malloc(sizeof(sqString));
    char str[] = "hello world";
    char a[5] = {0};
    printf("%d\n", sizeof(a));
    StrAssign(*p, str);
    StrCopy(*p2,*p);
    printf("%s\n", p->data);
    printf("%s\n", p2->data);
    sqString s3 = StrConcat(*p2, *p);
    printf("%s\n", s3.data);
    printf("%d\n", s3.length);
    return 0;
}