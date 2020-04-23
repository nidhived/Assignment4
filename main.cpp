#include <iostream>
#include "Registrar.h"
using namespace std;

int main(int argc, char** argv){
	Registrar test;
//opening file
  if (argc < 2){
    cout << "Please provide a file!" << endl;
    return 1;
  }
  string file = argv[1];
  cout << "opening file..." << endl;
	int ctime = 0;
  if (test.readfile(file)== false){
    cout << "File could not be analyized." << endl;
    return 1;
  }
//while file can be opened/true
	if (test.readfile(file)== true){
    //for numnber of windows open in input file
			for (int i = 0; i < test.windows; ++i){
				if (test.windowArray[i]->Twindow< 1){
					if (!test.studentQueue.isEmpty()){
            //add student to the front of the queue
						Student* stud = test.studentQueue.FrontOfQueue();
            //if time they entered is less than clock time
						if (stud->timeEntry <= ctime){
							if (test.windowArray[i]->idletime > 0)
              //idle time// students not at a window time
								test.idleList.enqueue(test.windowArray[i]->idletime);
						}
						test.windowArray[i] = test.studentQueue.dequeue();
						test.waitList.enqueue(test.windowArray[i]->Tqueue);
					}
				}
        ctime++;
        test.ticker(ctime);
			}

//////////////////////////////////////////////

//outputting statistics
cout << "SIMULATION RESULTS: " << endl;
cout << "-------------------------------------------------------------" << endl;
cout << endl;
cout << "Mean student wait time is:................................. " << test.meanWait() << endl;
cout << "Median student wait time is:............................... " << test.medianWait() << endl;
cout << "Max student wait time is:.................................. " << test.maxWait() << endl;
cout << "Number of students waiting over 10 minutes:................ " << test.overTen() << endl;
cout << "Mean window idle time:..................................... " << test.meanIdle() << endl;
cout << "Max window idle time is:................................... " << test.maxIdle() << endl;
cout << "Number of windows idle over 5 minutes is:.................. " << test.overFive() << endl;
cout << endl;

//////////////////////////////////////////
return 0;
		}
}
