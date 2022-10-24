#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现offsetof
//struct mm
//{
//	char a;
//	int b;
//	char c;
//	double d;
//};
//#define OFFSETOF(struct_name,num) (size_t)&(((struct_name*)0)->num)
//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	printf("%d\n", offsetof(struct mm , a));
//	printf("%d\n", offsetof(struct mm, b));
//	printf("%d\n", offsetof(struct mm , c));
//	printf("%d\n", offsetof(struct mm, d));
//	printf("%d\n", OFFSETOF(struct mm, a));
//	printf("%d\n", OFFSETOF(struct mm, b));
//	printf("%d\n", OFFSETOF(struct mm, c));
//	printf("%d\n", OFFSETOF(struct mm, d));
//	return 0;
//}

//青蛙跳台阶

//int wa(int n)
//{
//    if (n < 2)
//        return 1;
//    int MOD = 1000000007;
//    int i, front = 1, mid = 1, rear = 1;
//    for (i = 2; i <= n; i++) {
//        front = mid;
//        mid = rear;
//        rear = (front + mid) % MOD;
//    }
//    return rear;
//}
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    while (scanf("%d", &i) != EOF)
//    {
//        printf("\n%d\n", wa(i));
//    }
//    return 0;
//}

//      旋转后的1/2查找
//int minArray(int* numbers, int numbersSize) {
//     方法一 暴力遍历 时间O(n),空间O(1)
//     int i = 0;
//     int small = numbers[0];
//     for(i = 1 ; i < numbersSize ; i++)
//     {
//         if(small > numbers[i])
//           small = numbers[i];
//     }
//     return small;
//    int low, mid, high;
//    low = 0, high = numbersSize - 1;
//    while (low <= high)
//    {
//        mid = (low + high) / 2;
//       if (numbers[mid] < numbers[high])
//            high = mid;
//        else if (numbers[mid] > numbers[high])
//            low = mid + 1;
//        else
//            high--;
//    }
//    return numbers[mid];
//}
//#include<stdio.h>
//int main()
//{
//    int arr[] = { 4,5,6,7,8,9,1,2,3 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    printf("%d\n", minArray(arr, size));
//    return 0;
//}

//

#include<stdio.h>
int main()
{
    char s[100] = "We are happy. aba hahd jshah bin";
    //    int coent = 0;//空格数量
    //int i = 0;//循环辅助
    //int j = 0;//加%20之前的指针位移
    //for (i = 0; s[i] != '\0'; i++)
    //{
    //    if (s[i] == ' ')
    //        coent++;
    //}
    //j = i + coent * 2;
    //while (coent)
    //{
    //    if (s[i] != ' ')
    //        s[j--] = s[i--];
    //    else
    //    {
    //        s[j--] = '0';
    //        i--;
    //        s[j--] = '2';
    //        s[j--] = '%';
    //        coent--;
    //    }
    //}
    //printf("%s\n", s);
    //return 0;
    
}