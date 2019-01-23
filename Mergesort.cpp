// Implement mergesort in recursive way, and merge with while loops
// The function merge code based on the code in website "GeeksforGeeks" https://www.geeksforgeeks.org/merge-sort/
// The running time will be O(nlogn)

#include <iostream>

void mergesort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);


int main(void){

	int s1[] = {10, 7, 3, 2, 5, 9, 11, 15, 15, 25, 4};
	int size_array = sizeof(s1)/sizeof(s1[0]);

	mergesort(s1, 0, size_array-1);

	for(int i = 0; i < size_array; i++){
		std::cout << s1[i] << " ";
	}

	return 0;
}

void mergesort(int arr[], int p, int r){

	if(p < r){
		int q = (int)((p+r)/2);
		mergesort(arr, p, q);
		mergesort(arr, q+1, r);
		merge(arr, p, q, r);
	}

}

void merge(int arr[], int p, int q, int r){

	int i, j, k;
	int n1 = q-p+1;
	int n2 = r-q;

	int temp1[n1], temp2[n2];


	for(i = 0; i < n1; i++){
		temp1[i] = arr[p+i];
	}

	for(j = 0; j < n2; j++){
		temp2[j] = arr[q+1+j];
	}

	i = 0;
	j = 0;
	k = p;

	while( i < n1 && j < n2 ){
		if(temp1[i] < temp2[j]){
			arr[k] = temp1[i];
			i++;
		}
		else{
			arr[k] = temp2[j];
			j++;
		}

		k++;
	}

	while(i < n1){
		arr[k] = temp1[i];
		i++;
		k++;
	}

	while(j < n2){
		arr[k] = temp2[j];
		j++;
		k++;
	}

}
