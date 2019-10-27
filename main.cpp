#include "fibonacci_numbers.h" // first 94 fibonacci numbers
#include "functions.h"
#include <functional>
#include <chrono>
#include <string>
#include <iostream>
#include <map>

using namespace std;

double timeFunction(function< uint64_t(uint64_t) > func, uint64_t param);
bool testAllFibFuncs();
bool testFibFunc(function< uint64_t(uint64_t) > func, string funcName, uint8_t n);
void observeAllFuncs();
void populateNamesToFuncs();

map<string, function<uint64_t(uint64_t)>> namesToFuncs;

int main()
{
	populateNamesToFuncs();
	testAllFibFuncs();
	observeAllFuncs();

	return 0;
}

void populateNamesToFuncs() {
	namesToFuncs.emplace("FibLoop", FibLoop);
	namesToFuncs.emplace("FibRecur", FibRecur);
	namesToFuncs.emplace("FibRecurDP", FibRecurDP);
	namesToFuncs.emplace("FibMatrix", FibMatrix);
}

void observeAllFuncs() {
	
}

bool testAllFibFuncs() {
	return	testFibFunc(FibLoop, "FibLoop", 45) &&
			testFibFunc(FibRecur, "FibRecur", 45) &&
			testFibFunc(FibRecurDP, "FibRecurDP", 94) &&
			testFibFunc(FibMatrix, "FibMatrix", 94);	
}

bool testFibFunc(function< uint64_t(uint64_t) > func, string funcName, uint8_t n) {
	// First 95 fibonaccis (including zero)
	// fibonacci(94) is the max uint64_t can handle
	cout << "Testing " << funcName << "\n";

	for (uint64_t i = 0; i < n; i++) {
		uint64_t result = func(i);
		if (result != FIBS[i]) {
			cout << funcName << "(" << i << "): failed\n";
			cout << "Expected: " << FIBS[i] << ".Got : " << result << "\n";
			return false;
		}
		cout << funcName << "(" << i << "): passed\n";
	}
	return true;
}

double timeFunction(function< uint64_t(uint64_t) > func, uint64_t param) {
	using namespace chrono;

	high_resolution_clock::time_point start = high_resolution_clock::now();

	func(param);
		
	high_resolution_clock::time_point end = high_resolution_clock::now();

	duration<double> timeTaken = duration_cast<duration<double>>(end - start);

	return timeTaken.count();
}


