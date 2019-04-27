#include <iostream>
#include "function.h"
using namespace std;

void grow_accountlist(AccRec * &as, int &as_size, int n)
{
	// create a new dynamic array with a new size = max_size + n
	AccRec * as_new = new AccRec[as_size + n];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < as_size; i++)
	{
		as_new[i] = as[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] as;
	// assign the pointer to the new dynamic array to the pointer variable
	as = as_new;
	// update the size of the array
	as_size += n;

	cout << "---> accountlist size enlarged to hold a maximum of " << as_size << " records." << endl;

	return;
}
