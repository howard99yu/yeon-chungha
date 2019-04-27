#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "function.h"
#include "display.h"
using namespace std;

int load_accountlist(AccRec * &as, int &as_size)
{
    string filename;
    cin >> filename;
    int count = 0;
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i = 0;
    string line;
    while (getline(fin, line))
    {
		if (i >= as_size)
			grow_accountlist(as, as_size, 100);

		// extract a name and a phone no. from a line
		if (i < as_size) {
	        istringstream iss(line);
	        if (!getline(iss, as[i].date,','))
	            break;
          if (!getline(iss, as[i].category,','))
    	        break;
          if (!getline(iss, as[i].amount,','))
    	        break;
	        if (!getline(iss, as[i].account))
	            break;
	        ++i;
	    }
    count++;
    }
    fin.close();
    cout << count << " record(s) loaded." << endl << endl;
    return i;
}
