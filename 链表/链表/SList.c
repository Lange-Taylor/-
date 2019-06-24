#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"


// 链表的初始化 
void SListInit(SList* s) {
	assert(s);
	s->_pHead = NULL;
}
//创建新的节点
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

// 在链表s最后一个节点后插入值为data的节点 
void SListPushBack(SList* s, SDataType data) {
	assert(s);
	PNode pNewNode = BuySListNode(data);//创建一个新的节点
	if (NULL == s->_pHead) {
		s->_pHead = pNewNode;//如果链表为空,则让头节点指向新建立的节点
	}
	else
	{
		PNode pCur = s->_pHead;//创建一个变量用于寻找
		while (pCur->_pNext) {
			pCur = pCur->_pNext;//搜索最后一个节点为空时停下
		}
		pCur->_pNext = pNewNode;
	}
}

// 删除链表s最后一个节点 
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
		pCur = pCur->_pNext;//寻找下下一个元素
	}
	free(pCur->_pNext);//删除指针后需将其置空
	pCur->_pNext = NULL;
}

// 在链表s第一个节点前插入值为data的节点 
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

// 删除链表s的第一个节点 
void SListPopFront(SList* s) {
	assert(s);
	if (NULL == s->_pHead) {
		return;
	}
	PNode pDelNode = s->_pHead;
	s->_pHead = s->_pHead->_pNext;
	free(pDelNode);
}

// 在链表的pos位置后插入值为data的节点 
void SListInsert(PNode pos, SDataType data) {
	if (pos == NULL) {
		return;
	}
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

// 删除链表s中pos位置的节点 
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

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
PNode SListFind(SList* s, SDataType data) {
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur) {
		//pCur = pCur->_pNext;
		//查找时考虑每个元素都被遍历到,条件顺序考虑好
		if (data == pCur->_data) {
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

// 获取链表中有效节点的个数 
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

// 检测链表是否为空 
int SListEmpty(SList* s) {
	assert(s);
	return NULL == s->_pHead;
}

// 将链表中有效节点清空 
void SListClear(SList* s) {
	assert(s);
	while (SListSize(s)) {
		SListPopBack(s);
	}
	free(s->_pHead);
}

// 销毁链表 
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