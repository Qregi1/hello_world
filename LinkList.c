#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkLists.h"


LinkNode* CreatNewNode(LinkType value) {
	//����һ���ڴ�ռ�
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = value;
	p->next = NULL;
	return p;
}
//��ʼ��������
void LinkNodeInit(LinkNode** head) {

	if (head == NULL) {
		return;
	}	
	//û��ͷ�ڵ�
	if (*head == NULL) {
		return;
	}
	*head = CreatNewNode('0');
}

//β��һ��Ԫ��
LinkNode* LinkNodePushBack(LinkNode** head, LinkType value) {

	if (head == NULL) {
		return;
	}
	if (*head == NULL) {
		return;
	}
	LinkNode* NewNode = CreatNewNode(value);
	LinkNode* cur = *head;

	//ѭ����������
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
//βɾһ��Ԫ��
void LinkNodePopBack(LinkNode** head) {

	if (head == NULL) {
		return;
	}
	if (*head == NULL) {
		return;
	}
	LinkNode* cur = *head;
	if (cur->next == NULL) {
		printf("����Ϊ��");
		return;
	}
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	LinkNode* to_delete = cur->next;
	
	//����
	cur->next = NULL;
	//���ٽ��
	DestoryNode(&to_delete);
	to_delete = NULL;
}

/*��ӡ����*/
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
//ɾ���������һ����β���
void LinkNodePopNode(LinkNode* pos) {

	if (pos == NULL) {
		return;
	}

	//����ֵ����
	LinkNode* to_delete = pos->next;
	pos->data = to_delete->data;

	pos->next = to_delete->next;

	//ɾ�����
	DestoryNode(&to_delete);
}
//�����ӡ������
void PrintLinkListReverse(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	LinkNode* cur = head->next;
	LinkNode* node = head->next;


	//����ÿ����㣬Ȼ���ٽ���ͷ��
	while (cur->next != NULL) {

			//�ӵڶ�����㿪ʼͷ��,��ʼ����
			LinkNode* insert = cur->next;
			cur->next = insert->next;


			LinkNode* nextnode = head->next;
			//ͷ��
			head->next = insert;
			insert->next = nextnode;
		}
	
	PrintChar(head, "�����ӡ������");
}

//�ڵ�����һ����ͷ�ڵ�֮ǰ����һ��Ԫ��,�������������
void LinkNodeInsert(LinkNode* pos, LinkType value) {

	if (pos == NULL) {
		return;
	}
	//�����½���pos->data��ֵ�����½����
	LinkNode* NewNode = CreatNewNode(pos->data);
	LinkNode*  pos_next = pos->next;

	//���½���������
	pos->next = NewNode;
	NewNode->next = pos_next;

	pos->data = value;
}
//Լɪ������
LinkNode* JosephCycle(LinkNode* head, int k, int n) {

	if (head == NULL) {
		return;
	}
	//��ͷ�ڵ�ĵ�����
	LinkNode* begin = head;

	//�ӵ�k��Ԫ�ؿ�ʼ
	while (k--) {
		begin = begin->next;
	}

	//��ʼѭ��ɾ��
	while (1) {

		//���ֻ��һ��Ԫ���˾��˳�
		if (begin->next == begin) {
			break;
		}

		int i = 0;
		//ѭ��n-1�Σ��൱�ڴ�1��ʼ��������n��
		for (; i < n - 1; i++) {
			begin = begin->next;
		}

		//��ʼɾ��
		LinkNode* to_delete = begin->next;
		//��ֵɾ��
		begin->data = to_delete->data;
		//������
		begin->next = to_delete->next;
		//���ٽ��
		DestoryNode(&to_delete);

	}
	return begin;

}
///////////////////////////////////////////////
//��ͷ�ڵ�ĵ�����Ļ�������
//////////////////////////////////////////////

//��ʼ��һ����ͷ�ڵ�ĵ�����
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

//��ͷ�ڵ�ĵ��������÷�ת����
void RevereseLinkList(LinkNode** head) {

	if (head == NULL) {
		return;
	}
	LinkNode* cur = *head;

	while(cur->next != NULL) {

		//������
		LinkNode* to_insert = cur->next;
		cur->next = to_insert->next;

		//ͷ��
		LinkNode* for_insert = *head;

		(*head) = to_insert;
		to_insert->next = for_insert;

	}
}
//��ӡ��ͷ�ڵ�ĵ�����
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

//����������ð������
void LinkListBubbleSort(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	//��������ָ��
	LinkNode* prev = NULL;
	LinkNode* next = NULL;
	//βָ��ֵ�������NULLֵ
	LinkNode* tail = NULL;

	while (head != tail) {

		//�Ż����
		int flag = 0;
		//ָ��ĳ�ʼ��
		prev = head;
		next = head->next;
		//ͨ��nextָ��������������ֵð�����
		while (next != tail) {

			//���ǰһ�����ں�һ�����ͽ���������ֵ
			if (prev->data > next->data) {

				//����ֵ����
				LinkType tmp = prev->data;
				prev->data = next->data;
				next->data = tmp;

				flag = 1;
			}
			prev = next;
			next = next->next;
		}
		//���flagΪ0�����������Ѿ����������
		if (flag = 0) {
			return;
		}
		//����β���
		/*βָ�룬��һ���ǿ�ָ�룬�ж������Ƿ�β�գ�
		  ֮��ÿ�δ��������������һ��Ԫ�أ�֪��tail
		  ��head��ȣ������Ѿ����˵�һ��Ԫ�أ���ʾð�������Ѿ����*/
		tail = prev;
	}

}

//����������
void Swap(LinkType* value1, LinkType* value2) {

	LinkType tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}

//���������򣨿�������
/*left��right��ǰ�պ�*/
void QuickSort(LinkNode* left, LinkNode* right) {

	if (left == NULL) {
		return;
	}
	//�ݹ����
	if (left == right || left->next == right) {
		return;
	}

	LinkNode* key = left;

	//��������ָ��
	LinkNode* _prev = left;
	LinkNode* _next = left->next;


	while (_next != right) {
		
		//nextָ����������������С��key��ֵ������prev��ǰ��һ��
		if (_next->data <= key->data) {

			_prev = _prev->next;
			//���prev��next��ȣ����ý���
			if (_prev != _next) {
				Swap(&_prev->data, &_next->data);
			}
		}
		//_nextָ����ǰ��һ��
		_next = _next->next;
	}

	//��һ���Ƚ���Ҫ��
	/*��ʱ��prev֮��Ķ���key�����prevС��key������Ҫ�����߽���������������Ҫ*/
	if (_prev != key) {
		Swap(&_prev->data, &key->data);
	}
	//�����ǰ���Ԫ�ص���

	QuickSort(left, _prev);
	QuickSort(_prev->next, right);
}

//�ϲ���������ͷ��㵥�����ϲ�����Ȼ����
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
	//�ϲ������������Ƚϴ�С����С����Ϊͷ
	LinkNode* cur1 = *head1;
	LinkNode* cur2 = *head2;

	//�жϴ�Сȷ���µ�ͷ�ڵ�
	LinkNode* new_head = NULL;
	if (cur1->data > cur2->data) {
		new_head = cur2;
		cur2 = cur2->next;
	}
	else {
		new_head = cur1;
		cur1 = cur1->next;
	}

	//����һ��β��㷽��β��
	LinkNode* tail = new_head;

	//�жϴ�С��ʼβ��
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
	//����ʣ������
	if (cur1) {
		tail->next = cur1;
	}
	else if(cur2) {
		tail->next = cur2;
	}
	return new_head;
}

