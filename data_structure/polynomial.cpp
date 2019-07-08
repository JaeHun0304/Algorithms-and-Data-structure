
#include <iostream>

using namespace std;
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct{
	int degree;
	int coef[MAX_DEGREE];
} polynomial;

polynomial addpoly(polynomial A, polynomial B){
	polynomial C;
	int A_index=0, B_index=0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree,B.degree);

	while(A_index <= A.degree and B_index <= B.degree){
		if(A_degree > B_degree){
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if(A_degree == B_degree){
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else{
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}

	// for(int i = 0; i <= C.degree; i++) :for testing return value
		// cout << C.coef[i] << endl;
	return C;
}

polynomial multpoly(polynomial A, polynomial B){
	polynomial C;
	C.degree = A.degree + B.degree;

	for(int i = 0; i <= C.degree; i++){		//Initialize is very important for priting the correct output!
		C.coef[i] = 0;
	}

	for(int i = 0; i <= A.degree; i++){
		for(int j = 0; j <= B.degree; j++){
			C.coef[i+j] += A.coef[i] * B.coef[j];

		}
	}

	return C;
}

void printpoly(polynomial P){

	for(int i = 0; i <= P.degree; i++){
		cout<< P.coef[i] << "x^" << P.degree-i << " ";
	}
}

int main(){

	polynomial A={3, {4,3,5,0}};
	polynomial B={4, {3,1,0,2,1}};
	polynomial C1, C2;

	C1 = addpoly(A,B);

	cout << "A(x)= "; printpoly(A); cout << endl; 
	cout << "B(x)= "; printpoly(B); cout << endl;
	cout << "C1(x)= "; printpoly(C1); cout << endl;

	C2 = multpoly(A,B);

	cout << "A(x)= "; printpoly(A); cout << endl; 
	cout << "B(x)= "; printpoly(B); cout << endl;
	cout << "C2(x)= "; printpoly(C2); cout << endl;

	return 0;
}