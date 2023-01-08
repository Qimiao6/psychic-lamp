#define _CRT_SECURE_NO_WARNINGS 1
#include"Front.h"
#include<iostream>
//命名空间
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
		using binbin::bb;//依然遵循局部优先都原则
		cout << bb << endl;
	}
}
void test2()
{
	//printf("dsdjf\n");//不用声明命名空间直接可以打印，
					//说明printf函数不在命名空间中，在iostream的全局作用域
	namespace dbx = binbin;//可以给命名空间起别名
	//std::cout << dbx::bb << std::endl;
	dbx::bb++;//等同binbin::bb++
	using binbin::bb;
	using namespace std;
	cout << bb << endl;//说明可以起别名
}
void test3()
{
	using namespace std;
	using namespace n1;
	head pp = { "猪猪\n" };
	cout << pp.data << endl;
	n2::tail kk = { "狗狗\n" };//命名空间可嵌套
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
	int& a11 = a1;//别名还可起别名功能一样
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
	//命名空间
	//test1();
	//test2();
	//test3();
	//test4();
	//缺省参数
	using namespace std;
	//cout << add(1) << endl;
	////函数重载
	//cout << cul(1,3) << endl;
	//cout << cul(1,2,-5) << endl;
	//cout << cul(1.3 , 3 , -5) << endl;
	//引用
	test5();
	return 0;
}