#include "Seqlist.h"

void SeqListInit(Pseq ps1, size_t capacity) {
	ps1->array = (SLDataType*)malloc(capacity*sizeof(SLDataType));
	if (NULL == ps1->array) {
		assert(0);
		return;
	}
	ps1->capicity = capacity;
	ps1->size = 0;
	return;
}
void SeqListDestory(Pseq ps1) {
	if (ps1->array) {
		free(ps1->array);
		ps1->array = NULL;
		ps1->capicity = 0;
		ps1->size = 0;
	}
}
int SeqListCapacity(Pseq ps1) {
	assert(ps1);
	return ps1->capicity;
}
int SeqListEmpty(Pseq ps1) {
	assert(ps1);
	return 0 == ps1->size;
}
int SeqListSize(Pseq ps1) {
	assert(ps1);
	return ps1->size;
}
void SeqListPushBack(Pseq ps1, SLDataType x) {
	assert(ps1);
	if (ps1->size == ps1->capicity) {
		CheckCapacity(ps1);
	}
	ps1->array[ps1->size] = x;
	ps1->size++;
}
void SeqListPopBack(Pseq ps1) {
	assert(ps1);
	if (SeqListEmpty(ps1)) {
		return;
	}
	ps1->size--;
}
void SeqListPushFront(Pseq ps1, SLDataType x) {
	assert(ps1);
	//判断顺序表里是否存在元素
	///*if (ps1->size) {
	//	for (int i = ps1->size-1;i>=0;++i) {
	//		ps1->array[i + 1] = ps1->array[i];
	//	}
	//	ps1->array[0] = x;
	//	++ps1->size;
	//}
	//else
	//	ps1->array[0] = x;
	//	++ps1->size;*/
	if (ps1->size == ps1->capicity) {
		CheckCapacity(ps1);
	}
	for (int i = ps1->size - 1; i >= 0; --i) {
			ps1->array[i + 1] = ps1->array[i];
	}
		ps1->array[0] = x;
		ps1->size++;
}
void SeqListPopFront(Pseq ps1) {
	assert(ps1);
	if (!SeqListEmpty(ps1)) {
		for (int i = 1; i < ps1->size; ++i) {
			ps1->array[i - 1] = ps1->array[i];
		}
		ps1->size--;
	}
}

int SeqListFind(Pseq ps1, SLDataType x) {
	assert(ps1);
	for (int i = 0;i < ps1->size;++i) {
		if (x == ps1->array[i]) 
			return i;
	}
	return -1;
}
void SeqListInsert(Pseq ps1, size_t pos, SLDataType x) {
	assert(ps1);
	if (pos < 1||pos > ps1->size) {
		return;
	}
	if (ps1->size == ps1->capicity) {
		CheckCapacity(ps1);
	}
	//判断是否为空顺序表
	//需要将size_t强转回int作为循环条件判断

	for (int i = ps1->size - 1; i >= (int)(pos-1);--i) {
		ps1->array[i + 1] = ps1->array[i];
		ps1->array[i] = x;
	}
	ps1->size++;
}
void SeqListErase(Pseq ps1, size_t pos) {
	assert(ps1);
	if (pos<1 || pos > ps1->size) {
		return;
	}
	for (int i = (int)pos; i <= ps1->size ; ++i) {
		ps1->array[i - 1] = ps1->array[i];
	}
	ps1->size--;
}
void SeqListRemove(Pseq ps1, SLDataType x) {
	assert(ps1);
	for (int i = ps1->size; i >= 0;--i) {
		if (x == ps1->array[i]) {
			for (int j = i + 1; j < ps1->size;++j) {
				ps1->array[j - 1] = ps1->array[j];
			}
			ps1->size--;
		}
	}
}
void SeqListModify(Pseq ps1, size_t pos, SLDataType x) {
	assert(ps1);
	if (pos<1 || pos>ps1->size) {
		return;
	}
	ps1->array[pos-1] = x;
}
void SeqListPrint(Pseq ps1) {
	assert(ps1);
	for (int i = 0; i < ps1->size;++i)
		printf("%d\t", ps1->array[i]);
	printf("\n");
}

void CheckCapacity(Pseq ps1) {
	assert(ps1);
	int newCapacity = ps1->capicity * 2;
	//申请新的空间
	int* pTemp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
	if (NULL ==pTemp) {
		assert(0);
		return;
	}
	//拷贝元素
	for (int i = 0;i < ps1->size;++i) {
		pTemp[i] = ps1->array[i];
	}
	//释放旧空间
	free(ps1->array);
	ps1->array = pTemp;
	ps1->capicity = newCapacity;
}
void SeqListClear(Pseq ps1) {
	assert(ps1);
	ps1->size = 0;
}
int main() {
	SeqList  s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListPrint(&s);

	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 3);
	SeqListPrint(&s);

	SeqListInsert(&s, 1, 9);
	SeqListPrint(&s);
	SeqListInsert(&s, 10, 10);
	SeqListPrint(&s);
	

	int pos = SeqListFind(&s, 4);
	if (pos != -1)
		printf("存在,第一次出现下标%d\n", pos);
	else
		printf("不存在,%d\n", pos);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	int pos1 = SeqListFind(&s, 4);
	if (pos1 != -1)
		printf("存在,第一次出现下标%d\n", pos1);
	else
		printf("不存在,%d\n", pos1);
	printf("%d\n", SeqListSize(&s));

	SeqListModify(&s, 2, 6);
	SeqListPrint(&s);

	SeqListClear(&s);
	SeqListPrint(&s);
	assert(&s);

	SeqListDestory(&s);
	SeqListPrint(&s);
	assert(&s);

    system("pause");
	return 0;
}