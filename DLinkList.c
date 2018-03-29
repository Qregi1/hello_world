#define _CRT_SECURE_NO_WARNINGS 1

#include"DlinkList.h"

DLinkNode* CreatNewNode(DLinkType data) {

	//����������ռ�
	DLinkNode* new_node = (DLinkNode*)malloc(sizeof(DLinkNode));

	if (new_node != NULL) {
		new_node->data = data;
		new_node->_next = NULL;
		new_node->_prev = NULL;
	}
	return new_node;

}

//���������ͷ�ڵ�
void DLinkListInit(DLinkNode** head) {
	
	if (head == NULL) {
		return;
	}
	*head = CreatNewNode('0');
	(*head)->_next = *head;
	(*head)->_next = *head;

	
}
/*
**β��һ��Ԫ��
*/
DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		printf("����ͷ�ڵ��ʼ��ʧ��");
		return;
	}
	DLinkNode* new_node = CreatNewNode(value);

		int i = 0;
		DLinkNode* cur = head;
		/*
		**�������������Ԫ�أ�ͨ�������������ĩβ��Ȼ����в���
		*/
		while (cur->_next != head) {
			cur = cur->_next;
		}
		cur->_next = new_node;
		new_node->_prev = cur;

		head->_prev = new_node;
		new_node->_next = head;

}

void PrintDLinkNode(DLinkNode* head,const char* msg) {

	if (head == NULL) {
		return;
	}
	//���Ŵ�ӡ

	printf("%s\n", msg);
	DLinkNode* cur = head->_next;
	printf("\n\n head -> ");
	while (cur != head) {
		printf(" [%c]->", cur->data);
		cur = cur->_next;
	}
	printf("head\n");

	//���Ŵ�ӡ
	DLinkNode* cur2 = head->_prev;
	printf("\n\n head ->");
	while (cur2 != head) {
		printf(" [%c]->", cur2->data);
		cur2 = cur2->_prev;
	}
	printf("head\n\n\n");

}

/*
**����һ�����
*/
void DestoyNode(DLinkNode** node) {
	if (node == NULL) {
		//Ԫ�طǷ�
		return;
	}
	if (*node == NULL) {
		//�������������
		return;
	}
	free(*node);
	*node = NULL;
}
/*
**��˫�������У�βɾһ��Ԫ��
*/
void DLinkListPopBack(DLinkNode* head) {

	if (head == NULL) {
		//��ʼ��ͷ���ʧ��
		return;
	}

	if (head->_next == head || head->_prev == head) {
		printf("����Ϊ�գ�");
		return;
	}

	DLinkNode* cur = head;

	//ͨ��ѭ���������ҵ����һ��Ԫ��cur
	while (cur->_next != head) {
		cur = cur->_next;
	}
	//����һ���ṹ�������pre�������ڶ���Ԫ��
	DLinkNode* pre = cur->_prev;

	head->_prev = pre;
	pre->_next = head;

	DLinkNode* Delete = cur;
	DestoyNode(&Delete);

}


/*
**��˫�������У�ͷ��һ��Ԫ��
*/
void DLinkListPushFront(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		//ͷ�ڵ㲻���ڣ���ʼ������
		return;
	}
	DLinkNode* NewNode = CreatNewNode(value);
	//�����½��洢����
	//��������ĵ�һ��Ԫ��
	DLinkNode* OldNode = head->_next;

	head->_next = NewNode;
	NewNode->_prev = head;

	NewNode->_next = OldNode;
	OldNode->_prev = NewNode;

}

//ͷɾһ��Ԫ��
void DLinkListPopFront(DLinkNode* head) {

	if (head == NULL) {
		return;
	}
	//�ж������Ƿ�Ϊ��
	if (head->_next == head || head->_prev == head) {
		printf("����Ϊ�գ�");
		return;
	}

	//�ȱ���Ҫɾ���Ľ��
	DLinkNode* Delete = head->_next;
	//Ȼ������������
	DLinkNode* cur = head->_next->_next;

	head->_next = cur;
	cur->_prev = head;

	DestoyNode(&Delete);

}

//����һ��Ԫ��
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find) {

	if (head == NULL) {
		return;
	}
	DLinkNode* error = CreatNewNode('-1');
	DLinkNode* cur = head->_next;

	while (cur != head) {

		if (cur->data == to_find) {
			return cur;
		}
		cur = cur->_next;
	}
	printf("������û�и�Ԫ�أ�\n");
	return error;

}

//��ָ��λ��֮ǰ����һ��Ԫ��
void DLinkListInsert(DLinkNode* pos, DLinkType value) {

	if (pos == NULL) {
		//�����λ�ô���
		return;
	}
	DLinkNode* Insert = CreatNewNode(value);

	DLinkNode* pre = pos->_prev;
	//����
	pre->_next = Insert;
	Insert->_prev = pre;

	Insert->_next = pos;
	pos->_prev = Insert;

}

//��ָ��λ��֮�����һ��Ԫ��
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value) {

	if (pos == NULL) {
		return;
	}

	DLinkNode* InsertAfter = CreatNewNode(value);
	DLinkNode* PosNext = pos->_next;

	//����
	pos->_next = InsertAfter;
	InsertAfter->_prev = pos;

	InsertAfter->_next = PosNext;
	PosNext->_prev = InsertAfter;

}

//ɾ��ָ��λ�õ�Ԫ��
void DLinkListErase(DLinkNode* pos) {

	if (pos == NULL) {
		//λ�ô������
		return;
	}
	DLinkNode* before = pos->_prev;
	DLinkNode* after = pos->_next;

	before->_next = after;
	after->_prev = before;

	DestoyNode(&pos);

}

//ɾ��ָ��ֵ��Ԫ��
void DLinkListRemove(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		//ͷ�ڵ㲻����,��ʼ��ʧ��
		return;
	}
	DLinkNode* cur = head->_next;
	while (cur != head) {

		//�ҵ�ƥ���Ԫ����
		if (cur->data == value) {
			DLinkNode* cur_prev = cur->_prev;
			DLinkNode* cur_next = cur->_next;

			//ɾ��
			cur_prev->_next = cur_next;
			cur_next->_prev = cur_prev;
			return;

		}
		cur = cur->_next;
	}

}

//�������ĳ���
size_t DLinkListSize(DLinkNode* head) {

	if (head == NULL) {
		return;
	}
	DLinkNode* cur = head->_next;
	size_t sz = 0;
	while (cur != head) {
		++sz;
		cur = cur->_next;
	}
	return sz;

}

//ɾ������������ָ��ֵ��Ԫ��
void DLinkLisrRemoveAll(DLinkNode** head, DLinkType to_delete) {

	if (head == NULL) {
		return;
	}
	if (*head == NULL) {
		return;
	}
	size_t sz = DLinkListSize(*head);
	while (sz) {
		DLinkListRemove(*head, to_delete);
		sz--;
	}

}

//�ж������Ƿ�Ϊ��
int DLinkListEmpty(DLinkNode* head) {

	if (head == NULL) {
		return;
	}
	if (head->_next == head || head->_prev == head) {
		return -1;
	}
	else{
		return 1;
	}

}