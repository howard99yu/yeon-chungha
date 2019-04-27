#include <iostream>
#include "selection.h"
using namespace std;

char selection_search()
{
	char choice;

	// print selection menu
	cout << "*************" << endl;
	cout << "* Search by *" << endl;
	cout << "*************" << endl;
	cout << "1. Date." << endl;
	cout << "2. Type." << endl;
	cout << "3. amount." << endl;
	cout << "4. Account." << endl;
  cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;
  return choice;
}
