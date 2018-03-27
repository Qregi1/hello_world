#define _CRT_SECURE_NO_WARNINGS 1
#include"BinTree.h"
#include<stdlib.h>
#include"SeqStack.h"
#include"SeqQueue.h"

//创建一个树节点
BinTreeNode* CreateBinTreeNode(BinTreeType value) {
	BinTreeNode* new_node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (new_node) {
		//new_node不等于NULL
		new_node->data = value;
		new_node->lchild = NULL;
		new_node->rchild = NULL;
	}
	else {
		printf("创建节点失败!\n");
	}
	return new_node;
}

//前序遍历
//递归
BinTreeNode* BinTreePrevOrder1(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("[%c] ", root->data);
	BinTreePrevOrder1(root->lchild);
	BinTreePrevOrder1(root->rchild);
}

//非递归
BinTreeNode* BinTreePrevOrder2(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	//创建一个栈并初始化
	SeqStack seq;
	SeqStackInit(&seq);
	SeqStackPush(&seq, root);
	//循环开始，直到栈为空
	while (SeqStackIsEmpty(&seq) == 0) {
		//每次取出一个栈顶元素，然后把它的左右节点都压入栈中
		 BinTreeNode* top = SeqStackTopValue(&seq);
		 SeqStackPop(&seq);
		 printf("[%c] ", top->data);
		 if (top->rchild != NULL) {
			 SeqStackPush(&seq, top->rchild);
		 }
		 if (top->lchild != NULL) {
			 SeqStackPush(&seq, top->lchild);
		 }
	}
}

//中序遍历
BinTreeNode* BinTreeInOrder1(BinTreeNode* root) {
	//递归遍历 
	if (root == NULL) {
		return;
	}
	BinTreeInOrder1(root->lchild);
	printf("[%c] ", root->data);
	BinTreeInOrder1(root->rchild);
}

BinTreeNode* BinTreeInOrder2(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack seq;
	SeqStackInit(&seq);
	BinTreeNode* cur = root;
	//这个cur != NULL很重要
	while (cur != NULL || SeqStackIsEmpty(&seq) == 0) {
		while (cur != NULL) {
			SeqStackPush(&seq, cur);
			cur = cur->lchild;
		}
		//沿着树的左侧一直遍历
		cur = SeqStackTopValue(&seq);
		printf("[%c] ", cur->data);
		//出栈一个元素
		SeqStackPop(&seq);
		cur = cur->rchild;
	} 
}

//后续遍历
BinTreeNode* BintreePostOrder1(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	BintreePostOrder1(root->lchild);
	BintreePostOrder1(root->rchild);
	printf("[%c] ", root->data);
}

BinTreeNode* BintreePostOrder2(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	SeqStack seq;
	SeqStackInit(&seq);
	BinTreeNode* prev = NULL;
	while (root != NULL || SeqStackIsEmpty(&seq) == 0) {
		while (root != NULL) {
			SeqStackPush(&seq, root);
			root = root->lchild;
		}
		root = SeqStackTopValue(&seq);
		
		if (root->rchild == NULL || prev == root->rchild) {
			printf("[%c] ", root->data);
			prev = root;
			SeqStackPop(&seq);
			root = NULL;
		}
		else {
			root = root->rchild;
		}
	}
}

//层序遍历
void BinTreeLevelOrder(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	Queue que;
	QueueInit(&que);
	QueuePush(&que, root);
	while (QueueEmpty(&que) == 0) {
		root = QueueHeadValue(&que);
		printf("[%c] ", root->data);
		QueuePop(&que);
		if (root->lchild != NULL) {
			QueuePush(&que, root->lchild);
		}
		if (root->rchild != NULL) {
			QueuePush(&que, root->rchild);
		}
	}
}

//////////////////////////////////////////
//测试代码
//////////////////////////////////////////
#if 1
#include<stdlib.h>
#define TESHEAD printf("--------------------%s-------------------\n",__FUNCTION__)

