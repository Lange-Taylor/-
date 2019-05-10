#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
//˳���Ķ�̬�洢

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capicity;
}SeqList,*Pseq;
//��������ɾ�Ĳ麯��
//˳���ĳ�ʼ��
void SeqListInit(Pseq ps1, size_t capacity);
//˳��������
void SeqListDestory(Pseq ps1);
//˳��������
int SeqListCapacity(Pseq ps1);
// ���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0
int SeqListEmpty(Pseq ps1);
// ����˳�������ЧԪ�صĸ��� 
int SeqListSize(Pseq ps1);
//˳���β������һ��Ԫ��
void SeqListPushBack(Pseq ps1,SLDataType x);
//˳����βɾ
void SeqListPopBack(Pseq ps1);
//˳����ͷ��
void SeqListPushFront(Pseq ps1,SLDataType x);
//˳����ͷɾ
void SeqListPopFront(Pseq ps1);
// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1
int SeqListFind(Pseq ps1, SLDataType x);
// ��˳���posλ�ò���ֵΪx��Ԫ��
void SeqListInsert(Pseq ps1,size_t pos,SLDataType x);
// ɾ��˳�����posλ���ϵ�Ԫ�� 
void SeqListErase(Pseq ps1,size_t pos);
// ɾ��˳����е�һ��ֵΪdata��Ԫ��
void SeqListRemove(Pseq ps1,SLDataType x);
//��˳����е�pos��Ԫ���޸�Ϊx
void SeqListModify(Pseq ps1,size_t pos, SLDataType x);
//��ӡ˳���
void SeqListPrint(Pseq ps1);
// ˳�������� 
void CheckCapacity(Pseq ps1);
// ��˳����е�Ԫ����� 
void SeqListClear(Pseq ps1);