#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
#include"QL.h"
void TestOP()
{
	srand(time(NULL));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	if (!a1)
	{
		return;
	}
	int* a2 = (int*)malloc(sizeof(int) * N);
	if (!a2)
	{
		return;
	}
	int* a3 = (int*)malloc(sizeof(int) * N);
	if (!a3)
	{
		return;
	}
	//int* a4 = (int*)malloc(sizeof(int) * N);
	//int* a5 = (int*)malloc(sizeof(int) * N);
	//int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand()+i ;
		a2[i] = a1[i];
		a3[i] = a1[i];
		//a4[i] = a1[i];
		//a5[i] = a1[i];
		//a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	 TreeCreate(a3, N);
	int end3 = clock();
	int begin4 = clock();
	//HeapSort(a4, N);
	//int end4 = clock();
	//int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	//int end5 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();*/
	printf("InsertSort:%d\n", end1 - begin1);//µ¥Î»ºÁÃë
	printf("ShellSort:%d\n", end2 - begin2);
	printf("TreeCreate:%d\n", end3 - begin3);
	//printf("HeapSort:%d\n", end4 - begin4);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);*/
	free(a1);
	free(a2);
	free(a3);
	/*free(a4);
	free(a5);
	free(a6);*/
}