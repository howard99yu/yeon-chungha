#include <iostream>
#include "display.h"
using namespace std;

int display(AccRec as[],int i)
{
  cout << "Date:  " << as[i].date << endl;
  cout<<"amount:  HKD "<<as[i].amount<<endl;
  cout<<"Type:  "<<as[i].category<<endl;
  cout<<"Account:  "<<as[i].account<<endl<<endl;
}
