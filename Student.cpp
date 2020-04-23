#include <iostream>
#include "Student.h"
using namespace std;
//class to hold student variables/information for window
//default values
Student::Student(){
	Twindow = 0;
	timeEntry = 0;
	Tqueue = 0;
	idletime = 0;
}
Student::~Student(){
  //deconstructor
};
//overloaded constructor
Student::Student(int window, int entry){
	Twindow = window;
	timeEntry = entry;
	Tqueue = 0;
	idletime = 0;
}
