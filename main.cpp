#include "fibonacci_numbers.h" // first 94 fibonacci numbers
#include "functions.h"
#include <functional>
#include <chrono>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

double timeFunction(string funcName, uint64_t param);
bool testAllFibFuncs();
bool testFibFunc(string funcName, int n);
void measureAllFuncs();
void measureAndRecordFunc(string funcName, uint64_t N, int nTrials = 100);

map<string, function<uint64_t(uint64_t)>> namesToFuncs{
	{"FibLoop", FibLoop},
	{"FibRecur", FibRecur},
	{"FibRecurDP", FibRecurDP},
	{"FibMatrix", FibMatrix}
};

map<string, uint64_t> funcMaxNs{
	{"FibLoop", 45},
	{"FibRecur", 45},
	{"FibRecurDP", 94 },
	{"FibMatrix", 94},
};

int main()
{
	//testAllFibFuncs();
	measureAllFuncs();

	return 0;
}

void measureAllFuncs() {
	for (auto &it : namesToFuncs) {
		string funcName = it.first;
		uint64_t maxN = funcMaxNs[funcName];
		cout << "Testing " << funcName << "\n";
		measureAndRecordFunc(funcName, maxN);
	}
}

// times function and writes results to file
void measureAndRecordFunc(string funcName, uint64_t N, int nTrials) {
	ofstream fout("output\\" + funcName, ios::trunc);

	double sum = 0;
	double avg = 0;

	for (uint64_t i = 0; i < N; i++) {
		for (int trial = 0; trial < nTrials; trial++) {
			double time = timeFunction(funcName, N);
			sum += time;
			cout << "Trial " << trial << ", time: " << time << "\n";
			cout << "Sum: " << sum << "\n";

		}
		avg = sum / nTrials;
		fout << i << "\t" << avg << "\n";
	}

	fout.close();
}

bool testAllFibFuncs() {
	return	testFibFunc("FibLoop", 45) &&
			testFibFunc("FibRecur", 45) &&
			testFibFunc("FibRecurDP", 94) &&
			testFibFunc("FibMatrix", 94);	
}

bool testFibFunc(string funcName, int n) {
	// First 95 fibonaccis (including zero)
	// fibonacci(94) is the max uint64_t can handle
	cout << "Testing " << funcName << "\n";

	for (uint64_t i = 0; i < n; i++) {
		function<uint64_t(uint64_t)> func = namesToFuncs[funcName];
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

double timeFunction(string funcName, uint64_t param) {
	using namespace chrono;

	high_resolution_clock::time_point start = high_resolution_clock::now();
	
	function<uint64_t(uint64_t)> func = namesToFuncs[funcName];
	func(param);
		
	high_resolution_clock::time_point end = high_resolution_clock::now();

	duration<double> timeTaken = duration_cast<duration<double>>(end - start);

	return timeTaken.count();
}


