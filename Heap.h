#pragma once 

#include<stdio.h>

typedef int HeapType;

#define HEAPMAXSIZE 1000

typedef int(*Compare)(HeapType a, HeapType b);

typedef struct Heap{
	HeapType data[HEAPMAXSIZE];
	Compare cmp;
	size_t size;
}Heap;

/*初始化*/
void HeapInit(Heap* heap);

/*插入元素*/
void HeapInsert(Heap* heap, HeapType value);

/*取堆顶元素*/
HeapType HeapRoot(Heap* heap);

/*删除堆顶元素*/
void HeapErase(Heap* heap);

/*堆判空*/
int HeapEmpty(Heap* heap);

/*求堆的大小*/
size_t HeapSize(Heap* heap);

/*销毁堆*/
void HeapDestory(Heap* heap);

/*堆排序*/
void HeapSort(HeapType data[], size_t size);