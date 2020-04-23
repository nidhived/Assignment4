#include <iostream>
using namespace std;

template <class T>
class DListNode{
public:
//default constructor
	DListNode();
//deconstructor
	~DListNode();
//overloaded constructor
	DListNode(T data);
	
	T data;
	DListNode<T> *next;
	DListNode<T> *prev;
};
//default
template <class T>
DListNode<T>::DListNode(){
 		//default
}
// deconstructor
template <class T>
DListNode<T>::~DListNode(){
	//checking to see if there are values, then setting it to null
	if (next != NULL){
		next = NULL;
		prev = NULL;

		delete next;
		delete prev;
	}
}
//overloaded constructor
template <class T>
DListNode<T>::DListNode(T d){
	data = d;
	next = NULL;
	prev = NULL;
}
