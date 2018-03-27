#pragma once

#include<stdio.h>

typedef char BinTreeType;

typedef struct BinTreeNode{
	BinTreeType data;
	struct BinTreeNode* lchild;
	struct BinTreeNode* rchild;
}BinTreeNode;


//创建一个树节点
BinTreeNode* CreateBinTreeNode(BinTreeType value);
//前序遍历
//递归
BinTreeNode* BinTreePrevOrder1(BinTreeNode* root);
//非递归
BinTreeNode* BinTreePrevOrder2(BinTreeNode* root);
//中序遍历
BinTreeNode* BinTreeInOrder1(BinTreeNode* root);
BinTreeNode* BinTreeInOrder2(BinTreeNode* root);
//后续遍历
BinTreeNode* BintreePostOrder1(BinTreeNode* root);
BinTreeNode* BintreePostOrder2(BinTreeNode* root);

/*判断当前链表是否是完全二叉树*/
int IsCompleteTree(BinTreeNode* root);

/*由前序遍历序列和中序遍历序列重建二叉树*/
BinTreeNode* ReBulidBinTree(BinTreeType pre_array[], size_t pre_size,
	BinTreeType in_array[], size_t in_size);

