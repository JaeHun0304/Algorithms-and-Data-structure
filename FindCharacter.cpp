//  This program finds the first unrepeated character in the given array
//  The running time approximately 256*n, so it will be O(n)
//  The main concept is that ASCII code is formed with 256 characters and they can be also seen as intergers

#include <string>
#include <iostream>

char findchar(std::string &arr, int n);

int main(void){

	std::string test = "abcdefgggg";

	std::cout << findchar(test, 10);
	
	return 0;
}

char findchar(std::string &arr, int n){

	if(n==0 || arr == "")
		return '0';

	int ASCII[256] = {0};
	char answer;

	for(int i = 0; i < n; i++){
	
		for(int j = 0; j < 256; j++){
		if(int(arr[i]) == j){
			ASCII[j]++;
		}
	}

	}

	for(int k = 0; k < 256; k++){
		if(ASCII[k] == 1){
			answer = ASCII[k];
			return answer;
		}
	}


}