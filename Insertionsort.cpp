// Implement insertionsort algorithm for the given array
// function insertionsort based on the webiste https://www.geeksforgeeks.org/insertion-sort/

#include <iostream>
#include <array>


void insertionSort(int arr[], int n);

int main(){

	std::array<int,10> s1 = {10, 7, 3, 2, 5, 9, 11, 15, 25, 4};

	insertionSort(s1.begin(), 10);

	   for(auto a: s1){
		   std::cout << a << " ";
	   }

	return 0;
}


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 