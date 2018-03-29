#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkLists.h"


LinkNode* CreatNewNode(LinkType value) {
	//申请一段内存空间
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = value;
	p->next = NULL;
	return p;
}
//初始化单链表
void LinkNodeInit(LinkNode** head) {

	if (head == NULL) {
		return;
	}	
	//没有头节点
	if (*head == NULL) {
		return;
	}
	*head = CreatNewNode('0');
}

//尾插一个元素
LinkNode* LinkNodePushBack(LinkNode** head, LinkType value) {

	if (head == NULL) {
		return;
	}
	if (*head == NULL) {
		return;
	}
	LinkNode* NewNode = CreatNewNode(value);
	LinkNode* cur = *head;

	//循环遍历链表
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = NewNode;
	return NewNode;
}
void DestoryNode(LinkNode** node) {

	if (node == NULL) {
		return;
	}
	if (*node == NULL) {
		return;
	}
	free(*node);
	*node = NULL;
}
//尾删一个元素
void LinkNodePopBack(LinkNode** head) {

	if (head == NULL) {
		return;
	}
	if (*head == NULL) {
		return;
	}
	LinkNode* cur = *head;
	if (cur->next == NULL) {
		printf("链表为空");
		return;
	}
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	LinkNode* to_delete = cur->next;
	
	//拆结点
	cur->next = NULL;
	//销毁结点
	DestoryNode(&to_delete);
	to_delete = NULL;
}

/*打印链表*/
void PrintChar(LinkNode* head, char* msg) {

	if (head == NULL) {
		return;
	}
	printf("%s\n", msg);
	printf("\n\n[head]->");
	LinkNode* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
		printf("[%c]->", cur->data);
	}
	printf("NULL\n\n\n");
}
//删除单链表的一个非尾结点
void LinkNodePopNode(LinkNode* pos) {

	if (pos == NULL) {
		return;
	}

	//进行值传递
	LinkNode* to_delete = pos->next;
	pos->data = to_delete->data;

	pos->next = to_delete->next;

	//删除结点
	DestoryNode(&to_delete);
}
//逆序打印单链表
void PrintLinkListReverse(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	LinkNode* cur = head->next;
	LinkNode* node = head->next;


	//拆下每个结点，然后再进行头插
	while (cur->next != NULL) {

			//从第二个结点开始头插,开始拆结点
			LinkNode* insert = cur->next;
			cur->next = insert->next;


			LinkNode* nextnode = head->next;
			//头插
			head->next = insert;
			insert->next = nextnode;
		}
	
	PrintChar(head, "逆序打印单链表");
}

//在单链表一个非头节点之前插入一个元素,不允许遍历链表
void LinkNodeInsert(LinkNode* pos, LinkType value) {

	if (pos == NULL) {
		return;
	}
	//创建新结点把pos->data的值放入新结点中
	LinkNode* NewNode = CreatNewNode(pos->data);
	LinkNode*  pos_next = pos->next;

	//把新结点插入链表
	pos->next = NewNode;
	NewNode->next = pos_next;

	pos->data = value;
}
//约瑟夫环问题
LinkNode* JosephCycle(LinkNode* head, int k, int n) {

	if (head == NULL) {
		return;
	}
	//无头节点的单链表
	LinkNode* begin = head;

	//从第k个元素开始
	while (k--) {
		begin = begin->next;
	}

	//开始循环删除
	while (1) {

		//如果只有一个元素了就退出
		if (begin->next == begin) {
			break;
		}

		int i = 0;
		//循环n-1次，相当于从1开始数，数了n次
		for (; i < n - 1; i++) {
			begin = begin->next;
		}

		//开始删除
		LinkNode* to_delete = begin->next;
		//传值删除
		begin->data = to_delete->data;
		//拆除结点
		begin->next = to_delete->next;
		//销毁结点
		DestoryNode(&to_delete);

	}
	return begin;

}
///////////////////////////////////////////////
//无头节点的单链表的基本操作
//////////////////////////////////////////////

//初始化一个无头节点的单链表
void InitWithJosephy(LinkNode** head) {

	if (head == NULL) {
		return;
	}

	(*head) = NULL;
}

