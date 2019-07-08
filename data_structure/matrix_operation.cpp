
#include <iostream>

using namespace std;

typedef struct{
	int row;
	int col;
	int value;
} term;

int smTranspose(term a[], term b[]){
	int m = a[0].row, n = a[0].col, v = a[0].value;
	b[0].row = m;
	b[0].col = n;
	b[0].value = v;
	int p = 1;

	if(v > 0){
		for(int i = 0; i < n; i++){
			for(int j = 1; j <= v; j++){
				if(a[j].col == i){
					b[p].row = a[j].row;
					b[p].col = a[j].col;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}

	return p;
}

int main(){

	term a[10], b[10];

	a[0].row = 8;
	a[0].col = 7;
	a[0].value = 10;

	for(int i = 0; i <= a[0].value; i++){
		cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	}

	for(int i = 0; i < smTranspose(a, b); i++){
		cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
	}

	return 0;
}

