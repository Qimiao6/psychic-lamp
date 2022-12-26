#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	SList* Phead = NULL;//Phead等于空时说明链表为空
	STLPusList(&Phead, 11);
	STLPusList(&Phead, 12);
	STLPusList(&Phead, 13);
	STLPusList(&Phead, 14);
	STLPusList(&Phead, 15);
	pushead(&Phead, 100);
	STLPosList(&Phead);
	STLPosList(&Phead);
	STLPosList(&Phead);
	STLPosList(&Phead);
	STLPosList(&Phead);
	STLPosList(&Phead);

	return 0;
}