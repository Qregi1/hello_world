#pragma once

#include<stdio.h>

typedef char BinTreeType;

typedef struct BinTreeNode{
	BinTreeType data;
	struct BinTreeNode* lchild;
	struct BinTreeNode* rchild;
}BinTreeNode;


//����һ�����ڵ�
BinTreeNode* CreateBinTreeNode(BinTreeType value);
//ǰ�����
//�ݹ�
BinTreeNode* BinTreePrevOrder1(BinTreeNode* root);
//�ǵݹ�
BinTreeNode* BinTreePrevOrder2(BinTreeNode* root);
//�������
BinTreeNode* BinTreeInOrder1(BinTreeNode* root);
BinTreeNode* BinTreeInOrder2(BinTreeNode* root);
//��������
BinTreeNode* BintreePostOrder1(BinTreeNode* root);
BinTreeNode* BintreePostOrder2(BinTreeNode* root);

/*�жϵ�ǰ�����Ƿ�����ȫ������*/
int IsCompleteTree(BinTreeNode* root);

/*��ǰ��������к�������������ؽ�������*/
BinTreeNode* ReBulidBinTree(BinTreeType pre_array[], size_t pre_size,
	BinTreeType in_array[], size_t in_size);

