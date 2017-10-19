// Napon Krassner
// CSC 2430, Homework 6
// 2-24-2015
// Due: 2-27-2015
// Name: DynArray test client
// Description: This is the test client to test all the functions
//				in DynArray implementation file.

#include <iostream>
#include <fstream>
#include <string>
#include "DynArray.h"

using namespace std;

// Function prototypes
void linSearch(DynArray, elementType, string);
void binSearch(DynArray, elementType, string);

int main()
{
	// Declare infile var and open
	ifstream inFile;
	inFile.open("..\\ints.txt");

	if (inFile.fail())  // check for corrupted file
	{
		cout << "Failed to open input file!" << endl;
		exit(1);
	}

	// Read in data from file into DynArray with cap = 20
	int cap = 20;
	DynArray arr1(cap);
	for (int i = 0; i < cap; i++)
	{
		elementType add;
		inFile >> add;
		arr1.addElement(add, i);
	}
	inFile.close();  // Close file connection

	cout << "**Welcome to the Dynamic Array object testing client! By Napon Krassner (Jett)**" << endl << endl;

	// Test copy constructor with two copies
	DynArray arr2(arr1);
	DynArray arr3(arr1);

	// Cut arr2 in half
	arr2.halfSize();

	/*
	// Add 20 elements to arr3 one at a time using addElement with floats
	arr3.addElement(8.134, 20);
	arr3.addElement(7.345, 21);
	arr3.addElement(2.495, 22);
	arr3.addElement(9.412, 23);
	arr3.addElement(4.345, 24);
	arr3.addElement(2.124, 25);
	arr3.addElement(3.543, 26);
	arr3.addElement(5.234, 27);
	arr3.addElement(8.543, 28);
	arr3.addElement(4.544, 29);
	arr3.addElement(2.143, 30);
	arr3.addElement(7.54, 31);
	arr3.addElement(9.095, 32);
	arr3.addElement(0.532, 33);
	arr3.addElement(9.345, 34);
	arr3.addElement(0.395, 35);
	arr3.addElement(3.546, 36);
	arr3.addElement(8.345, 37);
	arr3.addElement(6.543, 38);
	arr3.addElement(8.439, 39);
	*/

	
	// Add 20 elements to arr3 one at a time using addElement with ints
	arr3.addElement(886, 20);
	arr3.addElement(752, 21);
	arr3.addElement(248, 22);
	arr3.addElement(948, 23);
	arr3.addElement(412, 24);
	arr3.addElement(268, 25);
	arr3.addElement(347, 26);
	arr3.addElement(596, 27);
	arr3.addElement(848, 28);
	arr3.addElement(468, 29);
	arr3.addElement(231, 30);
	arr3.addElement(705, 31);
	arr3.addElement(998, 32);
	arr3.addElement(0, 33);
	arr3.addElement(948, 34);
	arr3.addElement(0, 35);
	arr3.addElement(389, 36);
	arr3.addElement(872, 37);
	arr3.addElement(621, 38);
	arr3.addElement(813, 39);
	

	// Sort elements in arr1 and arr2
	arr1.sortArray();
	arr2.sortArray();


	// Output result from sorting
	cout << "Sorted arr1 DynArray: ";
	arr1.outputArray();
	cout << endl << endl;

	cout << "Sorted arr2 DynArray: ";
	arr2.outputArray();
	cout << endl << endl;

	/*
	//******** Search for float elements in arrays ********
	// Linear search arr1 for an element in array
	linSearch(arr1, 8.021, "arr1");
	
	// Binary search arr2 for an element in array
	binSearch(arr2, 9.006, "arr2");

	// Linear search arr2 for an element not in array
	linSearch(arr2, 8.888, "arr2");

	// Binary search arr3 for any element (it's not sorted)
	binSearch(arr3, 9.006, "arr3");
	*/

	
	//******** Search for int elements in arrays ********
	// Linear search arr1 for an element in array
	linSearch(arr1, 819, "arr1");
	
	// Binary search arr2 for an element in array
	binSearch(arr2, 416, "arr2");

	// Linear search arr2 for an element not in array
	linSearch(arr2, 888, "arr2");

	// Binary search arr3 for any element (it's not sorted)
	binSearch(arr3, 206, "arr3");
	
	
	return 0;
}

// Parameters: DynArray object to search in,
//				elementType for key to find,
//				string for name of array to print to console
// Return: nothing
// Description: Takes in the parameters to be used with the DynArray object
//				linear searching function. Then outputs the result to the console.
void linSearch(DynArray arrSearch, elementType key, string arrName)
{
	bool searchResult = arrSearch.linearSearch(key);
	if (searchResult)
		cout << key << " has been found in " << arrName << "! (Linear Search)" << endl;
	else
		cout << "Cannot find " << key << " in " << arrName << ". (Linear Search)" << endl;
}

// Parameters: DynArray object to search in,
//				elementType for key to find,
//				string for name of array to print to console
// Return: nothing
// Description: Takes in the parameters to be used with the DynArray object
//				binary searching function. Then outputs the result to the console.
void binSearch(DynArray arrSearch, elementType key, string arrName)
{
	int searchResult = arrSearch.binarySearch(key);
	if (searchResult == 1)
		cout << key << " has been found in " << arrName << "! (Binary Search)" << endl;
	else if (searchResult == 0)
		cout << "Cannot find " << key << " in " << arrName << ". (Binary Search)" << endl;
	else if (searchResult == -1)
		cout << "Cannot use binary search to an unsorted array: " << arrName << endl;
}