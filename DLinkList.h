#pragma once

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
struct ListNode {
	ListNode(const T& x = T())
	:_prev(NULL)
	, _next(NULL)
	, data(x)
	{}
	~ListNode()
	{}
public:
	T data;
	ListNode<T>* _prev;
	ListNode<T>* _next;
};

template<typename T>
class List{
	typedef ListNode<T> Node;
public:
	List()
		:_head(new	Node()) {
		_head->_prev = _head;
		_head->_next = _head;
	}
	List(const List& s);
	List<T>& operator=(List<T> s);
	~List();
	void clear();

	void PushBack(const T& x);
	void PopsBack();
	
	void PushFront(const T& x);
	void PopFront();
	void Insert(Node* pos, const T& x);
	void Erase(Node* pos);
	void Display();
	size_t ListSize();
	
	//实现栈的接口
	void PopBack() {
		PopsBack();
	}
	size_t Size() {
		return ListSize();
	}
	const T& LastNodeValue() {
		return _head->_prev->data;
	}
	//实现队列的接口
	const T& FirstNodeValue() {
		return _head->_next->data;
	}
	
	//测试Insert
	//在链表中第n个节点插入一个元素x
	void InsertSomeNode(int n, const T& x);
	//测试Erase
	void EraseSomeNode(int n);
private:
	Node* _head;
};

/////////////////////////////////////////////////////
//类的函数实现
/////////////////////////////////////////////////////
template<typename T>
List<T>::List(const List& s) {
	_head = new Node();
	_head->_prev = _head;
	_head->_next = _head;

	Node* cur = s._head->_next;
	while (cur != s._head) {
		Node* InsertNode = new Node(cur->data);

		InsertNode->_prev = _head->_prev;
		_head->_prev->_next = InsertNode;

		InsertNode->_next = _head;
		_head->_prev = InsertNode;

		cur = cur->_next;
	}
}

template<typename T>
List<T>& List<T>::operator=(List<T> s) {
	if (this != &s) {
		swap(_head, s._head);
	}
	return *this;
}

//清理除了头结点之外的节点
template<typename T>
void List<T>::clear() {
	Node* cur = _head->_next;
	while (cur != _head) {
		Node* cur_next = cur->_next;
		//拆节点
		cur->_prev->_next = cur->_next;
		cur->_next->_prev = cur->_prev;
		//释放拆下来的节点
		delete cur;
		//更新cur
		cur = cur_next;
	}
}

template<typename T>
List<T>::~List() {
	clear();

	delete _head;
	_head = NULL;
}

//在pos位置之前插入节点
template<typename T>
void List<T>::Insert(Node* pos, const T& x) {
	if (pos == NULL) {
		printf("pos参数传 入错误!\n");
		return;
	}
	Node* InsertNode = new Node(x);
	/*
	**这里的方法是在pos之后插入
	InsertNode->_prev = pos;
	InsertNode->_next = pos->_next;

	pos->_next->_prev = InsertNode;
	pos->_next = InsertNode;
	*/
	//在pos之前插入
	InsertNode->_next = pos;
	InsertNode->_prev = pos->_prev;

	pos->_prev->_next = InsertNode;
	pos->_prev = InsertNode;
}

template<typename T>
void List<T>::Erase(Node* pos) {
	if (pos == NULL || pos == _head) {
		printf("pos参数传入错误!\n");
		return;
	}

	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;

	delete pos;
}

template<typename T>
void List<T>::PushBack(const T& x) {
	Insert(_head, x);
}
template<typename T>
void List<T>::PopsBack() {
	Erase(_head->_prev);
}

template<typename T>
void List<T>::PushFront(const T& x) {
	Insert(_head->_next, x);
}

template<typename T>
void List<T>::PopFront() {
	Erase(_head->_next);
}

template<typename T>
void List<T>::Display() {
	Node* cur = _head->_next;
	printf("[head]->");
	while (cur != _head) {
		cout << "[" << cur->data << "]->";
		cur = cur->_next;
	}
	cout << "[head]" << endl;
}

template<typename T>
size_t List<T>::ListSize() {
	Node* cur = _head->_next;
	size_t sz = 0;
	while (cur != _head) {
		++sz;
		cur = cur->_next;
	}
	return sz;
}

template<typename T>
void List<T>::InsertSomeNode(int n, const T& x) {
	//判断参数传入的是否正确
	assert(n < 0 || n > ListSize());

	Node* cur = _head;
	if (n == ListSize()) {
		cur = _head->_prev;
	}
	else {
		while (n--) {
			cur = cur->_next;
		}
	}
	Insert(cur, x);
}
template<typename T>
void List<T>::EraseSomeNode(int n) {
	assert(n < 0 || n > ListSize());

	Node* cur = _head;
	if (n == ListSize()) {
		cur = _head->_prev;
	}
	else {
		while (n--) {
			cur = cur->_next;
		}
	}
	Erase(cur);
}

