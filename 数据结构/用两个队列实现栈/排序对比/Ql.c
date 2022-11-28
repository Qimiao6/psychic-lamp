#define _CRT_SECURE_NO_WARNINGS 1
#include"QL.h"

void SLInit(Node* Pteam)
{
	assert(Pteam);
	Pteam->Front = NULL;
	Pteam->Tail = NULL;
	Pteam->size = 0;
}
void SLPush(Node* Pteam, TeDataType* x)
{
	assert(Pteam);
	Team* cur = (Team*)malloc(sizeof(Team));
	if (NULL == cur)
	{
		printf("malloc\n");
		exit(-1);
	}
	cur->data = x;
	cur->next = NULL;
	if (Pteam->Front == NULL)
	{
		Pteam->Front = cur;
		Pteam->Tail = cur;
	}
	else
	{
		Pteam->Tail->next = cur;
		Pteam->Tail = cur;
	}
	Pteam->size++;
}
bool SLEmpty(Node* Pteam)
{
	assert(Pteam);

	return Pteam->size == 0;
}
void SLPop(Node* Pteam)
{
	assert(Pteam);
	assert(!SLEmpty(Pteam));
	Team* cur = Pteam->Front->next;
	free(Pteam->Front);
	Pteam->Front = cur;
	if (NULL == cur)
	{
		Pteam->Tail = NULL;
	}
	Pteam->size--;
}
TeDataType* SLFront(Node* Pteam)
{
	assert(Pteam);
	assert(!SLEmpty(Pteam));
	return Pteam->Front->data;
}
TeDataType* SLTail(Node* Pteam)
{
	assert(Pteam);
	assert(!SLEmpty(Pteam));
	return Pteam->Tail->data;
}
void SLDestroy(Node* Pteam)
{
	assert(Pteam);
	while (Pteam->Front)
	{
		Team* cur = Pteam->Front->next;
		free(Pteam->Front);
		Pteam->Front = cur;
	}
}
int SLsize(Node* Pteam)
{
	assert(Pteam);

	return Pteam->size;
}