//�ϲ����������ݹ飩���ϲ�����Ȼ����
LinkNode* MergeRecursive(LinkNode** head1, LinkNode** head2) {

	//�������ͷ�ڵ���ͬ������ͬһ������ֱ�ӷ���
	if (*head1 == *head2) {
		return *head1;
	}
	//���һ��Ϊ�գ���ֱ�ӷ�����һ��
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
	//�����������ͷ�ڵ�
	LinkNode* newhead = NULL;

	//�Ƚ�����ͷ���ֵ�Ĵ�С��Ȼ����еݹ�,֪��ĳһ��ΪNULL
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

//����������м��㣬Ҫ��ֻ�ܱ���һ������
LinkNode* FindMidNode(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	//�������ָ��
	LinkNode* low = head;
	LinkNode* fast = head;

	/*ѭ����������*/
	//fast->nextҲ���ܵ���NULL
	while (fast && fast->next) {
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

//���ҵ�����ĵ�����k����㣬Ҫ��ֻ�ܱ���һ������
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

//�ж������Ƿ���������������󻷵ĳ��Ⱥ��������,����������1
size_t CheckCycle(LinkNode* head, LinkNode** MeetNode) {

	if (head == NULL) {
		return;
	}

	//�������ָ��
	LinkNode* low = head;
	LinkNode* fast = head;

	while (fast && fast->next) {

		low = low->next;
		fast = fast->next->next;

		//�������ָ�����������ʾ�л�
		if (low == fast) {
			//��Ϊָ��ָ��Ҫ�仯�������Ƕ���ָ��
			*MeetNode = low;
			size_t length = 1;
			//��ʱ��Ҫ��lowָ������,ֱ��lowָ����fastָ������
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
//��������ָ�룬һ���������㿪ʼ�ߣ�
//һ����ͷ��ʼ�ߣ���һ����������Ϊ��ڵ�
LinkNode* FindEntryNode1(LinkNode* head) {

	if (head == NULL) {
		return;
	}
	LinkNode* low = head;
	LinkNode* fast = head;

	//ͨ������ָ�����ҵ�������
	while (fast && fast->next) {
		low = low->next;
		fast = fast->next->next;

		//�ҵ�������
		if (low == fast) {
			break;
		}
	}
	//һ����ͷ��ʼ�ߣ�һ���������㿪ʼ�ߣ����ʱ�ĵ�Ϊ��������ڵ�
	LinkNode* cur = head;
	while (cur != low) {
		cur = cur->next;
		low = low->next;
	}
	return cur;
}
//��������Ͽ�����ת��Ϊ�����������󽻵�
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

	//�����������󽻵�
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

//�����ཻ����
int CheckCross(LinkNode* head1, LinkNode* head2, LinkNode** CrossNode) {

	if (head1 == NULL) {
		return;
	}
	if (head2 == NULL) {
		return;
	}
	/*�ж����������������*/
	LinkNode* MeetNode1 = NULL;
	LinkNode* MeetNode2 = NULL;

	size_t length1 = CheckCycle(head1, &MeetNode1);
	size_t length2 = CheckCycle(head2, &MeetNode2);

	//1.��������������
	//�������ཻ����
	/*������ַ�����1.�����ָ���ཻ�������ǵ�β���һ����ͬ
	*             2.����һ����������������β���ָ����һ�������ͷ�ڵ㣬���ڱ�Ϊ���������������
	*/
	if (length1 == 1 && length2 == 1) {
		/*�����õڶ��ַ���*/
		LinkNode* cur1 = head2;
		//������������cur1Ϊhead1��������һ��Ԫ��
		while (cur1->next) {
			cur1 = cur1->next;
		}
		cur1->next = head2;
		/*
		*����ת��Ϊhead1�����������
		*����л����������������ཻ������Ϊ������ڵ㣬��֮���ཻ
		*/
		LinkNode* meet = NULL;
		size_t len = CheckCycle(head1, &meet);
		if (len == 1) {
			printf("�������������������Ҳ��ཻ");
			return -1;
		}
		else {
			/*��������������ǻ�����ڵ�*/
			*CrossNode = FindEntryNode1(head1);
			printf("�����������������ཻ");
			return 1;
		}
	}
	//2.������
	else if (length1 != 1 && length2 != 1) {
		/*
		*�����������ཻ���ཻ�������ڻ��⣬�����ڻ��ϣ������ڻ�����ڵ������㣩
		*/
		
		//�Ͽ�һ������Ļ����ж���һ���������������������������ܲ��ཻ�������ǽ����ڻ���
		LinkNode* Entry1 = FindEntryNode1(head1);

		LinkNode* meet1 = NULL;
		size_t cycle1 = CheckCycle(head1, &meet1);

		LinkNode* cur1 = head1;
		//�Ͽ�����1�Ļ�
		while (cur1->next != Entry1) {
			cur1 = cur1->next;
		}
		cur1->next = NULL;
		LinkNode* meet2 = NULL;
		size_t cycle2 = CheckCycle(head2, &meet2);
		//����2�������ˣ���ʾ�����������ཻ��
		if (cycle2 == 1) {

			/*��������Ļ�����ڵ���ȵģ�ת��Ϊ��������������ཻ����*/
			//cur1����Ϊ��������һ��,��Ϊ����2�������ˣ���ô�ཻ��϶���cur1֮ǰ������cur1���п���
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
			printf("�������������������ڻ���");
			return 1;
		}
		/*��Ϊ�Ͽ��ĵ�����ڵ��ǰһ���㣬����ཻ���ڻ�����ڵ�Ļ�������2���Ǵ�����*/
		/*�������
		1.Ҫô�����ڻ���
		2.Ҫô�����ڻ�����ڵ�
		3.Ҫô���ཻ*/
		else {
			//�õ�����2����ڵ�
			LinkNode* Entry2 = FindEntryNode1(head2);
			/*�Ա�Entry1��Entry2�������ȱ�ʾ��������ڵ���*/
			/*�������ȣ���������2�Ļ������������ȣ���������ȵĵ㣬���ʾ����������*/
			if (Entry1 == Entry2 && cycle1 == cycle2) {
				/*��ʵֻ��Ҫ�ж�ǰһ�������͹���*/
				*CrossNode = Entry1;
				printf("���������������ཻ�������ڻ�����ڵ㴦");
				return 1;
			}
			else {
				LinkNode* cur2 = Entry2;
				//���Ż���һȦ�������entry1Ҳ�ڻ��ϣ���ʾ�������ཻ
				while (cycle2--) {
					cur2 = cur2->next;
					if (cur2 == Entry1) {
						printf("���������������ཻ�������ڻ��ϣ���������������ڵ�");
						return 1;
					}
				}
				//����һȦ��û�з�������1����ڵ�������2�Ļ��ϣ���ʾ�������������Ҳ��ཻ
				printf("�����������������ǲ��ཻ");
				return -1;
			}
		}
	}
	//3.һ��������һ��������
	else {
		printf("��������һ��������һ�������������ཻ");
		return -1;
	}
}

/*����һ����������Ľ��*/
ComplexeNode* CreatComplexeNode(LinkType data) {

	ComplexeNode* tmp = (ComplexeNode*)malloc(sizeof(ComplexeNode));
	/*��ʼ����������*/
	tmp->data = data;
	tmp->_next = NULL;
	tmp->_random = NULL;
	return tmp;
}

/*����һ����������*/
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
/*��ӡһ����������*/
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
/*��������ĸ���*/
ComplexeNode* CopyCompexeList(ComplexeNode* cplist) {

	if (cplist == NULL) {
		return;
	}
	/*����һ������random�Ȳ���ᣬ�Ȳ��뵽����*/
	ComplexeNode* head = cplist;
	while (head) {
		/*�����µĽ��׼������*/
		ComplexeNode* tmp = CreatComplexeNode(head->data);
		/*����һ��prevָ����������*/
		ComplexeNode* prev = head;
		head = head->_next;

		prev->_next = tmp;
		tmp->_next = head;
	}
	/*ԭ�����random->next�����������random*/
	/*���Ը���random*/

	head = cplist;//��head��ʼ��Ϊ���������ͷ�ڵ�
	while (head) {
		ComplexeNode* random = head->_random;
		ComplexeNode* next = head->_next;

		//random�ĸ���
		next->_random = random->_next;

		head = head->_next->_next;
	}

	/*Ȼ��������*/
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
	//���һ��ûɾ��
	cur1->_next = NULL;

	return newhead;
}

// �������������  
//  
//1. �Ƚ�˳�����������ȱ�㣬˵˵���Ƿֱ���ʲô������ʹ�ã�  
//2. ��β��ͷ��ӡ������  
//3. ɾ��һ����ͷ������ķ�β�ڵ�  
//4. ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�  
//5. ������ʵ��Լɪ��  
//6. ����/��ת������  
//7. ����������ð������&��������  
//8. �ϲ�������������,�ϲ�����Ȼ����  
//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������  
//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������  
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�  
//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������  
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿  
//14. ��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
//    ����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������  