
#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main(){

	char student[2][3][20];
	array<array<array<char, 20>, 3>, 2> student2; //제일 안쪽이 가장 마지막 index이다!
	vector<vector<char>> student3; //3 dimensional vector
	string s1 = "JaeHun Jung";

	cout << sizeof(student)/sizeof(student[0]) << endl;
	cout << sizeof(student[0])/sizeof(student[0][0]) << endl;
	cout << sizeof(student[0][0])/sizeof(char) << endl;

	vector<char> temp;			//create temporary vector for stroing the string value
	for(int i=0; i <s1.size(); i++){
		temp.push_back(s1[i]);
	}
	student3.push_back(temp);  //push_back stored string into the 2D vector as one row

	for(int i=0; i < s1.size(); i++){
		student[0][0][i] = s1[i];
		student2[0][0][i] = s1[i];
	}

	cout << student[0][0] << endl;
	
	for(int i = 0; i < s1.size(); i++){
		cout << student2[0][0][i];
	}

	cout << '\n';

	for(int i = 0; i <s1.size(); i++){
		cout << student3[0][i];
	}

	return 0;
}