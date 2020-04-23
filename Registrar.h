#include <iostream>
#include "Student.h"
#include "Queue.h"
#include <string>
using namespace std;
//class to calculate stats based on input file
class Registrar{
public:
  //default constructor
	Registrar();
  //deconstructor
	~Registrar();
//when student enters the line
	int ticker(int t);
//mean for waiting time
	double meanWait();
//mean for idle time
  double meanIdle();
//median for waiting time
	double medianWait();
//max wait time
	int maxWait();
//longest time a window did not have a student
	int maxIdle();
// how many wait times were over 10
  int overTen();
//if the idle time was over 5
	int overFive();
//returns if file is correct orientation/format to analyize
	bool readfile(string file);

  int *mArray;
	int *idleArray;
	int windows;
	int students;
	Student* *windowArray;
	Queue<Student*> studentQueue;
	Queue<int> waitList;
	Queue<int> idleList;
private:
//private variables
  int windowTime;
	int ClockTick;
	int mArraycount;
	int iArraycount;
	int inputType;
	int entryTime;

};
