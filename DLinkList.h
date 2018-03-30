
#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef char DLinkType;

//C����˫������

typedef struct DLinkNode{

	 DLinkType data;
	 struct DLinkNode* _next;
	 struct DLinkNode* _prev;

}DLinkNode;

typedef struct DLinkList{

	DLinkNode* head;
	DLinkNode* tail;
	int size;

}DLinkList;

//����һ�����
DLinkNode* CreatNewNode(DLinkType value);
//�ͷ�һ�����
void DestoryNode(DLinkNode** node);
//��ʼ��˫������
DLinkList* InitDLinkList();
//�ж������Ƿ�Ϊ��
int DLinkListEmpty(DLinkList* plist);
//β��һ��Ԫ��
DLinkList* DLinkListPushBack(DLinkList* plist, DLinkType value);
//��ӡ��������
void PrintChar(DLinkList* plist, char* msg);
//βɾһ��Ԫ��
void DLinkListPopBack(DLinkList* plist);
//ͷ��һ��Ԫ��
void DLinkListPushFront(DLinkList* plist, DLinkType value);
//ͷɾһ��Ԫ��
void DLinkListPopFront(DLinkList* plist);
//����ĳ��Ԫ��
DLinkNode* DLinkListFind(DLinkList* plist, DLinkType to_find);
//��ָ��λ��֮ǰ����һ��Ԫ��
void DLinkListInsert(DLinkList* plist,DLinkNode* pos, DLinkType value);
//��ָ��λ��֮�����һ��Ԫ��
void DLinkListInsertAfter(DLinkList* plist, DLinkNode* pos, DLinkType value);
//ɾ��ָ��λ�õ�Ԫ��
void DLinkListErase(DLinkList* plist, DLinkNode* pos);
//ɾ��ָ��ֵ��Ԫ��
void DLinkListRemove(DLinkList* plist, DLinkType to_delete);
//ɾ������ָ��ֵ��Ԫ��
void DLinkListRemoveAll(DLinkList* plist, DLinkType to_delete);

//ɾ��һ�����������Ԫ��
void DLinkListClear(DLinkList* plist);