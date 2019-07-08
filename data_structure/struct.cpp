
#include <iostream>

using namespace std;

struct employee{
	string name;
	int year;
	int pay;
};

int main(){

	struct employee Kim, Lee, Park;

	Lee = {"Ann", 2005, 3200};	//Declare and initialize struct
	cout << Lee.name << " " << Lee.year << " " << Lee.pay << endl;
	Lee.pay = 5000;		//change pay value in struct employee
	cout << Lee.name << " " << Lee.year << " " << Lee.pay << endl;

	struct employee *sptr = &Lee;	//pointer for the struct
	sptr -> year = 2008;	//change struct value by struct pointer "sptr"
	sptr -> pay = 7000;
	cout << Lee.name << " " << Lee.year << " " << Lee.pay << endl;

	(*sptr).year = 2010; //other way to access struct record by pointer Parenthese is important since 
						 //. operator is precedant * operator!
	cout << Lee.name << " " << Lee.year << " " << Lee.pay << endl;

	// 구조체 복사 연산

	struct employee team[5];

	Kim = Lee;
	cout << Kim.name << " " << Kim.year << " " << Kim.pay << endl;
	team[2] = Lee;
	cout << team[2].name << " " << team[2].year << " " << team[2].pay << endl;

	return 0;
}