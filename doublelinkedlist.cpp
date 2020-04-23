#include <iostream>
#include "DListNode.h"
using namespace std;

template <class T>
class DoubleLL{
public:
	DListNode<T> *front;
	DListNode<T> *back;
  //since size cannot be negative
	unsigned int size;
//overloaded constructor
	DoubleLL();
//deconstructor
	~DoubleLL();

	void insertBack(T d);
	T removeFront();
	T returnFront(){
		return front->data;
  }
	void removePos(int pos);
  //will print the list
  void printList();
	unsigned int getSize(){
		return size;
  }
	bool isEmpty(){
		return (size == 0);
  }
};
//implementing the cpp for the double linked list
//default constructor
template <class T>
DoubleLL<T>::DoubleLL(){
  size = 0;
	front = NULL;
	back = NULL;
}
//deconstructor
template <class T>
DoubleLL<T>::~DoubleLL(){
   front = NULL;
   back = NULL;
   delete front;
   delete back;
}
//will insert at the tail
template <class T>
void DoubleLL<T>::insertBack(T d){
	DListNode<T> *node = new DListNode<T>(d);
	if (size == 0){
		front = node;
	}else{
    //if not empty
		back->next = node;
		node->prev = back;
	}
	back = node;
	++size;
}
//removes front/ head
template <class T>
T DoubleLL<T>::removeFront(){
	if (!isEmpty()){
		DListNode<T> *prevFront = front;
		T node = prevFront->data;

		if (front->next == NULL){
      //if only one node in the list
			front = NULL;
			back = NULL;
			}
		else{
      //more than 1 node
			front->next->prev = NULL;
			front = front->next;
		}

		delete prevFront;
		size--;
		return node;
	}else{
		return T();
  }
}
//to remove an element from the linked list
template <class T>
void DoubleLL<T>::removePos(int pos){
	int position = 0;
	DListNode<T>  *curr = front;
	DListNode<T>  *prev = front;
//look for value in the list
	while (position != pos){
		prev = curr;
		curr = curr->next;
		position++;
	}
//if
	prev->next = curr->next;
	curr->next->prev = prev;
	curr->next = NULL;
	curr->prev = NULL;
	curr->data = NULL;

	size--;
	delete curr;
}
//printing the elements in the list
template <class T>
void DoubleLL<T>::printList(){
	DListNode<T> *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
	}
}
