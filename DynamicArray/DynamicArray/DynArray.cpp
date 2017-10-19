// Napon Krassner
// CSC 2430, Homework 6
// 2-24-2015
// Due: 2-27-2015
// Name: DynArray implementation
// Description: This is the implementation file that contains all
//				the function definitions.

#include <iostream>
#include <iomanip>
#include "DynArray.h"


using namespace std;

//**********Constructors and Destructor**********

//Default constructor
//Create a pointer to an empty array of capacity 0
//isSorted set to false initially
DynArray::DynArray()		
{
	capacity = 0;
	pArr = new elementType[capacity];
	isSorted = false;
}

//Copy constructor
//Current object gets deep copy of original object (passed in)
DynArray::DynArray(const DynArray& original)
{
	deepCopy(original);
}

//Constructor to reate an array with a given number of elements
//isSorted set to false initially
DynArray::DynArray(int size)
{
	if (size < 0)
		capacity = 0;
	else
		capacity = size;
	pArr = new elementType[capacity];
	isSorted = false;
}

//Destructor
DynArray::~DynArray()
{
	delete[] pArr;
}

//**********Accessors**********

//Accessor - get array size
unsigned int DynArray::getCapacity() const
{
	return capacity;
}

//Accessor - return a given element
elementType DynArray::getValue(int here) const
{
	//No subscript validation (may be useful to add
	// to help you when testing homework!)
	return pArr[here];
}

// Search for a number in an array of ints using Malik's sequential search algorithm
// if found, return true, false otherwise
bool DynArray::linearSearch(elementType searchKey) const
{
	int loc;
	bool found = false;

	//starting position to search in array 
	loc = 0;

	//step through array until hit end, or find item
	while(loc < capacity && !found)
	{
		//compare key to current element
		if (pArr[loc] == searchKey)
			found = true;
		else
			loc++;
	}

	return found;
}

// A function to implement the binary search algorithm on an array of integers
int DynArray::binarySearch(elementType key) const
{
	int left, right, midpt;

	//set left and right to select correct starting midpoint
	left = 0;
	right = capacity - 1;

	if (isSorted)
	{
		//loop until we have only 1 element left
		// when 1 element is left, it either matches the key, or the 
		// key was not in the array
		while (left <= right)
		{
			midpt = (left + right) / 2;

			//if the midpoint is equal to key, have found what we're looking for!
			if (key == pArr[midpt])
			{
				return 1;		//return 1 if found
			}
			//otherwise, the key is either to the right of the midpoint
			else if (key > pArr[midpt])
			{
				//update left bound to be one past midpoint
				//i.e., throw out everything to left of midpoint (including midpoint)
				left = midpt + 1;
			}
			//or to the left of the midpoint
			else
			{
				//update right bound to be one before midpoint
				//i.e., throw out everything to right of midpoint (including midpoint)
				right = midpt - 1;
			}
		}

		 // 0 means "not found"
		return 0;
	}
	else
		return -1;  // -1 means not sorted
}

//**********Mutators**********

//Add a data item at a given spot in the array
//Default is end of array (if here not specified, or set to -1)
//Adding new element may unsort data, so isSorted set to false
void DynArray::addElement(elementType val, int here)	
{
	//store at end if -1 (default) passed in,
	//or any other negative number
	if (here < 0)
		pArr[capacity - 1] = val;   
	//otherwise, if within bounds, update value
	else if (here < capacity && here >= 0)
		pArr[here] = val;

	//need else if to account for unsigned to signed comparison
	else if (here >= capacity)
	{
		while (here >= capacity)  // double the size until here is <= capacity
			doubleSize();
		pArr[here] = val;
	}
	isSorted = false;
}

void DynArray::halfSize()
{
	//new capacity is halved
	unsigned int newCap = capacity / 2;

	//make temp dyn array
	elementType *temp = new elementType[newCap];

	//copy from original up to newCap to temp
	copy(pArr, temp, newCap);

	delete[] pArr;
	pArr = temp;

	//set temp to point to NULL
	temp = NULL;

	//change capacity
	capacity = newCap;
}

void DynArray::doubleSize()
{
	//new capacity is doubled
	unsigned int newCap = capacity * 2;

	//make temp dyn array
	elementType *temp = new elementType[newCap];

	//copy from original up to the original capacity into temp
	copy(pArr, temp, capacity);

	delete[] pArr;  // delete old stuff
	pArr = temp;  // copy new stuff to original array

	temp = NULL; // point to null

	// update capacity
	capacity = newCap;

}

// Use selection sort to sort dynamic array (that is not sorted)
void DynArray::sortArray()
{
	int index, smallestIndex, location;
	elementType temp; //for swap, ok variable name since is a temporary value!
	if (!isSorted)  //don't sort array that is sorted
	{
		//pick a starting value: first starting value is 0, last is arrayLength - 2
		for(index = 0; index < capacity - 1; index++)
		{
		   smallestIndex = index;
		   //find the smallest element in the rest of the array
		   for(location = index + 1; location < capacity; location++)
			if(pArr[location] < pArr[smallestIndex])
				smallestIndex = location;
	   
		   //swap elements, need temporary storage so don't clobber
		   //	one of the elements before we can swap it!
		   temp = pArr[smallestIndex];	 
		   pArr[smallestIndex] = pArr[index];
		   pArr[index] = temp;
		}
		isSorted = true;  // set to true after done sorting
	}
}

//**********Utilities**********

//Output the array five elementType per line
void DynArray::outputArray() const
{
	for (int i = 0; i < capacity; i++)
	{
		if (i%5 != 0)  // print until every 5th element
			cout << setw(8) << left << pArr[i];
		else
		{
			cout << endl;  // new line every 5th element
			cout << setw(8) << left << pArr[i];
		}
	}
}

//Private member functions
//Copying from ptrOne into ptrTwo
void DynArray::copy(elementType *ptrOne, elementType* ptrTwo, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		ptrTwo[i] = ptrOne[i];

}

//Perform a deep copy.  Contents of original --> this
//Copy value of isSorted also
void DynArray::deepCopy(const DynArray& original)
{
	
	capacity = original.capacity;
	pArr = new elementType[capacity];
	copy(original.pArr, pArr, capacity);
	isSorted = original.isSorted;
}