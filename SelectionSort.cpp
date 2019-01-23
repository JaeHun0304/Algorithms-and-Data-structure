// Implement selectionsort algorithm for the given array
// The running time is bounded to O(n^2), and no additional memory space will be required.

#include <array>
#include <iostream>


int FindMin(int* arr, int startindex, int size);
void selectionsort(int* arr, int size);
void swap(int* arr, int first, int second);

int main(){

	std::array<int, 10> s1 = {10, 7, 3, 2, 5, 9, 11, 15, 25, 4};

	selectionsort(s1.begin(), 10);

	   for(auto a: s1){
		    std::cout << a << " ";
	   }

}

void swap(int* arr, int first, int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int FindMin(int* arr, int startindex, int size){

	int min_index = startindex;

	for(int i = startindex + 1; i < size; i++){
		if(arr[i] < arr[min_index]){
			min_index = i;
		}
	}

	return min_index;
}

void selectionsort(int* arr, int size){

	for(int i=0; i < size; i++){
		int min = FindMin(arr, i, size);
		swap(arr, i, min);
	}

}