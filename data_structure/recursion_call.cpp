
#include <iostream>

using namespace std;
int fact(int n);

int main(){

	cout << fact(5) << endl;
	cout << fact(-1) << endl;

	return 0;
}

int fact(int n){

	if(n <= 1)
		return 1;
	else
		return n * fact(n-1);
}