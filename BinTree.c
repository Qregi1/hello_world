#define _CRT_SECURE_NO_WARNINGS 1
#include"BinTree.h"
#include<stdlib.h>
#include"SeqStack.h"
#include"SeqQueue.h"

//����һ�����ڵ�
BinTreeNode* CreateBinTreeNode(BinTreeType value) {
	BinTreeNode* new_node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	if (new_node) {
		//new_node������NULL
		new_node->data = value;
		new_node->lchild = NULL;
		new_node->rchild = NULL;
	}
	else {
		printf("�����ڵ�ʧ��!\n");
	}
	return new_node;
}

//ǰ�����
//�ݹ�
BinTreeNode* BinTreePrevOrder1(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("[%c] ", root->data);
	BinTreePrevOrder1(root->lchild);
	BinTreePrevOrder1(root->rchild);
}

//�ǵݹ�
BinTreeNode* BinTreePrevOrder2(BinTreeNode* root) {
	if (root == NULL) {
		return;
	}
	//����һ��ջ����ʼ��
	SeqStack seq;
	SeqStackInit(&seq);
	SeqStackPush(&seq, root);
	//ѭ����ʼ��ֱ��ջΪ��
	while (SeqStackIsEmpty(&seq) == 0) {
		//ÿ��ȡ��һ��ջ��Ԫ�أ�Ȼ����������ҽڵ㶼ѹ��ջ��
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

//�������
BinTreeNode* BinTreeInOrder1(BinTreeNode* root) {
	//�ݹ���� 
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
	//���cur != NULL����Ҫ
	while (cur != NULL || SeqStackIsEmpty(&seq) == 0) {
		while (cur != NULL) {
			SeqStackPush(&seq, cur);
			cur = cur->lchild;
		}
		//�����������һֱ����
		cur = SeqStackTopValue(&seq);
		printf("[%c] ", cur->data);
		//��ջһ��Ԫ��
		SeqStackPop(&seq);
		cur = cur->rchild;
	} 
}

//��������
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

//�������
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
//���Դ���
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