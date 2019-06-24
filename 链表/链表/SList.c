#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"


// ����ĳ�ʼ�� 
void SListInit(SList* s) {
	assert(s);
	s->_pHead = NULL;
}
//�����µĽڵ�
PNode BuySListNode(SDataType data) {
	PNode pNewNode = (PNode)malloc(sizeof(Node));

	if (NULL == pNewNode) {
		assert(0);
		return;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

// ������s���һ���ڵ�����ֵΪdata�Ľڵ� 
void SListPushBack(SList* s, SDataType data) {
	assert(s);
	PNode pNewNode = BuySListNode(data);//����һ���µĽڵ�
	if (NULL == s->_pHead) {
		s->_pHead = pNewNode;//�������Ϊ��,����ͷ�ڵ�ָ���½����Ľڵ�
	}
	else
	{
		PNode pCur = s->_pHead;//����һ����������Ѱ��
		while (pCur->_pNext) {
			pCur = pCur->_pNext;//�������һ���ڵ�Ϊ��ʱͣ��
		}
		pCur->_pNext = pNewNode;
	}
}

// ɾ������s���һ���ڵ� 
void SListPopBack(SList* s) {
	assert(s);
	PNode pCur = s->_pHead;
	if (pCur == NULL) {
		return;
	}
	if (pCur->_pNext ==NULL) {
		free(pCur);
		s->_pHead = NULL;
		return;
	}
	while (pCur->_pNext->_pNext) {
		pCur = pCur->_pNext;//Ѱ������һ��Ԫ��
	}
	free(pCur->_pNext);//ɾ��ָ����轫���ÿ�
	pCur->_pNext = NULL;
}

// ������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* s, SDataType data) {
	assert(s);
	///*if (s->_pHead == NULL) {
	//	SListPushBack(s, data);
	//}
	//else
	//{
	//	PNode pNewNode = BuySListNode(data);
	//	pNewNode->_pNext = s->_pHead;
	//	s->_pHead->_pNext = pNewNode;
	//}*/
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(SList* s) {
	assert(s);
	if (NULL == s->_pHead) {
		return;
	}
	PNode pDelNode = s->_pHead;
	s->_pHead = s->_pHead->_pNext;
	free(pDelNode);
}

// �������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsert(PNode pos, SDataType data) {
	if (pos == NULL) {
		return;
	}
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

// ɾ������s��posλ�õĽڵ� 
void SListErase(SList* s, PNode pos) {
	assert(s);
	if (NULL == pos || NULL == s->_pHead) {
		return;
	}
	if (pos == s->_pHead) {
		s->_pHead = s->_pHead->_pNext;
	}
	else
	{
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext!=pos) 
			pPrePos = pPrePos->_pNext;
		if (pPrePos)
			pPrePos->_pNext = pPrePos->_pNext->_pNext;
	}
	free(pos);
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(SList* s, SDataType data) {
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur) {
		//pCur = pCur->_pNext;
		//����ʱ����ÿ��Ԫ�ض���������,����˳���Ǻ�
		if (data == pCur->_data) {
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

// ��ȡ��������Ч�ڵ�ĸ��� 
size_t SListSize(SList* s) {
	assert(s);
	size_t count = 0;
	PNode pCur = s->_pHead;
	while (pCur) {
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* s) {
	assert(s);
	return NULL == s->_pHead;
}

// ����������Ч�ڵ���� 
void SListClear(SList* s) {
	assert(s);
	while (SListSize(s)) {
		SListPopBack(s);
	}
	free(s->_pHead);
}

// �������� 
void SListDestroy(SList* s) {
	assert(s);
	while (SListSize(s)) {
		SListPopBack(s);
	}
	free(s->_pHead);
}

void PritfSList(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {
		printf("NULL\n");
		return;
	}
	PNode pCur = s->_pHead;
	while (pCur) {
		printf("%d---->",pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}
int main() {

	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	PritfSList(&s);
	SListPopBack(&s);
	PritfSList(&s);
	SListPopFront(&s);
	PritfSList(&s);
	SListPushFront(&s, 9);
	
	PritfSList(&s);
	printf("%d\n",SListEmpty(&s));

	printf("%d\n",SListSize(&s));

	printf("%p\n", SListFind(&s, 9));
	printf("%p\n", SListFind(&s, 2));
	printf("%p\n", SListFind(&s, 3));
	printf("%p\n", SListFind(&s, 4));
	printf("%p\n", SListFind(&s, 5));

	SListInsert(SListFind(&s, 3), 8);
	PritfSList(&s);

	SListErase(&s, SListFind(&s, 3));
	PritfSList(&s);

	SListClear(&s);
	PritfSList(&s);

	SListDestroy(&s);
	PritfSList(&s);
	system("pause");
	return 0;
}
//https://blog.csdn.net/Lange_Taylor/article/details/89926133