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
//        printf("%s", *(p + i)); /* �� 9 �� */
//        printf("\n");
//    }
//}


//char* my_strcat(char* s1, const char* s2)//ע�ⷵ��ֵ��char*
//{
//	char* pp = s1;//��pp�Ӽӣ�s1�����׵�ַ
//	while (*pp)//�����õõ�Ŀǰppָ���ֵ�������'\0'˵�������һλ��
//	{          // '\0'��ASCIIֵ��0(Ϊ��)�����Զ�����ѭ��
//		pp++;//ppָ���ַ��1��ָ����һ����ַ��
//	}
//	while (*pp = *s2)//��s2��ֵ��ֵ��*pp(Ҳ����s1��ַ������)
//	{
//		pp++;//ppָ����һ����ַ
//		s2++;//s2ָ����һ����ַ
//	}
//	return s1;//����s1�׵�ַ
//}
//int main()
//{
//	char s1[100] = { 0 };//s1����һ�㣬��Ϊs2�����ݻ��s1�С�̫С�ᵼ��Խ��
//	char s2[50] = { 0 };
//	printf("������s1:\n");
//	scanf("%s", s1);
//	printf("������s2:\n");
//	scanf("%s", s1);
//	printf("s1:%s", my_strcat(s1, s2));//��������ֵΪs1�׵�ַ���Կ���ֱ�Ӵ�ӡ
//	return 0;
//}
char* my_strcat(char* s1, const char* s2)
{
	char* pp = s1;
	while (*pp)
	{
		pp++;
	}//��pp'\0'
	while (*pp++ = *s2++);  //��s2��ֵ��ֵ��*pp(Ҳ����s1��ַ������)
	return s1;              //����s1�׵�ַ
}
int main()
{
	char s1[100] = { 0};//s1����һ�㣬��Ϊs2�����ݻ��s1�С�̫С�ᵼ��Խ��
	char s2[50] = { 0 };
	printf("������s1:\n");
	scanf("%s", s1);
	printf("������s2:\n");
	scanf("%s", s2);
	printf("s1:%s", my_strcat(s1, s2));//��������ֵΪs1�׵�ַ���Կ���ֱ�Ӵ�ӡ
	return 0;
}

