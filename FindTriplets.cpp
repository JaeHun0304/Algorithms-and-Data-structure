//Find triplets which the sum is zero in the given array.

#include <iostream>
#include <unordered_set>

void findTriplets(int arr[], int n);

int main(){

	int arr[] = {1, 3, 4, 5, -3, -1};

	findTriplets(arr, 6);

	return 0;

}


void findTriplets(int arr[], int n){

	bool found = false;

	for (int i = 0; i < n-1; i++){
		std::unordered_set<int> s;
		for(int j = i+1; j < n; j++){

			int k = -(arr[i] + arr[j]);
			if(s.find(k) != s.end())
			{
				printf("%d %d %d", k, arr[i], arr[j]);
				found = true;
			}
			else
				s.insert(arr[j]);
		}
	}

	if(found == false)
		std::cout << "No Triplet Found";
}
