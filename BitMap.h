#pragma once

#include<stdint.h>
#include<stddef.h>

typedef struct BitMap{
	uint64_t* data;
	size_t capacity;
}BitMap;

/*��ʼ��*/
void BitMapInit(BitMap* bm, size_t capacity);

/*��indexλ����Ϊ��*/
void BitMapSet(BitMap* bm, size_t index);

/*��indexλ����Ϊ��*/
void BitMapUnSet(BitMap* bm, size_t index);

/*����indexΪ������Ϊ��������ǣ����ͷ��أ������򷵻أ�*/
int BitMapTest(BitMap* bm, size_t index);

/*�����λͼ����λ������Ϊ��*/
void BitmapFill(BitMap* bm);

/*������λͼ����λ������Ϊ��*/
void BitMapClear(BitMap* bm);

/*����*/
void BitMapDestory(BitMap* bm);
