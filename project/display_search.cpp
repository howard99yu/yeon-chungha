#include <iostream>
#include "display.h"
using namespace std;

int display_for_search(AccRec as[],int i)
{
  cout<<"Location Number= "<<i<<endl;
  cout << "Date:  " << as[i].date << endl;
  cout<<"Amount:  HKD "<<as[i].amount<<endl;
  cout<<"Type:  "<<as[i].category<<endl;
  cout<<"Account:  "<<as[i].account<<endl<<endl;
}
