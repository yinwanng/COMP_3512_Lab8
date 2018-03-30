#include <iostream>
#include "FixedList.h"
#include <string>
using namespace std;

int main()
{
	// Construct a double FixedList
	FixedList<double, 6> list1;

	// Add double values
	list1.add(1.0);
	list1.add(2.0);
	list1.add(3.0);
	list1.add(4.0);
	list1.add(5.0);
	cout << "Doubles: " << endl;

	// Size / Capacity
	cout << "Size: " << list1.size() << endl;
	cout << "Capacity: " << list1.capacity() << endl;

	// Get index value
	cout << "Index 0: " << list1.get(0) << endl;
	cout << "Index 1: " << list1.get(1) << endl;
	cout << "Index 2: " << list1.get(2) << endl;
	cout << "Index 3: " << list1.get(3) << endl;
	cout << "Index 4: " << list1.get(4) << endl;

	// []
	cout << "list1[0] " << list1[0] << endl;
	cout << "list1[1] " << list1[1] << endl;
	cout << "list1[2] " << list1[2] << endl;
	cout << "list1[3] " << list1[3] << endl;
	cout << "list1[4] " << list1[4] << endl;


	// Get first index
	cout << "Find 3 at index: " << list1.getFirstIndex(3) << endl;
	cout << "Find 12 at index: " << list1.getFirstIndex(12) << endl;

	// Remove
	list1.remove(1);
	cout << "list1[0] " << list1[0] << endl;
	cout << "list1[1] " << list1[1] << endl;
	cout << "list1[2] " << list1[2] << endl;
	cout << "list1[3] " << list1[3] << endl;
	cout << endl << endl;
	// Construct a string FixedList
	FixedList<string, 6> list2;

	// Add string values
	list2.add("Johnny");
	list2.add("Bob");
	list2.add("Chris");
	list2.add("Fiona");
	cout << "Strings: " << endl;

	// Size / Capacity
	cout << "Size: " << list2.size() << endl;
	cout << "Capacity: " << list2.capacity() << endl;

	// Get index value
	cout << "Index 0: " << list2.get(0) << endl;
	cout << "Index 1: " << list2.get(1) << endl;
	cout << "Index 2: " << list2.get(2) << endl;
	cout << "Index 3: " << list2.get(3) << endl;

	// []
	cout << "list2[0] " << list2[0] << endl;
	cout << "list2[1] " << list2[1] << endl;
	cout << "list2[2] " << list2[2] << endl;
	cout << "list2[3] " << list2[3] << endl;

	// Get first index
	cout << "Find Chris at index: " << list2.getFirstIndex("Chris") << endl;
	cout << "Find Bill at index: " << list2.getFirstIndex("Bill") << endl;

	// Remove
	list2.remove("Chris");
	cout << "list2[0] " << list2[0] << endl;
	cout << "list2[1] " << list2[1] << endl;
	cout << "list2[2] " << list2[2] << endl;
	cout << endl << endl;
	

	system("pause");
	return 0;
}


