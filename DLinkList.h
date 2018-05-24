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
	
	//ʵ��ջ�Ľӿ�
	void PopBack() {
		PopsBack();
	}
	size_t Size() {
		return ListSize();
	}
	const T& LastNodeValue() {
		return _head->_prev->data;
	}
	//ʵ�ֶ��еĽӿ�
	const T& FirstNodeValue() {
		return _head->_next->data;
	}
	
	//����Insert
	//�������е�n���ڵ����һ��Ԫ��x
	void InsertSomeNode(int n, const T& x);
	//����Erase
	void EraseSomeNode(int n);
private:
	Node* _head;
};

/////////////////////////////////////////////////////
//��ĺ���ʵ��
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

//�������ͷ���֮��Ľڵ�
template<typename T>
void List<T>::clear() {
	Node* cur = _head->_next;
	while (cur != _head) {
		Node* cur_next = cur->_next;
		//��ڵ�
		cur->_prev->_next = cur->_next;
		cur->_next->_prev = cur->_prev;
		//�ͷŲ������Ľڵ�
		delete cur;
		//����cur
		cur = cur_next;
	}
}

template<typename T>
List<T>::~List() {
	clear();

	delete _head;
	_head = NULL;
}

//��posλ��֮ǰ����ڵ�
template<typename T>
void List<T>::Insert(Node* pos, const T& x) {
	if (pos == NULL) {
		printf("pos������ �����!\n");
		return;
	}
	Node* InsertNode = new Node(x);
	/*
	**����ķ�������pos֮�����
	InsertNode->_prev = pos;
	InsertNode->_next = pos->_next;

	pos->_next->_prev = InsertNode;
	pos->_next = InsertNode;
	*/
	//��pos֮ǰ����
	InsertNode->_next = pos;
	InsertNode->_prev = pos->_prev;

	pos->_prev->_next = InsertNode;
	pos->_prev = InsertNode;
}

template<typename T>
void List<T>::Erase(Node* pos) {
	if (pos == NULL || pos == _head) {
		printf("pos�����������!\n");
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
	//�жϲ���������Ƿ���ȷ
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

