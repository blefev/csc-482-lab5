
#include "functions.h"


using namespace std;

int main()
{
	size_t inp = 0;

	for (size_t i = 0; i < 1000; i++) {
		cout << "f(" << i << ")\n";
		cout << "FibLoop: " << FibLoop(i) << "\n";
		cout << "FibRecur: " << FibRecur(i) << "\n";
		cout << "FibRecurDP: " << FibRecurDP(i) << "\n";
		cout << "FibMatrix: " << FibMatrix(i) << "\n";
		cout << "\n\n";
	}

	return 0;
}