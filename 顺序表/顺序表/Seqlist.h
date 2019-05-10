#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
//顺序表的动态存储

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capicity;
}SeqList,*Pseq;
//基本的增删改查函数
//顺序表的初始化
void SeqListInit(Pseq ps1, size_t capacity);
//顺序表的销毁
void SeqListDestory(Pseq ps1);
//顺序表的容量
int SeqListCapacity(Pseq ps1);
// 检测顺序表是否为空，如果为空返回非0值，非空返回0
int SeqListEmpty(Pseq ps1);
// 返回顺序表中有效元素的个数 
int SeqListSize(Pseq ps1);
//顺序表尾部插入一个元素
void SeqListPushBack(Pseq ps1,SLDataType x);
//顺序表的尾删
void SeqListPopBack(Pseq ps1);
//顺序表的头插
void SeqListPushFront(Pseq ps1,SLDataType x);
//顺序表的头删
void SeqListPopFront(Pseq ps1);
// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的下标，否则返回-1
int SeqListFind(Pseq ps1, SLDataType x);
// 在顺序表pos位置插入值为x的元素
void SeqListInsert(Pseq ps1,size_t pos,SLDataType x);
// 删除顺序表中pos位置上的元素 
void SeqListErase(Pseq ps1,size_t pos);
// 删除顺序表中第一个值为data的元素
void SeqListRemove(Pseq ps1,SLDataType x);
//将顺序表中第pos个元素修改为x
void SeqListModify(Pseq ps1,size_t pos, SLDataType x);
//打印顺序表
void SeqListPrint(Pseq ps1);
// 顺序表的扩容 
void CheckCapacity(Pseq ps1);
// 将顺序表中的元素清空 
void SeqListClear(Pseq ps1);