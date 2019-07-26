#include <iostream>
#include <vector>

using namespace std;
int BinarySearch(const vector<int>& vec, int key);

int main(void){

	vector<int> sample = {1, 2, 3, 4, 5, 6, 20, 30, 50, 80, 100};

	cout << "location of 30 is " << BinarySearch(sample, 30) << endl; 

	return 0;
}

int BinarySearch(const vector<int>& vec, int key){


	int max = vec.size() - 1;
	int min = 0;
	int mid = int((min + max) / 2);

	if(key > vec.back())
		return -1;

	while( min <= vec.size()-1 || max >= 0){
		if(vec[mid] == key)
			return mid;
		else if(vec[mid] < key){
			min = mid;
			mid = int((min + max) / 2);
			if(mid == min)
				mid++;
		}
		else{
			max = mid;
			mid = int((min + max) / 2);
			if(mid == max)
				mid--;
		}
	}
	
	return -1;
}