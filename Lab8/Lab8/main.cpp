#include <iostream>
#include "FixedList.h"
using namespace std;

int main()
{
	FixedList<int, 5> test;

	cout << test.get(5) << endl;


	system("pause");
	return 0;
}