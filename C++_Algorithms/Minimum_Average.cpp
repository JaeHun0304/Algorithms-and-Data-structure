
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int find_min(vector<int> vec, int size);

#define L 3
int main(){

	
	vector<int> vec1 = {1, 2, 3, 1, 2, 3};
	vector<int> vec2;
	int sum;

	sum = find_min(vec1, L);

	cout << sum/L << endl;


	return 0;
}

int find_min(vector<int> vec, int size){

	vector<int>::iterator itr = vec.begin();
	
	int sum;
	while((itr+size) != vec.end()){
		int next_case, prev_case = 0;
			for(int i = 0; i < size; i++)
				prev_case += *(itr+i);
			for(int i = 1; i < (size+1); i++)
				next_case += *(itr+i);

		if(next_case < prev_case)
			sum = next_case;
		else
			sum = prev_case;
		itr++;		
	}

	return sum;
}