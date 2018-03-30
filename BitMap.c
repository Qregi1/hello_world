#define _CRT_SECURE_NO_WARNINGS 1
#include"BitMap.h"
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<assert.h>
#include<string.h>

size_t DataSize(size_t capacity) {
	/*sizeof(uint64_t)是８个字节，　capacity表示需要存储的数据类型*/
	return capacity / (sizeof(uint64_t) * 8)+ 1;
}

/*初始化*/
void BitMapInit(BitMap* bm, size_t capacity) {
	if (bm == NULL) {
		return;
	}
	bm->capacity = capacity;
	/*得到的size表示需要容量的几个６４位的存储空间*/
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

/*把index位设置为１*/
/*
**用65为例子
**n = index / (sizeof(uint64_t) * 8);  -> 1
**offset = index % (sizeof(uint64_t) * 8)  -> 1
**data[n] |= (1lu << offset)
*/
void BitMapSet(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	if (index >= bm->capacity) {
		/*表示已经超过现在所能存储的数据容量 */
		return;
	}
	size_t n = 0;
	size_t offset = 0;
	GetOffset(index, &n, &offset);
	bm->data[n] |= (1lu << offset);
}

/*把index位设置为０*/
void BitMapUnSet(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n, offset;
	GetOffset(index, &n, &offset);
	/*
	**１左移offest位，然后求补，再与bm->data[n]一与
	*/
	bm->data[n] &= ~(1lu << offset);
}


/*测试index为１还是为０，如果是１，就返回１，否则返回０*/
int BitMapTest(BitMap* bm, size_t index) {
	if (bm == NULL) {
		return;
	}
	size_t n, offset;
	GetOffset(index, &n, &offset);
	int i = bm->data[n] & (1lu << offset);
	return i != 0 ? 1 : 0;
}

/*把这个位图所有位都设置为１*/
void BitmapFill(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	/*这里的size是总共有多少个字节*/
	size_t size = sizeof(uint64_t)* DataSize(bm->capacity);
	memset(bm->data, 0xff, size);
}

/*把整个位图所有位都设置为０*/
void BitMapClear(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	size_t size = sizeof(uint64_t)* DataSize(bm->capacity);
	memset(bm->data, 0, size);
}

/*销毁*/
void BitMapDestory(BitMap* bm) {
	if (bm == NULL) {
		return;
	}
	free(bm->data);
	bm->capacity = 0;
}

////////////////////////////////////////
//以下为测试代码
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
	/*数组有两个元素*/
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
	/*数组有两个元素*/
	BitMapSet(&bm, 65);
	printf("之前：\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	BitMapUnSet(&bm, 65);
	printf("之后：\n");
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
	/*数组有两个元素*/
	BitMapSet(&bm, 65);
	printf("之前：\n");
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
	/*数组有两个元素*/
	BitMapSet(&bm, 65);
	printf("之前：\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	printf("之后：\n");
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
	/*数组有两个元素*/
	BitMapSet(&bm, 65);
	printf("之前：\n");
	int i = 0;
	for (; i < bm.capacity / (sizeof(uint64_t)* 8); ++i) {
		printf("[%lu] %lu", i, bm.data[i]);
	}
	printf("\n");

	printf("全部设为1之后：\n");
	BitmapFill(&bm);
	int j = 0;
	for (; j < bm.capacity / (sizeof(uint64_t)* 8); ++j) {
		printf("[%lu] %lx", j, bm.data[j]);
	}
	printf("\n");

	printf("全部设为０之后:\n");
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
