#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

void DListInit(PDLNode* pHead) {
	assert(pHead);
	*pHead = (PDLNode)malloc(sizeof(DLNode));
	if (NULL == *pHead) {
		assert(0);
		return;
	}
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

PDLNode BuyDListNode(DLDataType data) {
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->_data = data;

	return pNewNode;
}

void DListPushBack(PDLNode pHead, DLDataType data) {
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;
	pHead->_pPre->_pNext = pNewNode;
	pHead->_pPre = pNewNode;
}

void DListPopBack(PDLNode pHead) {
	assert(pHead);
	if (pHead == pHead->_pNext) {
		return;
	}
	PDLNode pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}

void DListPushFront(PDLNode pHead, DLDataType data) {
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pPre = pHead;
	pNewNode->_pNext = pHead->_pNext;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}

void DListPopFront(PDLNode pHead) {
	assert(pHead);
	if (pHead == pHead->_pNext) {
		return;
	}
	PDLNode pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = pHead;
	free(pDelNode);
}

void DListInsert(PDLNode pos, DLDataType data) {
	if (pos == NULL) {
		return;
	}
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	//pos->_pPre->_pNext = pNewNode;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
	
}

void DListErase(PDLNode pos) {
	if (pos == NULL) {
		return;
	}
	
	pos->_pNext->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pos->_pNext;
	free(pos);
	pos == NULL;
}

PDLNode DListFind(DLDataType pos, PDLNode pHead) {
	assert(pHead);
	PDLNode pRet = pHead;
	while (pRet != pHead->_pNext) {
		if (pos == pHead->_data) {
			return pHead;
		}
		pHead = pHead->_pNext;
	}
	return NULL;
}

void DListClear(PDLNode pHead) {
	PDLNode pCur = pHead->_pPre;
	while (pCur != pHead) {
		pCur->_pPre->_pNext = pHead;
		pHead->_pPre = pCur->_pPre;
		free(pCur);
		pCur = pHead->_pPre;
		//pCur->_pNext = pHead->_pNext;
	}
	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
}

void DListDestroy(PDLNode* pHead) {
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

void PrintDList(PDLNode pHead) {
	assert(pHead);
	PDLNode pCur = pHead;
	while (pCur != pHead->_pNext) {
		printf("%d---->", pHead->_pNext->_data);
		pHead = pHead->_pNext;
	}
	printf("\n");

}

int main() {

	PDLNode pHead = NULL;
	DListInit(&pHead);
	
	//printf("%p\n", BuyDListNode(2));
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);

	PrintDList(pHead);

	DListPushFront(pHead, 4);
	DListPushFront(pHead, 5);
	DListPushFront(pHead, 6);

	PrintDList(pHead);

	DListPopBack(pHead);
	PrintDList(pHead);

	DListPopFront(pHead);
	PrintDList(pHead);

	DListInsert(pHead, 9);
	PrintDList(pHead);

	//printf("%p\n", DListFind(2, pHead));

	DListErase(DListFind(2,pHead),pHead);
	PrintDList(pHead);

	DListClear(pHead);

	DListDestroy(&pHead);

	system("pause");
	return 0;
}