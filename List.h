#pragma once 

#include <iostream>
#include <cassert>
using namespace std;

typedef int DataType;

//用C++实现一个链表，链表的节点
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
	//构造函数
	//DataType()
	List()
		:_head(new Node(DataType()))
	{
		_head->_prev = _head;
		_head->_next = _head;
	}
	//拷贝构造函数
	List(const List& l) {
		_head = new Node(DataType());
		_head->_prev = _head;
		_head->_next = _head;

		//遍历对象l
		Node* cur = l._head->_next;
		while (cur != l._head) {
			PushBack(cur->value);
			cur = cur->_next;
		}
	}
	//拷贝构造函数
	List& operator=(const List& l){
		if (this != &l) {
			//先把旧的删除
			clear();
			//遍历链表l并把每个节点都给当前链表装上	
			Node* cur = l._head->_next;
			while (cur != l._head) {
				PushBack(cur->value);
				cur = cur->_next;
			}
		}
		return *this;
	}
	//析构函数
	~List() {
		clear();
		delete _head;
		_head = NULL;
	}
	//清理函数
	void clear() {
		Node* cur = _head->_next;
		while (cur != _head) {
			Node* cur_next = cur->_next;
			//遍历链表然后拆卸并释放除头结点之外的节点
			delete cur;
			cur = cur_next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	//尾插一个元素
	void PushBack(DataType x) {
		Insert(_head->_prev, x);
	}
	//头插一个元素
	void PushFront(DataType x) {
		Insert(_head->_next, x);
	}
	//尾删一个元素
	void PopBack() {
		Erase(_head->_prev);
	}
	//头删一个元素
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
		//没找到就返回空值
		return NULL;
	}
	//在节点pos之前插入
	void Insert(Node* pos, DataType x) {
		assert(pos);
		Node* insert_node = new Node(x);
		Node* pos_prev = pos->_prev;

		//插入节点
		pos_prev->_next = insert_node;
		insert_node->_prev = pos_prev;

		insert_node->_next = pos;
		pos->_prev = insert_node;
	}
	//删除当前位置的节点
	void Erase(Node* pos) {
		assert(pos && pos != _head);
		Node* pos_prev = pos->_prev;
		Node* pos_next = pos->_next;

		//把节点从链表中拆除
		pos_prev->_next = pos_next;
		pos_next->_prev = pos_prev;

		delete pos;
	}
private:
	Node* _head;
};

