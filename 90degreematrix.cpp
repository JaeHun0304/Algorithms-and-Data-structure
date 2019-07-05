
// this target question and possible solution is cited from the website https://www.geeksforgeeks.org/
// ,and I modfied some portion of the question

#include <iostream>

#define n 4
void rotatematrix(int arr[][n]);

int main(){

	int matrix[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16}};

	rotatematrix(matrix);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}

void rotatematrix(int arr[][n]){
	for(int i = 0; i < n/2; i++){
		for(int j = i; j < n-1-i; j++){

			int temp = arr[i][j];

			arr[i][j] = arr[j][n-1-i];

			arr[j][n-1-i] = arr[n-1-i][n-1-j];

			arr[n-1-i][n-1-j] = arr[n-1-j][i];

			arr[n-1-j][i] = temp;
		}

	}
}