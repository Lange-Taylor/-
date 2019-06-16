#include "Queue.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void QueueInit(Queue* pq) {
	assert(pq);
	pq->_front = pq->_back = NULL;
}
void QueueDstory(Queue* pq) {
	assert(pq);
	QueueNode* pDelNode = pq->_front;

	if (QueueSize(pq)) {
		QueuePop(pq);
	}
	free(pq->_front);
	free(pq->_back);
	pq->_front = pq->_back = NULL;
}

QueueNode* BuyQueueNode(QUDataType x) {
	QueueNode* PNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NULL == PNewNode) {
		assert(0);
		return;
	}
	PNewNode->_data = x;
	PNewNode->_next = NULL;
	return PNewNode;
}
void QueuePush(Queue* pq, QUDataType x) {
	assert(pq);
	QueueNode* pNewNode = BuyQueueNode(x);
	if (QueueEmpty(pq)) {
		pq->_front = pq->_back = pNewNode;
	}
	else {
		pq->_back->_next = pNewNode;
		pq->_back = pNewNode;
	}
}
void QueuePop(Queue* pq) {
	assert(pq);
	if (QueueEmpty(&pq))
		return;
	QueueNode* pDelNode = pq->_front;
	if (pq->_front == pq->_back) {
		pq->_front = pq->_back = NULL;
	}
	else
	{
		pq->_front = pq->_front->_next;
	}
	free(pDelNode);
}

QUDataType QueueFront(Queue* pq) {
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq) {
	assert(pq);
	return pq->_back->_data;
}
int QueueEmpty(Queue* pq) {
	return NULL == pq->_front;
}
int QueueSize(Queue* pq) {
	assert(pq);
	QueueNode* pCur = pq->_front;
	int size = 0;
	while (pCur) {
		size++;
		pCur = pCur->_next;
	}
	return size;
}
int main() {

	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueueDstory(&q);
	return 0;
}