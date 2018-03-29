#pragma once

#include<stdio.h>

typedef char LinkType;

typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

//��ʼ����ͷ�ڵ�ĵ�����
void LinkNodeInit(LinkNode** head);
//β��һ��Ԫ��
LinkNode* LinkNodePushBack(LinkNode** head, LinkType value);
//βɾһ��Ԫ��
void LinkNodePopBack(LinkNode** head);
/*��ӡ����*/
void PrintChar(LinkNode* head, char* msg);
//ɾ���������һ����β���
void LinkNodePopNode(LinkNode* pos);
//�����ӡ������
void PrintLinkListReverse(LinkNode* head);
//�ڵ�����һ����ͷ�ڵ�֮ǰ����һ��Ԫ��,�������������
void LinkNodeInsert(LinkNode* pos, LinkType value);
//������ʵ��Լɪ������
/*
**Լɪ�򻷣���֪n����Χ����һ�������ϣ��ӱ��Ϊk���˿�ʼ������
����m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���˳��У�
����ѭ����ȥ��֪��Բ������ȫ������
*/
LinkNode* JosephCycle(LinkNode* head, int k, int n);

//��ʼ��һ����ͷ�ڵ�ĵ�����
void InitWithJosephy(LinkNode** head);
//��ͷ�ڵ�ĵ������β��
LinkNode* PushBack(LinkNode** head, LinkType value);
//���÷�ת��ͷ�ڵ������
void RevereseLinkList(LinkNode** head);
//��ӡ��ͷ�ڵ�ĵ�����
void PrintCharWithoutHead(LinkNode* head, char* msg);

//����������ð������
void LinkListBubbleSort(LinkNode* head);
//���������򣨿�������
void QuickSort(LinkNode* left, LinkNode* right);

//�ϲ������������ϲ�����Ȼ����
LinkNode* Merge(LinkNode** head1, LinkNode** head2);
//�ϲ����������ݹ飩���ϲ�����Ȼ����
LinkNode* MergeRecursive(LinkNode* head1, LinkNode* head2);
//����������м��㣬Ҫ��ֻ�ܱ���һ������
LinkNode* FindMidNode(LinkNode* head);
//���ҵ�����ĵ�����k����㣬Ҫ��ֻ�ܱ���һ������
LinkNode* FindKNode(LinkNode* head, int k);
//�ж������Ƿ���������������󻷵ĳ��Ⱥ��������,����������1
size_t CheckCycle(LinkNode* head, LinkNode** MeetNode);

/*��������������ڵ�
*���ַ���
*1.��һ�֣���������ָ�룬һ���������㿪ʼ�ߣ�
*һ����ͷ��ʼ�ߣ���һ����������Ϊ��ڵ�
*
*2.��������Ͽ�����ת��Ϊ�����������󽻵�
*/
LinkNode* FindEntryNode1(LinkNode* head);
LinkNode* FindEntryNode2(LinkNode* head);

/*
*�ж����������ཻ
*1.��������������
*  �ཻ
*  ���ཻ
*
*2.һ������һ��������
*  �������ཻ
*
*3.����������
*  �ཻ�ڻ��⣨��������ڵ㣬���ܲ��ڣ�
*  �ཻ�ڻ��ڣ��������㣬������������ڵ㣩
*/

int CheckCross(LinkNode* head1, LinkNode* head2, LinkNode** MeetNode);

/* 
*��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
*����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�
*������������ظ��ƺ��������
*/

typedef struct ComplexeNode{
	LinkType data;
	struct ComplexeNode* _next;
	struct ComplexeNode* _random;
}ComplexeNode;

/*����һ����������Ľ��*/
ComplexeNode* CreatComplexeNode(LinkType data);
/*����һ����������*/
void CreatComplexeList(ComplexeNode** head);
/*��ӡһ����������*/
void PrintComplexeList(ComplexeNode* head);
/*��������ĸ���*/
ComplexeNode* CopyCompexeList(ComplexeNode* cplist);