void TestPreorder() {
	BinTreeNode* root;
	root = NULL;
	BinTreeNode* node_a = CreateBinTreeNode('a');
	BinTreeNode* node_b = CreateBinTreeNode('b');
	BinTreeNode* node_c = CreateBinTreeNode('c');
	BinTreeNode* node_d = CreateBinTreeNode('d');
	BinTreeNode* node_e = CreateBinTreeNode('e');
	BinTreeNode* node_f = CreateBinTreeNode('f');
	BinTreeNode* node_g = CreateBinTreeNode('g');
	BinTreeNode* node_h = CreateBinTreeNode('h');

	node_a->lchild = node_b;
	node_a->rchild = node_c;
	node_b->lchild = node_d;
	node_b->rchild = node_e;
	node_c->rchild = node_f;
	node_e->lchild = node_g;
	node_e->rchild = node_h;
	root = node_a;

	BinTreePrevOrder1(root);
	printf("\n");
	BinTreePrevOrder2(root);

}

void TestInOrder() {
	BinTreeNode* root;
	root = NULL;
	BinTreeNode* node_a = CreateBinTreeNode('a');
	BinTreeNode* node_b = CreateBinTreeNode('b');
	BinTreeNode* node_c = CreateBinTreeNode('c');
	BinTreeNode* node_d = CreateBinTreeNode('d');
	BinTreeNode* node_e = CreateBinTreeNode('e');
	BinTreeNode* node_f = CreateBinTreeNode('f');
	BinTreeNode* node_g = CreateBinTreeNode('g');
	BinTreeNode* node_h = CreateBinTreeNode('h');

	node_a->lchild = node_b;
	node_a->rchild = node_c;
	node_b->lchild = node_d;
	node_b->rchild = node_e;
	node_c->rchild = node_f;
	node_e->lchild = node_g;
	node_e->rchild = node_h;
	root = node_a;

	BinTreeInOrder1(root);
	printf("\n");
	BinTreeInOrder2(root);
}

void TestPostOrder() {
	BinTreeNode* root;
	root = NULL;
	BinTreeNode* node_a = CreateBinTreeNode('a');
	BinTreeNode* node_b = CreateBinTreeNode('b');
	BinTreeNode* node_c = CreateBinTreeNode('c');
	BinTreeNode* node_d = CreateBinTreeNode('d');
	BinTreeNode* node_e = CreateBinTreeNode('e');
	BinTreeNode* node_f = CreateBinTreeNode('f');
	BinTreeNode* node_g = CreateBinTreeNode('g');
	BinTreeNode* node_h = CreateBinTreeNode('h');

	node_a->lchild = node_b;
	node_a->rchild = node_c;
	node_b->lchild = node_d;
	node_b->rchild = node_e;
	node_c->rchild = node_f;
	node_e->lchild = node_g;
	node_e->rchild = node_h;
	root = node_a;

	BintreePostOrder1(root);
	printf("\n");
	BintreePostOrder2(root);
}

void TestLevelOrder() {
	BinTreeNode* root;
	root = NULL;
	BinTreeNode* node_a = CreateBinTreeNode('a');
	BinTreeNode* node_b = CreateBinTreeNode('b');
	BinTreeNode* node_c = CreateBinTreeNode('c');
	BinTreeNode* node_d = CreateBinTreeNode('d');
	BinTreeNode* node_e = CreateBinTreeNode('e');
	BinTreeNode* node_f = CreateBinTreeNode('f');
	BinTreeNode* node_g = CreateBinTreeNode('g');
	BinTreeNode* node_h = CreateBinTreeNode('h');

	node_a->lchild = node_b;
	node_a->rchild = node_c;
	node_b->lchild = node_d;
	node_b->rchild = node_e;
	node_c->rchild = node_f;
	node_e->lchild = node_g;
	node_e->rchild = node_h;
	root = node_a;
	BinTreeLevelOrder(root);
}

int main() {
	//TestPreorder();
	TestInOrder();
	//TestPostOrder();
	//TestLevelOrder();
	system("pause");
	return 0;
}
#endif