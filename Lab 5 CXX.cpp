// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <array>
#define ARRAY_SIZE 10000

using namespace std;

uint64_t FibLoop(uint64_t);
uint64_t FibRecur(uint64_t);
uint64_t FibRecurDP(uint64_t);
uint64_t FibRecurDPWorker(uint64_t, array<uint64_t, ARRAY_SIZE> &xs);
uint64_t FibMatrix(uint64_t);
bool testAllFibFuncs();

int main()
{	
	uint64_t inp = 0;


	while (cout << "Fib : " && cin >> inp && inp != 0) {
		cout << FibLoop(inp) << endl;
	}

	return 0;
}

bool testAllFibFuncs() {
	return false;
}

uint64_t FibLoop(uint64_t x) {
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

uint64_t FibRecurDP(uint64_t x) {
	static array<uint64_t, ARRAY_SIZE> fibs { 0, 1, 1 };
	return FibRecurDPWorker(x, fibs);
}

uint64_t FibRecurDPWorker(uint64_t x, array<uint64_t, ARRAY_SIZE> &xs) {
	if (xs[x] != NULL) {
		return xs[x];
	}

	return FibRecurDPWorker(x - 1, xs) + FibRecurDPWorker(x - 2, xs);
}

uint64_t FibMatrix(uint64_t x) {

	return 1;
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

