// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <array>
#define ARRAY_SIZE 10000
#define matrixVec vector<vector<uint64_t> >
using namespace std;

uint64_t FibLoop(size_t);
uint64_t FibRecur(uint64_t);
uint64_t FibRecurDP(size_t);
uint64_t FibRecurDPWorker(size_t, array<uint64_t, ARRAY_SIZE> &xs);
uint64_t FibMatrix(uint64_t);
matrixVec MatrixPower(matrixVec, int);
matrixVec MatrixMultiplication(matrixVec A, matrixVec B);
bool testAllFibFuncs();

void printMatrix(matrixVec v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{	
	size_t inp = 0;

	for (size_t i = 1; i < 10; i++) {
		cout << "f(" << i << ")\n";
		cout << "FibLoop: " << FibLoop(i) << "\n";
		cout << "FibRecur: " << FibRecur(i) << "\n";
		cout << "FibRecurDP: " << FibRecurDP(i) << "\n";
		cout << "FibMatrix: " << FibMatrix(i) << "\n";
		cout << "\n\n";
	}

	return 0;
}





matrixVec
MatrixMultiplication(matrixVec A, matrixVec B) {
	if (A[0].size() != B.size()) {
		cout << "MatrixMultiplication: matrices are not multiplicable. Exiting...\n";
		exit(1);
	}


	// create a vector with rows = a rows, cols = b cols
	matrixVec C(A[0].size(), vector<uint64_t>(B.size()));

	// go through each row
	for (size_t i = 0; i < A.size(); i++) {
		// go through each column
		for (size_t j = 0; j < B[0].size(); j++) {
			uint64_t sum = 0;

			for (size_t k = 0; k < B.size(); k++) {
				sum += A[i][k] * B[k][j];
				C[i][j] = sum;
			}
		}
	}
	return C;
}


uint64_t FibMatrix(uint64_t x) {
	matrixVec squareMatrix(2, vector<uint64_t>(2, 1));
	squareMatrix[0][0] = 0;

	matrixVec f0f1(2, vector<uint64_t>(1, 1));
	f0f1[0][0] = 0;

	matrixVec resultMatrix;
	
	matrixVec matrixPower = MatrixPower(squareMatrix, x);
	resultMatrix = MatrixMultiplication(matrixPower, f0f1);

	return resultMatrix[0][0];
}


matrixVec MatrixPower(matrixVec x, int n) {
	if (x.size() != x[0].size()) {
		cout << "MatrixPower: matrix is not square. Exiting...\n";
		exit(1);
	}

	matrixVec ans;

	while (n > 0) {
		if (n & 1) {
			ans = ans.empty() ? x : MatrixMultiplication(x, ans);
		}

		n >>= 1;
		x = MatrixMultiplication(x, x);
	}

	return ans;
}





bool testAllFibFuncs() {
	return false;
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
