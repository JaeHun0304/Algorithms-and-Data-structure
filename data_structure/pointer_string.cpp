
#include <iostream>

using namespace std;

int main(){

	string s1 = "Dreams come true!";
	string s2;
	string *ptr1;
	char *ptr2;

	ptr1 = &s1;
	cout << '\n' << "s1 address " << &s1 << '\t' << "ptr1 pointed address " << ptr1 << endl;
	cout << "s1 = " << s1 << " ptr1 = " << *ptr1 << endl;
	
	ptr2 = &s1[7];
	cout << "ptr2 = " << ptr2 << endl;

	return 0;
}