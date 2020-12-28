#include <iostream>
#include <cstdlib>
using namespace std;

void printRec(int* A, int sz, int i) {
	if (i == sz) { 
		cout << endl; 
		return; 
	}
	cout << A[i] << " "; 
	printRec(A, sz, i + 1); 
}


void generateRec(int* A, int sz,int i) {
	if (sz == i)
		return;
	A[i] = rand() % 61 - 40;
	generateRec(A, sz ,i+1);
}
int sumaRec(int* A, int sz, int i) {
	int suma = 0;
	if (sz == i)
		return 0;
	if (!(A[i] > 0 || (i % 2) != 0)) {
		suma += A[i];

	}
	suma += sumaRec(A, sz, i + 1);
	return suma;
}

int quantityRec(int* A, int sz, int i) {
	int quantity = 0;
	if (sz == i)
		return 0;
	if (!(A[i] > 0 || (i % 2) != 0)) {
		quantity ++;

	}
	quantity += quantityRec(A, sz, i + 1);
	return quantity;
}


void zeroRec(int* A, int sz, int i) {
	if (sz == i)
		return;
	if (!(A[i] > 0 || (i % 2) != 0))
		A[i] = 0;
	zeroRec(A, sz, i + 1);
}
int main(){


	int A[26] = {};
	generateRec(A,26,0);
	printRec(A, 26,0);
	cout << sumaRec(A, 26,0) << endl;
	cout << quantityRec(A, 26,0) << endl;
	zeroRec(A, 26,0);
	printRec(A, 26, 0);
}