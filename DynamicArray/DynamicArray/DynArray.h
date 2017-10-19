// Napon Krassner
// CSC 2430, Homework 6
// 2-24-2015
// Due: 2-27-2015
// Name: DynArray header
// Description: This is the header file that contain member function prototypes
//				and member variables.

#ifndef DYN_ARRAY
#define DYN_ARRAY

using namespace std;
typedef int elementType;		//Makes DynArray a "reusable container"

class DynArray
{
public:
	//**********CONSTRUCTORS**********
	//Default constructor
	//Creates dynamic array of elementType with capacity of 0
	DynArray();

	//Constructor
	//Creates dynamic array of elementType with capacity passed in (int)
	// If capacity is < 0, capacity is set to 0
	DynArray(int);

	//Copy constructor
	//Takes another DynArray as parameter, copies all private
	// data into this object.  NOTE: copy constructor NEEDS
	// to take a reference parameter, and we use const for safety.
	DynArray(const DynArray&);

	//Destructor, frees memory used by the dynamic array
	~DynArray();

	//**********ACCESSSORS**********
	//Accessor to return array capacity
	//No Parameters
	//Returns: the array's capacity (an int)
	unsigned int getCapacity() const;

	//Accessor to return element at position
	//Parameters: position to add element at (an int)
	//Returns: array element (elementType) at position
	elementType getValue(int) const;

	//Parameters: value to search for (an element type), function doen't change anything so const
	//Returns: true if found, false if not
	//Description: Search for a number in an array of ints using Malik's sequential search algorithm
	bool linearSearch(elementType) const;

	//Parameters: search element/key (an element type), doesn't change anything so const
	//Returns: 1 if found, 0 if not found, or -1 if not sorted
	//Description: A function to implement the binary search algorithm on a dynamic array
	int binarySearch(elementType) const;

	//**********MUTATORS**********
	//Mutator that adds a data item at a given spot, at end if no spot given
	//Parameters: the element to add (elementType), and the position (int, default -1)
	//Returns: nothing
	void addElement(elementType, int = -1);

	//Parameters: nothing
	//Returns: nothing
	//Effects: the capacity is cut in half (data loss is okay).
	//			All the data from original up to capacity is copied over.
	void halfSize();

	//Parameters: nothing
	//Returns: nothing
	//Effects: Doubles the capacity of an array
	void doubleSize();

	//Parameters: nothing
	//Returns: nothing
	//Description: use selection sort to sort an dynamic array of floats
	//				only sort if it isn't sorted.
	void sortArray();

	//**********UTILITY FUNCTIONS**********
	//Utility function to output the array one elementType per line
	//No parameters
	//Returns nothing
	//Changes nothing
	void outputArray() const;

private:
	elementType *pArr;	//pointer to 1st element
	unsigned int capacity;		//(current) size of the array
	bool isSorted;  // true when data is sorted

	//Function to copy elements from one array to another
	//Parameters: the array to copy from (elementType*), the array to copy to (elementType*)
	// the # of elements to copy (int)
	//Returns: nothing
	//Effects: up to n elements of 2nd array are copied into first
	void copy(elementType*, elementType*, unsigned int);

	//Deep copy of DynArray objects
	//Parameters: the DynArray to copy from
	//Returns: nothing
	//Effects: this object's private member variables set to original's
	// via a deep copy
	void deepCopy(const DynArray&);
};

#endif