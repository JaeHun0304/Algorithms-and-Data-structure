
#include <iostream>

using namespace std;

int main(){

	string s[] = {"Korea", "Seoul", "Mapo", "152"};

	for(int i = 0; i < sizeof(s)/sizeof(s[0]); i++) //The size of the data type string is fixed!
		std::cout << s[i] << endl;

	s[2] = "Jongno";

	for(int i = 0; i < sizeof(s)/sizeof(s[0]); i++)
		std::cout << s[i] << endl;

	return 0;
}