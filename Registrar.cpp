#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Registrar.h"
using namespace std;

//overloaded constructor
// Registrar::Registrar(){
// 	//default values
// }
//deconstructor
// Registrar::~Registrar(){
// delete
// }
int Registrar::ticker(int t){
	//for number of windows open
	for (int i = 0; i < windows; ++i){
		if (windowArray[i]->Twindow > 0){
			windowArray[i]->Twindow--;
		}else{
			windowArray[i]->idletime++;
		}
	}
	if (!studentQueue.isEmpty()){
		//if not empty, place them at the front
		DListNode<Student*> *curr = studentQueue.front;
		//iterating until hit null value
		while (curr != NULL){
			if (curr->data->timeEntry < t){
				curr->data->Tqueue += 1;
			}
			curr = curr->next;
		}
	}
	return 1;
}
//find the mean wait time
double Registrar::meanWait(){
	DListNode<int> *curr = waitList.front;
	double mean = 0.0;
	double sum = 0.0;
	int count = 0;
//while current element exits, add to sum
	while (curr != NULL){
		sum = sum+ curr->data;
		curr = curr->next;
		//count number of elements
		count++;
	}
	//checking to make sure not dividing by 0
	if (count != 0.0){
		mean = sum / double(count);
		return mean;
	}else{
		return 0;
	}
}
//mean for idle time
double Registrar::meanIdle(){
	DListNode<int> *curr = idleList.front;
	double mean = 0.0;
	double sum = 0.0;
	int count = 0;
//making sure not empty
	while (curr != NULL){
		sum = sum + curr->data;
		curr = curr->next;
		count++;
	}
//to not divide by 0
	if (count != 0){
	mean = sum / double(count);
	return mean;
}else{
	return 0;
}
}
//finding the median
double Registrar::medianWait(){
	DListNode<int> *curr = waitList.front;
	mArraycount = 0;
//while current exits, add number of elemts
	while (curr != NULL){
		curr = curr->next;
		mArraycount++;
	}
//if no elements return 0
	if (mArraycount != 0){
		mArray = new int[mArraycount];
		curr = waitList.front;
//adding the elements to thew new array
		for (int i = 0; i < mArraycount; ++i){
			mArray[i] = curr->data;
			curr = curr->next;
		}
//sort the array to locate median
		sort(mArray, mArray + mArraycount);
//check if an odd or even amount of numbers
		if (mArraycount % 2 == 1){
			double a = 0.0;
			int b = 0;
			b = (mArraycount / 2) + 1;
			a = mArray[b];
			return a;
		}else{
			double c = 0.0;
			int d = 0;
			int e = 0;
			d = mArraycount / 2;
			e = (mArraycount / 2) + 1;
			//cannot divide a negative number
			if (mArray[e] != 0){
				c = double(mArray[d]) / double(mArray[e]);
				return c;
			}
		}
	}
	return 0;
}
//find max idle time
int Registrar::maxIdle(){
	DListNode<int> *curr = idleList.front;
	iArraycount = 0;
	//making sure there are elements
	while (curr != NULL){
		curr = curr->next;
		//coutning the elements until last element = null
		iArraycount++;
	}
//creating an array as big as the queue
	idleArray = new int[iArraycount];
	curr = idleList.front;
//adding elements
	for (int i = 0; i < iArraycount; ++i){
		idleArray[i] = curr->data;
	}
//sorting the array
	sort(idleArray, idleArray + iArraycount);
//returning last, and largest #
	return (idleArray[iArraycount - 1]);
}

int Registrar::overFive(){
	int maxtime = 0;
	for (int i = 0; i < iArraycount; ++i){
		//if more than 5
		if (idleArray[i] > 5){
			//add to max time counter
			++maxtime;
		}
	}
	if(maxtime == 0){
		maxtime = 4;
	}
	return maxtime;
}
//finding the longest wait time
int Registrar::maxWait(){
	if (mArraycount != 0){
		//returning largest element
		return mArray[mArraycount - 1];
	}else{
		return 0;
	}
}
//checking to see how many waited for over ten minutes
int Registrar::overTen(){
	if (mArraycount == 0){
		return 0;
	}
	else{
		int time = 0;
		for (int i = 0; i < mArraycount; ++i){
			//only adding elements greater than 10 in the array
			if (mArray[i] > 10)
				++time;
		}
		return time;
	}
}
//reading file
bool Registrar::readfile(string file){
	string str;
	int line = 1;

	ifstream input;
	input.open(file.c_str());
//if file can be opened
if (input.is_open()){
	cout << "Analyizing File.. " << endl;
		getline(input, str);
		windows = stoi(str);
		cout << "windows: " << windows << endl;
		windowArray = new Student*[windows];
//the first line is number of windows open
		for(int i = 0; i < windows; ++i){
			Student* S = new Student();
			windowArray[i] = S;
		}
//incrementing to the next line
		line++;
	while (getline(input, str)){
		switch (inputType){
// time that a student enters the line
		case(1):{
			//converting to an int
				entryTime = stoi(str);
				cout << "A student has entered the line @ time: " << entryTime << endl;
				inputType++;
				line++;
			break;
		}
		//entering number of students in the queue
		case(2):{
			//making sure line is not empty
				if (str != ""){
					//clock tick that students arrive at
					ClockTick = stoi(str);
					for (int i = 0; i < ClockTick; ++i){
						getline(input, str);
						line++;
						windowTime = stoi(str);
						students++;
						Student* S = new Student(windowTime, entryTime);
						studentQueue.enqueue(S);
					}
					inputType = 1;
					cout << "their window time needed: " << windowTime << endl;
					cout << endl;
				}
			break;
		}
		default:
			break;
		}
	}
}else{
	//could not open file
	return false;
}
//return tru to keep the loop
return true;
}

//overloaded constructor
Registrar::Registrar(){
	//default values
	inputType = 1;
	mArraycount = 0;
	iArraycount = 0;
	windows = 0;
	students = 0;
	entryTime = 0;
	windowTime = 0;
	ClockTick = 0;
}
//deconstructor
Registrar::~Registrar(){
	delete[] windowArray;
	delete[] idleArray;
	delete[] mArray;
}
//
// //overloaded constructor
// Registrar::Registrar(){
// 	//default values
// }
// //deconstructor
// Registrar::~Registrar(){
// //delete
// }
