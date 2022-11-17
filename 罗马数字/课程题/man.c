#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h" 
#include "string.h" 
//void fun(float* sn, int n)
//{
//    float s = 0.0, w, f = -1.0;
//    int i = 0;
//    for (i = 0; i <= n; i++)
//    {
//        f = -1 * f;
//        w = f / (2 * i + 1);
//        s += w;
//    }
//    *sn = s;
//}
//int main()
//{
//    int n = 5 ; 
//    float b = 0;
//    float* PP = &b;
//    fun(PP, n);
//    printf("%f\n", *PP);
//    return 0;
//}

//char* strc(char* s1, char* s2)
//{
//	char* p = s1;
//	while (*s2 != '\0')
//	{
//		*p++ = *s2++;
//	}
//	return s1;
//}
//void main()
//{
//	char s1[30] = "computer ok!", s2[] = "language", * pt;
//	pt = strc(s1, s2);
//	printf("%s\n", pt);
//}
//#include "stdio.h" 
//main()
//{
//    char a[4][5] = { "ABCD","EFGH","IJKL","MNOP" };
//    char(*p)[5];
//    int i, j;
//    p = a;
//    for (i = 0; i < 4; i++)
//    {
//        printf("%s", *(p + i)); /* 第 9 行 */
//        printf("\n");
//    }
//}


//char* my_strcat(char* s1, const char* s2)//注意返回值是char*
//{
//	char* pp = s1;//用pp加加，s1保留首地址
//	while (*pp)//解引用得到目前pp指向的值，如果是'\0'说明是最后一位。
//	{          // '\0'的ASCII值是0(为假)，会自动跳出循环
//		pp++;//pp指向地址加1（指向下一个地址）
//	}
//	while (*pp = *s2)//将s2的值赋值给*pp(也就是s1地址的内容)
//	{
//		pp++;//pp指向下一个地址
//		s2++;//s2指向下一个地址
//	}
//	return s1;//返回s1首地址
//}
//int main()
//{
//	char s1[100] = { 0 };//s1开大一点，因为s2的内容会填到s1中。太小会导致越界
//	char s2[50] = { 0 };
//	printf("请输入s1:\n");
//	scanf("%s", s1);
//	printf("请输入s2:\n");
//	scanf("%s", s1);
//	printf("s1:%s", my_strcat(s1, s2));//函数返回值为s1首地址所以可以直接打印
//	return 0;
//}
char* my_strcat(char* s1, const char* s2)
{
	char* pp = s1;
	while (*pp)
	{
		pp++;
	}//找pp'\0'
	while (*pp++ = *s2++);  //将s2的值赋值给*pp(也就是s1地址的内容)
	return s1;              //返回s1首地址
}
int main()
{
	char s1[100] = { 0};//s1开大一点，因为s2的内容会填到s1中。太小会导致越界
	char s2[50] = { 0 };
	printf("请输入s1:\n");
	scanf("%s", s1);
	printf("请输入s2:\n");
	scanf("%s", s2);
	printf("s1:%s", my_strcat(s1, s2));//函数返回值为s1首地址所以可以直接打印
	return 0;
}

