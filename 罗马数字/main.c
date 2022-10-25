#define _CRT_SECURE_NO_WARNINGS 1
#ifdef _bb_
Öî¸ð±ó
#endif
#include<stdio.h>
int main()
{
    char s[100] = { 0 };
    scanf("%s", &s);
int len = strlen(s);
int max = 0;
int i = 0;//±éÀú
while (i < len)
{
    switch (s[i])
    {
    case 'I':
        s[i] = 1;
        break;
    case 'V':
        s[i] = 5;
        break;
    case 'X':
        s[i] = 10;
        break;
    case 'L':
        s[i] = 50;
        break;
    case 'C':
        s[i] = 100;
        break;
    case 'D':
        s[i] = 500;
        break;
    case 'M':
        s[i] = 1000;
        break;
    }
    i++;
}
i = 0;
while (i < len - 1)
{
    if (s[i] >= s[i + 1])
        max += s[i];
    else
    {
        max -= s[i];
    }
    i++;
}
printf("%d\n", max += s[i]);
return 0;
}