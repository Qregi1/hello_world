#define _CRT_SECURE_NO_WARNINGS 1

#include"DlinkList.h"

DLinkNode* CreatNewNode(DLinkType data) {

	//给数据申请空间
	DLinkNode* new_node = (DLinkNode*)malloc(sizeof(DLinkNode));

	if (new_node != NULL) {
		new_node->data = data;
		new_node->_next = NULL;
		new_node->_prev = NULL;
	}
	return new_node;

}

//创建链表的头节点
void DLinkListInit(DLinkNode** head) {
	
	if (head == NULL) {
		return;
	}
	*head = CreatNewNode('0');
	(*head)->_next = *head;
	(*head)->_next = *head;

	
}
/*
**尾插一个元素
*/
DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		printf("链表头节点初始化失败");
		return;
	}
	DLinkNode* new_node = CreatNewNode(value);

		int i = 0;
		DLinkNode* cur = head;
		/*
		**如果链表里面有元素，通过遍历到链表的末尾，然后进行插入
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
	//正着打印

	printf("%s\n", msg);
	DLinkNode* cur = head->_next;
	printf("\n\n head -> ");
	while (cur != head) {
		printf(" [%c]->", cur->data);
		cur = cur->_next;
	}
	printf("head\n");

	//反着打印
	DLinkNode* cur2 = head->_prev;
	printf("\n\n head ->");
	while (cur2 != head) {
		printf(" [%c]->", cur2->data);
		cur2 = cur2->_prev;
	}
	printf("head\n\n\n");

}

/*
**销毁一个结点
*/
void DestoyNode(DLinkNode** node) {
	if (node == NULL) {
		//元素非法
		return;
	}
	if (*node == NULL) {
		//参数传入出错误
		return;
	}
	free(*node);
	*node = NULL;
}
/*
**在双向链表中，尾删一个元素
*/
void DLinkListPopBack(DLinkNode* head) {

	if (head == NULL) {
		//初始化头结点失败
		return;
	}

	if (head->_next == head || head->_prev == head) {
		printf("链表为空！");
		return;
	}

	DLinkNode* cur = head;

	//通过循环遍历，找到最后一个元素cur
	while (cur->_next != head) {
		cur = cur->_next;
	}
	//创建一个结构体变量，pre代表倒数第二个元素
	DLinkNode* pre = cur->_prev;

	head->_prev = pre;
	pre->_next = head;

	DLinkNode* Delete = cur;
	DestoyNode(&Delete);

}


/*
**在双向链表中，头插一个元素
*/
void DLinkListPushFront(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		//头节点不存在，初始化错误
		return;
	}
	DLinkNode* NewNode = CreatNewNode(value);
	//创建新结点存储数据
	//爆粗链表的第一个元素
	DLinkNode* OldNode = head->_next;

	head->_next = NewNode;
	NewNode->_prev = head;

	NewNode->_next = OldNode;
	OldNode->_prev = NewNode;

}

//头删一个元素
void DLinkListPopFront(DLinkNode* head) {

	if (head == NULL) {
		return;
	}
	//判断链表是否为空
	if (head->_next == head || head->_prev == head) {
		printf("链表为空！");
		return;
	}

	//先保存要删除的结点
	DLinkNode* Delete = head->_next;
	//然后从链表拆除结点
	DLinkNode* cur = head->_next->_next;

	head->_next = cur;
	cur->_prev = head;

	DestoyNode(&Delete);

}

//查找一个元素
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
	printf("链表中没有该元素！\n");
	return error;

}

//往指定位置之前插入一个元素
void DLinkListInsert(DLinkNode* pos, DLinkType value) {

	if (pos == NULL) {
		//传入的位置错误
		return;
	}
	DLinkNode* Insert = CreatNewNode(value);

	DLinkNode* pre = pos->_prev;
	//插入
	pre->_next = Insert;
	Insert->_prev = pre;

	Insert->_next = pos;
	pos->_prev = Insert;

}

//往指定位置之后插入一个元素
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value) {

	if (pos == NULL) {
		return;
	}

	DLinkNode* InsertAfter = CreatNewNode(value);
	DLinkNode* PosNext = pos->_next;

	//插入
	pos->_next = InsertAfter;
	InsertAfter->_prev = pos;

	InsertAfter->_next = PosNext;
	PosNext->_prev = InsertAfter;

}

//删除指定位置的元素
void DLinkListErase(DLinkNode* pos) {

	if (pos == NULL) {
		//位置传入错误
		return;
	}
	DLinkNode* before = pos->_prev;
	DLinkNode* after = pos->_next;

	before->_next = after;
	after->_prev = before;

	DestoyNode(&pos);

}

//删除指定值的元素
void DLinkListRemove(DLinkNode* head, DLinkType value) {

	if (head == NULL) {
		//头节点不存在,初始化失败
		return;
	}
	DLinkNode* cur = head->_next;
	while (cur != head) {

		//找到匹配的元素了
		if (cur->data == value) {
			DLinkNode* cur_prev = cur->_prev;
			DLinkNode* cur_next = cur->_next;

			//删除
			cur_prev->_next = cur_next;
			cur_next->_prev = cur_prev;
			return;

		}
		cur = cur->_next;
	}

}

//求出链表的长度
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

//删除所有链表中指定值得元素
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

//判断链表是否为空
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