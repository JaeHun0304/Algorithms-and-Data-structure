
#include <iostream>

using namespace std;

int main(){

	char *ptrArray[2]; //pointer-array
	char **ptrptr;	//pointer-of-pointer


	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";

	ptrptr = ptrArray;
	cout << "Address of ptrArray[0]= " << &ptrArray[0] << endl;
	cout << "Value of ptrptr 1st= " << *ptrptr << endl; //expect address of ptrArray[0], But prints ptrArray[0] value
	cout << "Address of ptrArray[1]= " << &ptrArray[1] << endl;
	cout << "Value of ptrptr 2nd= " << *(ptrptr + 1) << endl;

	cout << '\n' << "Value of ptrArray[0]= " << ptrArray[0] << endl;
	cout << "Value of Value of ptrptr 1st= " << **(ptrptr) << endl;
	return 0;
}