#define _CRT_SECURE_NO_WARNINGS 1
#include"BitMap.h"
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<assert.h>
#include<string.h>

size_t DataSize(size_t capacity) {
	/*sizeof(uint64_t)�ǣ����ֽڣ���capacity��ʾ��Ҫ�洢����������*/
	return capacity / (sizeof(uint64_t) * 8)+ 1;
}

/*��ʼ��*/
void BitMapInit(BitMap* bm, size_t capacity) {
	if (bm == NULL) {
		return;
	}
	bm->capacity = capacity;
	/*�õ���size��ʾ��Ҫ�����ļ�������λ�Ĵ洢�ռ�*/
	size_t size = DataSize(capacity);
	bm->data = (uint64_t*)malloc(sizeof(uint64_t)* size);
	memset(bm->data, 0, sizeof(uint64_t)* size);
}

size_t GetOffset(size_t index, size_t* n, size_t* offset) {
	assert(n);
	assert(offset);
	*n = index / (sizeof(uint64_t)* 8);
	*offset = index % (sizeof(uint64_t)* 8);
}

/*��indexλ����Ϊ��*/
/*
**��65Ϊ����
**n = index / (sizeof(uint64_t) * 8);  -> 1
**offset = index % (sizeof(uint64_t) * 8)  -> 1
**data[n] |= (1lu << offset)
*/
void BitMapSet(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	if (index >= bm->capacity) {
		/*��ʾ�Ѿ������������ܴ洢���������� */
		return;
	}
	size_t n = 0;
	size_t offset = 0;
	GetOffset(index, &n, &offset);
	bm->data[n] |= (1lu << offset);
}

/*��indexλ����Ϊ��*/
void BitMapUnSet(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n, offset;
	GetOffset(index, &n, &offset);
	/*
	**������offestλ��Ȼ���󲹣�����bm->data[n]һ��
	*/
	bm->data[n] &= ~(1lu << offset);
}


/*����indexΪ������Ϊ��������ǣ����ͷ��أ������򷵻أ�*/
int BitMapTest(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n, offset;
	GetOffset(index, &n, &offset);
	int i = bm->data[n] & (1lu << offset);
	return i != 0 ? 1 : 0;
}

/*�����λͼ����λ������Ϊ��*/
void BitmapFill(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	/*�����size���ܹ��ж��ٸ��ֽ�*/
	size_t size = sizeof(uint64_t)* DataSize(bm->capacity);
	memset(bm->data, 0xff, size);
}

/*������λͼ����λ������Ϊ��*/
void BitMapClear(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	size_t size = sizeof(uint64_t)* DataSize(bm->capacity);
	memset(bm->data, 0, size);
}

/*����*/
void BitMapDestory(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	free(bm->data);
	bm->capacity = 0;
}

////////////////////////////////////////
//����Ϊ���Դ���
////////////////////////////////////////
#if 1
#include<stdio.h>
#include<stdlib.h>

#define TESTHEAD printf("---------------%s--------------\n",__FUNCTION__)

void TestInit() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 65);

	printf("expect 65, actual:%d\n", bm.capacity);
}

void TestSet() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 128);
	/*����������Ԫ��*/
	BitMapSet(&bm, 65);
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");
}

void TestUnSet() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 128);
	/*����������Ԫ��*/
	BitMapSet(&bm, 65);
	printf("֮ǰ��\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	BitMapUnSet(&bm, 65);
	printf("֮��\n");
	int j = 0;
	for (; j < bm.capacity / (sizeof(uint64_t)* 8); ++j) {
		printf("[%lu] %lu", j, bm.data[j]);
	}
	printf("\n");
}

void TestBitMapTest() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 128);
	/*����������Ԫ��*/
	BitMapSet(&bm, 65);
	printf("֮ǰ��\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	int n = BitMapTest(&bm, 65);
	printf("expcect 1, acutl:%d\n", n);
}

void TestFill() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 128);
	/*����������Ԫ��*/
	BitMapSet(&bm, 65);
	printf("֮ǰ��\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	printf("֮��\n");
	BitmapFill(&bm);
	int j = 0;
	for (; j < bm.capacity / (sizeof(uint64_t)* 8); ++j) {
		printf("[%lu] %lx", j, bm.data[j]);
	}
	printf("\n");
}

void TestClear() {
	BitMap bm;
	TESTHEAD;
	BitMapInit(&bm, 128);
	/*����������Ԫ��*/
	BitMapSet(&bm, 65);
	printf("֮ǰ��\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	printf("ȫ����Ϊ1֮��\n");
	BitmapFill(&bm);
	int j = 0;
	for (; j < bm.capacity / (sizeof(uint64_t)* 8); ++j) {
		printf("[%lu] %lx", j, bm.data[j]);
	}
	printf("\n");

	printf("ȫ����Ϊ��֮��:\n");
	BitMapClear(&bm);
	int k = 0;
	for (; k < bm.capacity / 64; ++k) {
		printf("[%lu] %lx", j, bm.data[k]);
	}
	printf("\n");
}



int main() {
	TestInit();
	TestSet();
	TestUnSet();
	TestBitMapTest();
	TestFill();
	TestClear();
	system("pause");
}

#endif