LinkNode* PushBack(LinkNode** head, LinkType value) {

	if (head == NULL) {
		return;
	}

	LinkNode* NewNode = CreatNewNode(value);

	if (*head == NULL) {

		*head = NewNode;
	}
	else {

		LinkNode* cur = (*head);
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = NewNode;
	}
	return NewNode;
}

//无头节点的单链表逆置反转链表
void RevereseLinkList(LinkNode** head) {

	if (head == NULL) {
		return;
	}
	LinkNode* cur = *head;

	while(cur->next != NULL) {

		//拆除结点
		LinkNode* to_insert = cur->next;
		cur->next = to_insert->next;

		//头插
		LinkNode* for_insert = *head;

		(*head) = to_insert;
		to_insert->next = for_insert;

	}
}
//打印无头节点的单链表
void PrintCharWithoutHead(LinkNode* head, char* msg) {

	if (head == NULL) {
		return;
	}
	printf("%s\n\n", msg);
	printf("[head]->");

	LinkNode* cur = head;
	while (cur != NULL) {

		printf("[%c]->", cur->data);
		cur = cur->next;

	}
	printf("NULL\n\n\n\n");
}

//单链表排序（冒泡排序）
void LinkListBubbleSort(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	//定义三个指针
	LinkNode* prev = NULL;
	LinkNode* next = NULL;
	//尾指针值得是最后NULL值
	LinkNode* tail = NULL;

	while (head != tail) {

		//优化标记
		int flag = 0;
		//指针的初始化
		prev = head;
		next = head->next;
		//通过next指针遍历链表把最大的值冒到最后
		while (next != tail) {

			//如果前一个大于后一个，就交换他俩的值
			if (prev->data > next->data) {

				//进行值交换
				LinkType tmp = prev->data;
				prev->data = next->data;
				next->data = tmp;

				flag = 1;
			}
			prev = next;
			next = next->next;
		}
		//如果flag为0，代表链表已经是有序的了
		if (flag = 0) {
			return;
		}
		//更新尾标记
		/*尾指针，第一次是空指针，判断链表是否尾空，
		  之后每次代表的是链表的最后一个元素，知道tail
		  与head相等，代表已经到了第一个元素，表示冒泡排序已经完成*/
		tail = prev;
	}

}

//交换两个数
void Swap(LinkType* value1, LinkType* value2) {

	LinkType tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}

//单链表排序（快速排序）
/*left和right是前闭后开*/
void QuickSort(LinkNode* left, LinkNode* right) {

	if (left == NULL) {
		return;
	}
	//递归出口
	if (left == right || left->next == right) {
		return;
	}

	LinkNode* key = left;

	//定义两个指针
	LinkNode* _prev = left;
	LinkNode* _next = left->next;


	while (_next != right) {
		
		//next指针遍历链表，如果遇到小于key的值，就让prev往前走一步
		if (_next->data <= key->data) {

			_prev = _prev->next;
			//如果prev与next相等，则不用交换
			if (_prev != _next) {
				Swap(&_prev->data, &_next->data);
			}
		}
		//_next指针往前走一步
		_next = _next->next;
	}

	//这一步比较重要！
	/*此时，prev之后的都比key大，如果prev小于key，就需要将两者交换，如果相等则不需要*/
	if (_prev != key) {
		Swap(&_prev->data, &key->data);
	}
	//如果当前这个元素等于

	QuickSort(left, _prev);
	QuickSort(_prev->next, right);
}

//合并两个不带头结点单链表，合并后依然有序
LinkNode* Merge(LinkNode** head1, LinkNode** head2) {

	if (head1 == NULL) {
		return;
	}
	if (head2 == NULL) {
		return;
	}

	if (*head1 == NULL) {
		return *head2;
	}
	if (*head2 == NULL) {
		return *head1;
	}
	//合并两个单链表，比较大小，以小的作为头
	LinkNode* cur1 = *head1;
	LinkNode* cur2 = *head2;

	//判断大小确定新的头节点
	LinkNode* new_head = NULL;
	if (cur1->data > cur2->data) {
		new_head = cur2;
		cur2 = cur2->next;
	}
	else {
		new_head = cur1;
		cur1 = cur1->next;
	}

	//定义一个尾结点方便尾插
	LinkNode* tail = new_head;

	//判断大小开始尾插
	while (cur1 && cur2) {

		if (cur1->data > cur2->data) {
			tail->next = cur2;
			cur2 = cur2->next;

			tail = tail->next;
		}
		else {
			tail->next = cur1;
			cur1 = cur1->next;

			tail = tail->next;

		}
	}
	//链接剩余链表
	if (cur1) {
		tail->next = cur1;
	}
	else if(cur2) {
		tail->next = cur2;
	}
	return new_head;
}

