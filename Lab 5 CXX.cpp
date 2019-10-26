// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <array>
#define ARRAY_SIZE 10000
#define matrix2x2 array<array<uint64_t, 2>, 2>
#define matrixVec vector<vector<uint64_t>>
using namespace std;

uint64_t FibLoop(size_t);
uint64_t FibRecur(uint64_t);
uint64_t FibRecurDP(size_t);
uint64_t FibRecurDPWorker(size_t, array<uint64_t, ARRAY_SIZE> &xs);
uint64_t FibMatrix(uint64_t);
array<array<uint64_t, 10>, 10> MatrixPower(array<array<uint64_t,10>, 10>);
matrixVec dotProduct(matrixVec matrix, size_t n);

vector<vector<uint64_t> >
MatMul(vector<vector<uint64_t> > A, vector<vector<uint64_t> > B);






vector<vector<uint64_t> >
MatMul(vector<vector<uint64_t> > A, vector<vector<uint64_t> > B) {
	size_t a_rows = A.size();
	size_t a_cols = A[0].size();
	size_t b_rows = B.size();
	size_t b_cols = B[0].size();

	// create a vector with rows = a_rows
	vector<vector<uint64_t> > C(a_cols, vector<uint64_t>(b_rows));

	// go through each row
	for (size_t i = 0; i < A.size(); i++) {
		// go through each column
		for (size_t j = 0; j < B[0].size(); j++) {
			uint64_t sum = 0;

			for (size_t k = 0; k < B.size(); k++) {
				sum = A[i][k] * B[k][j];
				C[i]
			}
		}
	}
}





uint64_t mypow(uint64_t x, uint8_t n) {
	uint64_t ans = 1;
	size_t i = 0;

	while (n > 0) {
		if (n & 1) {
			ans *= x;
		}

		n >>= 1;
		x *= x;
		i++;
	}
	cout << "Did " << i << " loops\n";
	cout << ans << endl;
	return ans;
}



bool testAllFibFuncs();

int main()
{	
	size_t inp = 0;

	mypow(2, 13);
	/*
	while (cout << "Fib : " && cin >> inp && inp != 0) {
		cout << FibLoop(inp) << endl;
	}
	*/

	return 0;
}

bool testAllFibFuncs() {
	return false;
}

uint64_t FibMatrix(uint64_t x) {

	return 1;
}


matrixVec matrixMultiplication(matrixVec matrixA, matrixVec matrixB) {
	int x;
	matrixVec result;
	for (size_t i = 0; i < matrixA.size(); i++) {
		for (size_t j = 0; j < matrixA.size(); j++) {

		}
	}
}


matrixVec dotProduct(matrixVec matrix) {
	matrixVec ret{ 0 };
	return ret;
}

template <typename T>
array<array<uint64_t, 10>, 10> MatrixPower(array<array<uint64_t, 10>, 10> matrix, size_t n) {
	uint64_t ans = ;

	while (n > 0) {
		if (n & 1) {
			ans = x;
		}

		n >>= 1;
		x *= x;
	}

	return ans;
}


uint64_t FibLoop(size_t x) {
	array<uint64_t, ARRAY_SIZE> fibs{ 0, 1, 1 };

	if (fibs[x] != NULL) {
		return fibs[x];
	}

	for (size_t i = 3; i <= x; i++) {
		if (fibs[i] == NULL) {
			fibs[i] = fibs[i - 1] + fibs[i - 2];
		}
	}
	return fibs[x];
}

uint64_t FibRecur(uint64_t x) {
	if (x == 0) return 0;
	if (x == 1 || x == 2) return 1;

	return FibRecur(x - 1) + FibRecur(x - 2);
}

uint64_t FibRecurDP(size_t x) {
	static array<uint64_t, ARRAY_SIZE> fibs { 0, 1, 1 };
	return FibRecurDPWorker(x, fibs);
}

uint64_t FibRecurDPWorker(size_t x, array<uint64_t, ARRAY_SIZE> &xs) {
	if (xs[x] != NULL) {
		return xs[x];
	}

	return FibRecurDPWorker(x - 1, xs) + FibRecurDPWorker(x - 2, xs);
}



//MatrixPower

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


