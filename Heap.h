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

/*��ʼ��*/
void HeapInit(Heap* heap);

/*����Ԫ��*/
void HeapInsert(Heap* heap, HeapType value);

/*ȡ�Ѷ�Ԫ��*/
HeapType HeapRoot(Heap* heap);

/*ɾ���Ѷ�Ԫ��*/
void HeapErase(Heap* heap);

/*���п�*/
int HeapEmpty(Heap* heap);

/*��ѵĴ�С*/
size_t HeapSize(Heap* heap);

/*���ٶ�*/
void HeapDestory(Heap* heap);

/*������*/
void HeapSort(HeapType data[], size_t size);