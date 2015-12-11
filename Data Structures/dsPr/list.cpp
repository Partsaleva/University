#include "stdafx.h"
#include "List.h"

template<class T>
List<T>::List() :head(nullptr), tail(nullptr), size(0){}

template<class T>
List<T>::~List(){
	Node* curr = head;
	Node* temp;
	while (curr != nullptr)
	{
		temp = curr->link;
		delete curr;
		curr = temp;
	}
}

template<class T>
void List<T>::throwIfEmpty()const{
	if (head == nullptr)
	{
		throw std::out_of_range("Empty!");
	}
}

//check position between 0 and size-1
template<class T>
void List<T>::checkIfValidPosition(const size_t &pos) const{
	if (pos < 0 || pos >= size)
	{
		throw std::out_of_range("Invalid position");
	}
}

template<class T>
void List<T>::pushFront(const T &value){
	cout << "pushFront: " << value << endl;
	head = new Node(value, head);
	if (tail == nullptr)
	{
		tail = head;
	}
	size++;
}

template<class T>
void List<T>::pushBack(const T &value){
	cout << "pushBack: " << value << endl;
	Node* newNode = new Node(value);
	if (head == nullptr && tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->link = newNode;
		tail = newNode;
	}
	size++;
}


template<class T>
T List<T>::popFront(){
	throwIfEmpty();
	T val = head->value;
	cout << "popFront: " << val << endl;
	Node* temp = nullptr;

	temp = head;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->link;

	}
	delete temp;
	size--;
	return val;
}

template<class T>
T List<T>::popBack(){
	throwIfEmpty();
	T val = tail->value;
	cout << "popBack: " << val << endl;

	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		Node* curr = nullptr;
		Node* prev = nullptr;

		curr = head;
		while (curr->link != nullptr) {
			prev = curr;
			curr = curr->link;
		}
		tail = prev;
		prev->link = nullptr;
		delete curr;
	}
	size--;
	return val;
}

template<class T>
void List<T>::insert(const size_t position, const T &value){
	cout << "insert " << value << " at " << position << " index" << endl;
	Node* newNode = new Node(value);
	Node* curr = nullptr;
	if (position == size)
	{
		;
	}
	else
	{
		checkIfValidPosition(position);
	}

	curr = head;
	if (head == nullptr && tail == nullptr)
	{
		head = tail = newNode;
	}
	else if (position == 0)
	{
		head = newNode;
		newNode->link = curr;
	}
	else
	{
		for (size_t i = 0; i < position - 1; i++)
		{
			curr = curr->link;
		}

		newNode->link = curr->link;
		curr->link = newNode;
		if (curr==tail)
		{
			tail = newNode;
		}

	}
	size++;
}


template<class T>
void List<T>::remove(const T& value) {
	cout << "remove: " << value << endl;
	Node* curr = nullptr;
	Node* prev = nullptr;

	curr = head;
	while (curr != nullptr && value != curr->value) {
		prev = curr;
		curr = curr->link;
	}

	if (curr != nullptr) {
		if (curr == tail)
		{
			tail = prev;
		}
		// found the node, have to delete it
		if (prev != nullptr) {
			// not the first element
			prev->link = curr->link;
		}
		else {
			// removing the first element
			curr = head;
			head = head->link;

		}
		delete curr;
	}
	size--;
}

template<class T>
bool List<T>::find(const T &value)const{
	Node* curr = nullptr;

	curr = head;
	while (curr != nullptr)
	{
		if (curr->value == value)
		{
			return true;
		}
		curr = curr->link;
	}
	return false;
}

template<class T>
void List<T>::sort() {
	Node* first = nullptr;

	if (head == nullptr || head->link == nullptr){
		first = tail = head;
	}
	else
	{
		while (head != nullptr) {

			Node* curr = head;
			head = head->link;
			if (first == nullptr)
			{
				curr->link = first;
				first = curr;
			}
			else if (curr->value <= first->value)
			{
				if (first->value > tail->value)
				{
					tail = first;
				}
				curr->link = first;
				first = curr;
			}
			else
			{
				Node* p = first;
				while (p != nullptr) {
					if (p->link == nullptr || curr->value <= p->link->value)
					{
						if (p->link != nullptr && p->link->value > tail->value)
						{
							tail = p->link;
						}
						curr->link = p->link;
						p->link = curr;
						break;
					}
					p = p->link;
				}
			}
		}
	}
	head = first;

}

template<class T>
void List<T>::reverse(){
	Node* curr = nullptr;
	Node* prev = nullptr;
	Node* next = nullptr;

	tail = curr = head;
	while (curr != nullptr)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

template<class T>
void List<T>::print()const{
	Node* curr = head;
	while (curr)
	{
		cout << curr->value << ' ';
		curr = curr->link;
	}
}

template<class T>
size_t List<T>::listSize()const{
	return size;
}

template<class T>
T List<T>::peek() const{
	T val = head->value;
	throwIfEmpty();
	return val;
}

template class List <int>;
template class List <char*>;