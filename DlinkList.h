#pragma once
 

#include<stdio.h>
#include<stddef.h>

typedef char DLinkType;

//˫������
typedef struct DLinkNode {

	DLinkType data;
	struct DLinkNode* _next;
	struct DLinkNode* _prev;

}DLinkNode;
//
//typedef struct DLinkList{
//
//	struct DLinkNode head;
//	struct DLinkNode tail;
//	size_t size;
//
//}DLinkList;

//�������
DLinkNode* CreatNewNode(DLinkType data);
//��ʼ��
void DLinkListInit(DLinkNode** head);
//β��һ��Ԫ��
DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value);
//��ӡ˫������
void PrintDLinkNode(DLinkNode* head, const char* msg);
//�ͷ�ĳ�����ĵ�ַ�ռ�
void DestoyNode(DLinkNode* node);
//βɾһ��Ԫ��
void DLinkListPopBack(DLinkNode* head);
//ͷ��һ��Ԫ��
void DLinkListPushFront(DLinkNode* head, DLinkType value);
//ͷɾһ��Ԫ��
void DLinkListPopFront(DLinkNode* head);
//����һ��Ԫ��
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);
//��ָ��λ��֮ǰ����һ��Ԫ��
void DLinkListInsert(DLinkNode* pos, DLinkType value);
//��ָ��λ��֮�����һ��Ԫ��
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value);
//ɾ��ָ��λ�õ�Ԫ��
void DLinkListErase(DLinkNode* pos);
//ɾ��ָ��ֵ��Ԫ��
void DLinkListRemove(DLinkNode* head, DLinkType value);
//�������ĳ���
size_t DLinkListSize(DLinkNode* head);
//ɾ������������ָ��ֵ��Ԫ��
void DLinkLisrRemoveAll(DLinkNode** head,DLinkType to_delete);
//�ж������Ƿ�Ϊ��
int DLinkListEmpty(DLinkNode* head);