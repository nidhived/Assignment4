using namespace std;
//header class for student
class Student{
public:
	//default constructor
	Student();
	//deconstructor
	~Student();
	//overloaded
	Student(int window, int entry);
//public variables
	int Twindow;
	int Tqueue;
	int idletime;
	int timeEntry;
};
