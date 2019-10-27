#include "fibonacci_numbers.h" // first 94 fibonacci numbers
#include "functions.h"
#include <functional>
#include <chrono>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <bitset>

using namespace std;

long double timeFunction(string funcName, uint64_t param);
bool testAllFibFuncs();
bool testFibFunc(string funcName, int X);
void measureAllFuncs();
void measureAndRecordFunc(string funcName, uint64_t X, int nTrials = 100);

map<string, function<uint64_t(uint64_t)>> namesToFuncs{
	{"FibLoop", FibLoop},
	{"FibRecur", FibRecur},
	{"FibRecurDP", FibRecurDP},
	{"FibMatrix", FibMatrix}
};

map<string, uint64_t> funcMaxXs{
	{"FibLoop", 92},
	{"FibRecur", 30},
	{"FibRecurDP", 92},
	{"FibMatrix", 92},
};

int main(int argc, char** argv)
{
	if (argc > 1 && string(argv[1]) == "test") {
		return testAllFibFuncs();
	}
	
	measureAllFuncs();

	return 0;
}

void measureAllFuncs() {
	// iterate through each function and call measureAndRecordFunc
	for (auto &it : namesToFuncs) {
		string funcName = it.first; // this is the value in the namesToFuncs map
		uint64_t maxX = funcMaxXs[funcName]; // get maximum N
		cout << "Testing " << funcName << "\n";
		measureAndRecordFunc(funcName, maxX);
	}
}

// times function and writes results to file
void measureAndRecordFunc(string funcName, uint64_t X, int nTrials) {
	ofstream fout("output\\" + funcName, ios::trunc);
	fout << "N\tX\tT\n";
	long double sum = 0;
	long double avg = 0;

	for (uint64_t i = 0; i <= X; i++) {
		cout << i << " ";
		for (int trial = 0; trial < nTrials; trial++) {
			long double time = timeFunction(funcName, i);
			sum += time;
			
			//cout << "Trial " << trial << ", time: " << time << "\n";
			//cout << "Sum: " << sum << "\n";	
		}
		avg = sum / nTrials;
		// i (n) needs to be represented as number of bits
		bitset<64> bits(i);
		fout << bits.count() << "\t" << i << "\t" << avg << "\n";
		
	}
	cout << "\n";
	fout.close();
}

bool testAllFibFuncs() {
	// test each function by name
	for (auto& it : namesToFuncs) {
		string funcName = it.first; // map value is function name
		uint64_t maxX = funcMaxXs[funcName]; // max X
		if (!testFibFunc(funcName, maxX)) {
			return false; // return if failed
		}
	}
	return true;
}

bool testFibFunc(string funcName, int X) {
	// First 94 fibonaccis (including zero)
	// fibonacci(93) is the max uint64_t can handle
	cout << "Testing " << funcName << "\n";

	for (uint64_t i = 1; i < X; i++) {
		// grab function object from map
		function<uint64_t(uint64_t)> func = namesToFuncs[funcName];
		// call function with i and store result
		uint64_t result = func(i);

		// check if it matches known fibonacci number
		if (result != FIBS[i]) {
			cout << funcName << "(" << i << "): failed\n";
			cout << "Expected: " << FIBS[i] << ".Got : " << result << "\n";
			return false;
		}
		cout << funcName << "(" << i << "): passed\n";
	}
	return true;
}

// time function passed in, called with param
long double timeFunction(string funcName, uint64_t param) {
	using namespace chrono; // temporarily use namespace for ease
	function<uint64_t(uint64_t)> func = namesToFuncs[funcName];

	high_resolution_clock::time_point start = high_resolution_clock::now();
	func(param); // call fibonacci function
	high_resolution_clock::time_point end = high_resolution_clock::now();

	// calculate timeTaken
	duration<long double> timeTaken = duration_cast<duration<long double>>(end - start);

	return timeTaken.count() * 1000;
}


