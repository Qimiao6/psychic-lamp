#define _CRT_SECURE_NO_WARNINGS 1
#include"Front.h"
#include<iostream>
//�����ռ�
void test1()
{
	using namespace std;
	//cout << zgb::bb << endl;
	//cout << binbin::bb << endl;
	using namespace zgb;
	//cout << bb << endl;
	//cout << binbin::bb << endl;
	if (1)
	{
		using binbin::bb;//��Ȼ��ѭ�ֲ����ȶ�ԭ��
		cout << bb << endl;
	}
}
void test2()
{
	//printf("dsdjf\n");//�������������ռ�ֱ�ӿ��Դ�ӡ��
					//˵��printf�������������ռ��У���iostream��ȫ��������
	namespace dbx = binbin;//���Ը������ռ������
	//std::cout << dbx::bb << std::endl;
	dbx::bb++;//��ͬbinbin::bb++
	using binbin::bb;
	using namespace std;
	cout << bb << endl;//˵�����������
}
void test3()
{
	using namespace std;
	using namespace n1;
	head pp = { "����\n" };
	cout << pp.data << endl;
	n2::tail kk = { "����\n" };//�����ռ��Ƕ��
	cout << kk.n2data << endl;
}
void test4()
{
	;
}
int add(int x , int y = 20 ,int z = 10)
{
	return x + y + z;
}
int cul(int x, int y)
{
	return x - y;
}
int cul(int x, int y,int j)
{
	return x - y-j;
}
double cul(double x, int y, int j)
{
	return x - y - j;
}
void test6(int& b1)
{
	b1++;

}
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
void test5()
{
	int a = 10;
	int& a1 = a;
	a1++;
	int& a11 = a1;//�����������������һ��
	a11++;
	using namespace std;
	//cout << a << endl;
	int b = 0;
	test6(b);
	//cout << b << endl;
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;

}
int main()
{
	//�����ռ�
	//test1();
	//test2();
	//test3();
	//test4();
	//ȱʡ����
	using namespace std;
	//cout << add(1) << endl;
	////��������
	//cout << cul(1,3) << endl;
	//cout << cul(1,2,-5) << endl;
	//cout << cul(1.3 , 3 , -5) << endl;
	//����
	test5();
	return 0;
}