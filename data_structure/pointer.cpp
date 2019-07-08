
#include <iostream>

using namespace std;

int main(){

	int i,j;
	int *ptr;
	ptr = &i; // ptr points the address of variable i
	cout << i << endl;
	*ptr = 10; // save value 10 to variable i
	j = *ptr; // save pointer's pointed out value to variable j

	cout << ptr << endl;
	cout << &i << endl;
	cout << *ptr << " " << j << " " << i << endl; 

	return 0;
}