#pragma once
#include<iostream>
#include<cassert>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node<T>* next;//指向下一节点位置
};

template<typename T>
class KsoString :public Node<T> {
public:
	//默认构造
	KsoString() {
		this->head = new Node<T>;
		if (!this->head) {
			cerr << "Error allocating memory!" << endl;
		}
		this->head->next = nullptr;
	}
	//拷贝构造
	KsoString(const KsoString<T>& k) :head(nullptr) {
		if (&k != nullptr) {
			if (this != &k) {
				Node<T>* p = k.head;
				Node<T>* tmp = new Node<T>;
				tmp->data = p->data;
				tmp->next = nullptr;
				head = tmp;
				Node<T>* h = head;
				while (p->next != nullptr) {
					Node<T>* tmp = new Node<T>;
					tmp->data = p->next->data;
					tmp->next = nullptr;
					h->next = tmp;
					h = h->next;
					p = p->next;
				}
			}
		}
	}
	~KsoString()
	{
		if (head) {
			while (head) {
				Node<T>* p = head;
				head = head->next;
				delete p;
			}
		}
	}
private:
	Node<T>* head;

public:
	//判断是否为空
	bool Empty() {
		if (this->head == nullptr) return true;
		else return false;
	}

	//获取大小
	int GetSize() {
		Node<T>* tmp = this->head->next;
		int count = 0;
		while (tmp) {
			count++;
			tmp = tmp->next;
		}
		return count;
	}
	//头插入元素
	void push_front(T& value) {
		Node<T>* tmp = new Node<T>;
		tmp->data = value;
		tmp->next = this->head->next;
		this->head->next = tmp;
	}
	//头删
	void pop_front()
	{
		Node<T>* p = head;
		head = head->next;
		delete p;

	}
	//尾插法
	void push_back(const T& value) {
		Node<T>* tmp = new Node<T>;
		tmp->data = value;
		tmp->next = nullptr;
		if (head == nullptr) {
			head = tmp;
		}
		else {
			Node<T>* p = head;
			while (p->next != nullptr) {
				p = p->next;
			}
			p->next = tmp;
		}
	}
	//尾删
	void pop_back() {
		if (head->next = nullptr) pop_front();
		Node<T>* p = head;
		while (p->next->next != nullptr) {
			p = p->next;
		}
		delete p->next;
		p->next = nullptr;
	}
	//插入指定位置元素
	void insert(int pos, const T& value) {
		/*if (pos == 1) push_front(T & value);
		else if (pos == this->GetSize()) push_back(const T & value);
		else {*/
		int count = 1;
		Node<T>* tmp = new Node<T>;
		Node<T>* node = this->head;
		while (count < pos && node->next != nullptr) {
			count++;
			node = node->next;
		}
		tmp->data = value;
		tmp->next = node->next;
		node->next = tmp;
		//}
	}


	//删除指定位置元素
	int erase(int pos) {
		if (pos < 1) return 0;
		int n = 1;
		if (pos == 1) {
			pop_front();
			return 1;
		}
		Node<T>* p = head;
		while (p->next != nullptr) {
			if (pos == n) {
				Node<T>* tmp = p->next;
				p->next = p->next->next;
				delete tmp;
				return 1;
			}
			p = p->next;
			++n;
		}
		return 0;
	}
	//重载[]运算符
	T operator[](int index) {
		if (index > this->GetSize()) { cout << "0" << endl; }
		else {
			Node<T>* tmp = this->head->next;
			int count = 1;
			while (count < index) {
				count++;
				tmp = tmp->next;
			}
			return tmp->data;
		}
	}

	//打印
	void show() {
		assert(head != nullptr);
		Node<T>* p = head;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void print() {
		assert(head != nullptr);
		Node<T>* p = head;
		while (p != nullptr) {
			wcout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

};
