#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    clock_t time=clock();

	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();
	cout << "All test over" << endl;

    printf("\nTime taken: %.2fs\n", (double)(clock() - time)/CLOCKS_PER_SEC);
}