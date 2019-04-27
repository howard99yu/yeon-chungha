#include <iostream>
#include "selection.h"
using namespace std;

char selection_menu()
{
	char choice;

	// print selection menu
	cout << "****************************************" << endl;
	cout << "* Welcome to Accounting System Manager *" << endl;
	cout << "****************************************" << endl;
	cout << "1. Load a Accounting System." << endl;
	cout << "2. Print all records." << endl;
	//cout << "3. Sort the records by ascending order of the name." << endl;
	cout << "3. Search the records by partial match of the name." << endl;
	cout << "4. Save the Accounting System." << endl;
	cout << "5. Add a new record." << endl;
  cout << "6. Edit a record." << endl;
  cout << "7. Delete a record." << endl;
  cout << "8. Monthly Analysis." << endl;
  cout << "9. Set Monthly Budget." << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;
  return choice;
}
