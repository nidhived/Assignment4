#include <iostream>
#include "DListNode.h"
using namespace std;

template <class Q>
class Queue{
public:
//overloaded constructor
	Queue();
//deconstructor
	~Queue();
//main queue methods
	void enqueue(Q d); //insert method
	Q dequeue(); //remove method
	Q FrontOfQueue(); //displaying front queue
	//helper methods
	unsigned int getSize(); // number of elements in teh queue
	bool isEmpty(); // if the queue has any elements or nah
	//front back size variables
	DListNode<Q> *front;
	DListNode<Q> *back;
	unsigned int size;
};
//default constructor
template <class Q>
Queue<Q>::Queue(){
	size = 0;
	front = NULL;
	back = NULL;
}
//deconstructor
template <class Q>
Queue<Q>::~Queue(){
  //delete
}
//enqueue (adding elements to the line)
template <class Q>
void Queue<Q>::enqueue(Q d){
	DListNode<Q> *node = new DListNode<Q>(d);
	//check to see if  empty
	if (size == 0){
		front = node;
	}else{
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}
//dequeue (remove elements of the line)
template <class Q>
Q Queue<Q>::dequeue(){
	//check to see if empty
	if (!isEmpty()){
		DListNode<Q> *prevFront = front;
		Q node = prevFront->data;
//if there is only one node in the list
		if (front->next == NULL){
			front = NULL;
			back = NULL;
		}else{
			//more than one node in the list
			front->next->prev = NULL;
			front = front->next;
		}
		delete prevFront;
		size--;
		return node;
	}else{
		//if list is empty
		return Q();
	}
}
//showing the front element of the queue
template <class Q>
Q Queue<Q>::FrontOfQueue(){
	return front->data;
}

//getting nymber of elements
template <class Q>
unsigned int Queue<Q>::getSize(){
	return size;
}
//checking if the queue is empty
template <class Q>
bool Queue<Q>::isEmpty(){
	return (size == 0);
}