//合并两个链表（递归），合并后依然有序
LinkNode* MergeRecursive(LinkNode** head1, LinkNode** head2) {

	//如果两个头节点相同，则是同一个链表，直接返回
	if (*head1 == *head2) {
		return *head1;
	}
	//如过一个为空，则直接返回另一个
	if (head1 == NULL) {
		return;
	}
	if (head2 == NULL) {
		return;
	}
	if (*head1 == NULL) {
		return *head2;
	}
	if (*head2 == NULL) {
		return *head1;
	}
	//定义新链表的头节点
	LinkNode* newhead = NULL;

	//比较两个头结点值的大小，然后进行递归,知道某一个为NULL
	if ((*head1)->data < (*head2)->data) {

		newhead = *head1;
		newhead->next = MergeRecursive(&(*head1)->next, &(*head2));

	}
	else {

		newhead = *head2;
		newhead->next = MergeRecursive(&(*head1), &((*head2)->next));

	}

	return newhead;

}

//查找链表的中间结点，要求只能遍历一次链表
LinkNode* FindMidNode(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	//定义快慢指针
	LinkNode* low = head;
	LinkNode* fast = head;

	/*循环遍历链表*/
	//fast->next也不能等于NULL
	while (fast && fast->next) {
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

//查找单链表的倒数第k个结点，要求只能遍历一次链表
LinkNode* FindKNode(LinkNode* head, int k) {

	if (head == NULL) {
		return;
	}
	LinkNode* low = head;
	LinkNode* fast = head;

	while (k--) {
		fast = fast->next;
	}

	while (fast && fast->next) {
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

//判断链表是否带环，若带环，求环的长度和相遇结点,不带环返回1
size_t CheckCycle(LinkNode* head, LinkNode** MeetNode) {

	if (head == NULL) {
		return;
	}

	//定义快慢指针
	LinkNode* low = head;
	LinkNode* fast = head;

	while (fast && fast->next) {

		low = low->next;
		fast = fast->next->next;

		//如果两个指针相遇，则表示有环
		if (low == fast) {
			//因为指针指向要变化，所以是二级指针
			*MeetNode = low;
			size_t length = 1;
			//这时候要让low指针先走,直到low指针与fast指针相遇
			low = low->next;
			while (fast != low) {
				low = low->next;
				length++;
			}
			return length;
		}

	}
	return 1;
}
//定义两个指针，一个从相遇点开始走，
//一个从头开始走，第一次相遇点则为入口点
LinkNode* FindEntryNode1(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	LinkNode* low = head;
	LinkNode* fast = head;

	//通过快慢指针来找到相遇点
	while (fast && fast->next) {
		low = low->next;
		fast = fast->next->next;

		//找到相遇点
		if (low == fast) {
			break;
		}
	}
	//一个从头开始走，一个从相遇点开始走，相等时的点为链表环的入口点
	LinkNode* cur = head;
	while (cur != low) {
		cur = cur->next;
		low = low->next;
	}
	return cur;
}
//从相遇点断开，则转化为两个单链表求交点
LinkNode* FindEntryNode2(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	LinkNode* low = head;
	LinkNode* fast = head;
	LinkNode* MeetNode = NULL;

	while (fast && fast->next) {

		low = low->next;
		fast = fast->next->next;
		if (low == fast) {
			MeetNode = low;
			break;
		}
	}
	LinkNode* head2 = MeetNode->next;
	MeetNode->next = NULL;

	//两个单链表求交点
	int length = 0;
	int length2 = 0;
	LinkNode* cur1 = head;
	LinkNode* cur2 = head2;
	while (cur1) {
		cur1 = cur1->next;
		++length;
	}
	cur1 = head;
	while (cur2) {
		cur2 = cur2->next;
		++length2;
	}
	cur2 = head2;
	int Dif = 0;
	if (length > length2) {
		Dif = length - length2;
		while (Dif--) {
			cur1 = cur1->next;
		}
	}
	else {
		Dif = length2 - length;
		while (Dif--) {
			cur2 = cur2->next;
		}
	}
	while (cur1 != cur2) {
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;

}

//链表相交问题
int CheckCross(LinkNode* head1, LinkNode* head2, LinkNode** CrossNode) {

	if (head1 == NULL) {
		return;
	}
	if (head2 == NULL) {
		return;
	}
	/*判断两个链表带不带环*/
	LinkNode* MeetNode1 = NULL;
	LinkNode* MeetNode2 = NULL;

	size_t length1 = CheckCycle(head1, &MeetNode1);
	size_t length2 = CheckCycle(head2, &MeetNode2);

	//1.两个链表都不带环
	//单链表相交问题
	/*会的两种方法，1.如果两指针相交，则他们的尾结点一定相同
	*             2.遍历一个链表，让这个链表的尾结点指向另一个链表的头节点，现在变为链表带不带环问题
	*/
	if (length1 == 1 && length2 == 1) {
		/*这里用第二种方法*/
		LinkNode* cur1 = head2;
		//遍历链表，现在cur1为head1链表的最后一个元素
		while (cur1->next) {
			cur1 = cur1->next;
		}
		cur1->next = head2;
		/*
		*现在转变为head1链表的求环问题
		*如果有环，代表两个链表相交，交点为环的入口点，反之则不相交
		*/
		LinkNode* meet = NULL;
		size_t len = CheckCycle(head1, &meet);
		if (len == 1) {
			printf("两个链表都不带环，而且不相交");
			return -1;
		}
		else {
			/*链表带环，交点是环的入口点*/
			*CrossNode = FindEntryNode1(head1);
			printf("两个链表都不带环，相交");
			return 1;
		}
	}
	//2.都带环
	else if (length1 != 1 && length2 != 1) {
		/*
		*都带环，不相交，相交（交点在环外，交点在环上，交点在环的入口点三个点）
		*/
		
		//断开一个链表的环，判断另一个还带不带环，如果带环，则可能不相交，或者是交点在环上
		LinkNode* Entry1 = FindEntryNode1(head1);

		LinkNode* meet1 = NULL;
		size_t cycle1 = CheckCycle(head1, &meet1);

		LinkNode* cur1 = head1;
		//断开链表1的环
		while (cur1->next != Entry1) {
			cur1 = cur1->next;
		}
		cur1->next = NULL;
		LinkNode* meet2 = NULL;
		size_t cycle2 = CheckCycle(head2, &meet2);
		//链表2不带环了，表示两个链表是相交的
		if (cycle2 == 1) {

			/*两个链表的环的入口点相等的，转化为求两个单链表的相交问题*/
			//cur1现在为链表的最后一个,因为链表2不带环了，那么相交点肯定在cur1之前，包括cur1都有可能
			LinkNode* curr1 = head1;
			LinkNode* curr2 = head2;
			int len1 = 0;
			int len2 = 0;
			while (curr1) {
				curr1 = curr1->next;
				++len1;
			}
			curr1 = head1;
			while (curr2) {
				curr2 = curr2->next;
				++len2;
			}
			curr2 = head2;
			int dif = 0;
			if (len1 > len2) {
				dif = len1 - len2;
				while (dif--) {
					curr1 = curr1->next;
				}
			}
			else {
				dif = len2 - len1;
				while (dif--) {
					curr2 = curr2->next;
				}
			}
			while (curr1 != curr2) {
				curr1 = curr1->next;
				curr2 = curr2->next;
			}
			*CrossNode = curr1;
			printf("两个链表都带环，交点在环外");
			return 1;
		}
		/*因为断开的点是入口点的前一个点，如果相交点在环的入口点的话，链表2还是带环的*/
		/*链表带环
		1.要么交点在环上
		2.要么交点在环的入口点
		3.要么不相交*/
		else {
			//得到链表2的入口点
			LinkNode* Entry2 = FindEntryNode1(head2);
			/*对比Entry1和Entry2，如果相等表示交点在入口点上*/
			/*如果不相等，遍历链表2的环，如果长度相等，而且有相等的点，则表示有两个交点*/
			if (Entry1 == Entry2 && cycle1 == cycle2) {
				/*其实只需要判断前一个条件就够了*/
				*CrossNode = Entry1;
				printf("两个链表都带环，相交，交点在环的入口点处");
				return 1;
			}
			else {
				LinkNode* cur2 = Entry2;
				//绕着环走一圈，如果有entry1也在环上，表示两个环相交
				while (cycle2--) {
					cur2 = cur2->next;
					if (cur2 == Entry1) {
						printf("两个链表都带环，相交，交点在环上，是两个链表环的入口点");
						return 1;
					}
				}
				//走了一圈，没有发现链表1的入口点在链表2的环上，表示两个链表都带环且不相交
				printf("两个链表都带环，但是不相交");
				return -1;
			}
		}
	}
	//3.一个带环，一个不带环
	else {
		printf("两个链表一个带环，一个不带环，不相交");
		return -1;
	}
}

/*创建一个复杂链表的结点*/
ComplexeNode* CreatComplexeNode(LinkType data) {

	ComplexeNode* tmp = (ComplexeNode*)malloc(sizeof(ComplexeNode));
	/*初始化复杂链表*/
	tmp->data = data;
	tmp->_next = NULL;
	tmp->_random = NULL;
	return tmp;
}

/*创建一个复杂链表*/
void CreatComplexeList(ComplexeNode** head) {

	if (head == NULL) {
		return;
	}

	ComplexeNode* n1 = CreatComplexeNode('a');
	ComplexeNode* n2 = CreatComplexeNode('b');
	ComplexeNode* n3 = CreatComplexeNode('c');
	ComplexeNode* n4 = CreatComplexeNode('d');
	ComplexeNode* n5 = CreatComplexeNode('e');

	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	n4->_next = n5;
	n5->_next = NULL;

	n1->_random = n3;
	n2->_random = n1;
	n3->_random = n5;
	n4->_random = n2;
	n5->_random = n5;

	*head = n1;
}
/*打印一个复杂链表*/
void PrintComplexeList(ComplexeNode* head) {

	if (head == NULL) {
		return;
	}
	while (head) {

		printf("\n[%c]", head->data);
		printf(":[random]->[%c]", head->_random->data);
		printf(":[next]->");

		head = head->_next;
	}
	printf("NULL\n\n");

}
/*复杂链表的复制*/
ComplexeNode* CopyCompexeList(ComplexeNode* cplist) {

	if (cplist == NULL) {
		return;
	}
	/*复制一个链表，random先不理会，先插入到里面*/
	ComplexeNode* head = cplist;
	while (head) {
		/*创建新的结点准备插入*/
		ComplexeNode* tmp = CreatComplexeNode(head->data);
		/*定义一个prev指针用作插入*/
		ComplexeNode* prev = head;
		head = head->_next;

		prev->_next = tmp;
		tmp->_next = head;
	}
	/*原链表的random->next就是新链表的random*/
	/*所以复制random*/

	head = cplist;//把head初始化为合体链表的头节点
	while (head) {
		ComplexeNode* random = head->_random;
		ComplexeNode* next = head->_next;

		//random的复制
		next->_random = random->_next;

		head = head->_next->_next;
	}

	/*然后拆除链表*/
	head = cplist;
	ComplexeNode* newhead;
	ComplexeNode* oldhead;

	oldhead = head;
	newhead = head->_next;

	ComplexeNode* cur1 = head;
	ComplexeNode* cur2 = head->_next;

	while (cur2 && cur2->_next) {
		cur1->_next = cur2->_next;
		cur1 = cur1->_next;

		cur2->_next = cur1->_next;
		cur2 = cur2->_next;
	}
	//最后一个没删除
	cur1->_next = NULL;

	return newhead;
}

// 链表相关面试题  
//  
//1. 比较顺序表和链表的优缺点，说说它们分别在什么场景下使用？  
//2. 从尾到头打印单链表  
//3. 删除一个无头单链表的非尾节点  
//4. 在无头单链表的一个非头节点前插入一个节点  
//5. 单链表实现约瑟夫环  
//6. 逆置/反转单链表  
//7. 单链表排序（冒泡排序&快速排序）  
//8. 合并两个有序链表,合并后依然有序  
//9. 查找单链表的中间节点，要求只能遍历一次链表  
//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表  
//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。  
//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环）  
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】  
//14. 复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
//    还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。  