// Implement tower of hanoi based on the recursive approach.
// The main principle is that n-1 disks go to spare column, move n disk to target column, and finally move n-1 disk to target column
// The running time will be O(2^n)

#include <iostream>
#include <vector>

void solvehanoi(int n, std::vector<int> &from, std::vector<int> &to, std::vector<int> &temp);
void movedisk(std::vector<int> &from, std::vector<int> &to);

int main(void){

	std::vector<int> columnA = {5, 4, 3, 2, 1};
	std::vector<int> columnB;
	std::vector<int> columnC;


	solvehanoi(5, columnA, columnB, columnC);

	for(int i = 0; i < columnB.size(); i++){
		// std::cout << columnB[i] << " ";
	}



	return 0;
}


void solvehanoi(int n, std::vector<int> &from, std::vector<int> &to, std::vector<int> &temp){


	if(n == 0){
		return;
	}

	solvehanoi(n-1, from, temp, to);
	movedisk(from, to);
	solvehanoi(n-1, temp, to, from);

}

void movedisk(std::vector<int> &from, std::vector<int> &to){

	to.push_back(from.back());
	from.pop_back();
}
