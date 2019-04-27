#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "function.h"
#include "search.h"
#include "display.h"
#include "selection.h"
using namespace std;

int main()
{
	int as_size = 200;
  AccRec * accountlist = new AccRec[as_size];
	accountlist[0].location_checker=0;
  accountlist[0].budget_counter=0;
  int num_records = 0, count;
  char choice = selection_menu();
  char choice_search;
	while (choice != '0')
	{
		switch (choice)
		{
			case '1':
				cout << "Please enter the filename: ";

				num_records = load_accountlist(accountlist, as_size);
			//	cout << endl << num_records << " record(s) loaded." << endl << endl;
			  break;

      case '2':
				print_accountlist(accountlist, num_records);
				break;

      case '3':
  			cout << "Please enter a choice: ";
        cout << endl;
        choice_search = selection_search();

        if (choice_search=='1')
        {
            count=search_date(accountlist, num_records);
            cout << endl << count << " record(s) saved." << endl << endl;
        }

        if (choice_search=='2')
        {
            count=search_type( accountlist, num_records);
            cout << endl << count << " record(s) saved." << endl << endl;
        }

        if (choice_search=='3')
        {
          count=search_amount( accountlist, num_records);
          cout << endl << count << " record(s) saved." << endl << endl;
        }
        if (choice_search=='4')
        {
          count=search_method( accountlist, num_records);
          cout << endl << count << " record(s) saved." << endl << endl;
        }
        break;

      case '4':
  			cout << "Please enter the filename: ";

				save_accountlist(accountlist, num_records);
				cout <<"Saved." << endl << endl;
				break;

			case '5':
  			if (num_records >= as_size)
  				grow_accountlist(accountlist, as_size, 100);

				if (num_records < as_size)
  				num_records = add_record(accountlist, num_records);
  				cout << "There are now " << num_records <<
  				" record(s) in the accountlist." << endl << endl;
  				break;

      case '6':
        Update_list(accountlist,num_records);
        break;

      case '7':
        delete_element(accountlist,num_records,as_size);
        break;

			case '8':
	      Monthly_Analysis(accountlist,num_records);
				break;

			case '9':
        //string month;
        cout<<"Type in month and year in MM/YYYY or M/YYYY to set budget: ";
        //cin>>month;
        //if( month.substr(0,1)=="0")
	//			{
        //	month.erase(0,1);
        //}
        Budget_setting(accountlist,num_records);
        break;

			default:
				cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}
  cout << "Goodbye!" << endl << endl;
  delete [] accountlist;
  return 0;
}
