#pragma once 

#include <iostream>
#include <cassert>
using namespace std;

typedef int DataType;

//��C++ʵ��һ����������Ľڵ�
typedef struct ListNode {
	ListNode* _prev;
	ListNode* _next;

	DataType value;
	
	ListNode(DataType x)
		:value(x)
		, _prev(NULL)
		, _next(NULL)
	{}
}Node;

class List {
public:
	//���캯��
	//DataType()
	List()
		:_head(new Node(DataType()))
	{
		_head->_prev = _head;
		_head->_next = _head;
	}
	//�������캯��
	List(const List& l) {
		_head = new Node(DataType());
		_head->_prev = _head;
		_head->_next = _head;

		//��������l
		Node* cur = l._head->_next;
		while (cur != l._head) {
			PushBack(cur->value);
			cur = cur->_next;
		}
	}
	//�������캯��
	List& operator=(const List& l){
		if (this != &l) {
			//�ȰѾɵ�ɾ��
			clear();
			//��������l����ÿ���ڵ㶼����ǰ����װ��	
			Node* cur = l._head->_next;
			while (cur != l._head) {
				PushBack(cur->value);
				cur = cur->_next;
			}
		}
		return *this;
	}
	//��������
	~List() {
		clear();
		delete _head;
		_head = NULL;
	}
	//������
	void clear() {
		Node* cur = _head->_next;
		while (cur != _head) {
			Node* cur_next = cur->_next;
			//��������Ȼ���ж���ͷų�ͷ���֮��Ľڵ�
			delete cur;
			cur = cur_next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	//β��һ��Ԫ��
	void PushBack(DataType x) {
		Insert(_head->_prev, x);
	}
	//ͷ��һ��Ԫ��
	void PushFront(DataType x) {
		Insert(_head->_next, x);
	}
	//βɾһ��Ԫ��
	void PopBack() {
		Erase(_head->_prev);
	}
	//ͷɾһ��Ԫ��
	void PopFront() {
		Erase(_head->_next);
	}
	Node* Find(DataType x) {
		Node* cur = _head->_next;
		while (cur != _head) {
			if (cur->value == x) {
				return cur;
			}
			cur = cur->_next;
		}
		//û�ҵ��ͷ��ؿ�ֵ
		return NULL;
	}
	//�ڽڵ�pos֮ǰ����
	void Insert(Node* pos, DataType x) {
		assert(pos);
		Node* insert_node = new Node(x);
		Node* pos_prev = pos->_prev;

		//����ڵ�
		pos_prev->_next = insert_node;
		insert_node->_prev = pos_prev;

		insert_node->_next = pos;
		pos->_prev = insert_node;
	}
	//ɾ����ǰλ�õĽڵ�
	void Erase(Node* pos) {
		assert(pos && pos != _head);
		Node* pos_prev = pos->_prev;
		Node* pos_next = pos->_next;

		//�ѽڵ�������в��
		pos_prev->_next = pos_next;
		pos_next->_prev = pos_prev;

		delete pos;
	}
private:
	Node* _head;
};

