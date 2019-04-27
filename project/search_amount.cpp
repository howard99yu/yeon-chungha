#include <iostream>
#include <string>
#include <cstdlib>
#include "search.h"
#include "display.h"
using namespace std;

int search_amount(AccRec as[], int nRec)
{
  int i,count=0;
  double from,to;
  string str;
  cout << "Please choose Income/Expense: ";
  cin >> str;
  cout << endl;
  cout << "Select your range: "<<endl;
  cout << "From: ";
  cin >> from;
  cout << "To: ";
  cin >> to;
  cout << endl;
  if (str=="Income" || str=="income")
  {
    for (i = 0; i < nRec; i++)
    {
      string temp = as[i].amount;
      double number;
      number = atof(temp.c_str());
      if (number>0)
      {
        if (number>=from && number<=to)
        {
          display(as,i);
          count++;
        }
      }
    }
  }
  else if (str=="Expense" || str=="expense")
  {
    from=-1*from;
    to=-1*to;
    for (i = 0; i < nRec; i++)
    {
      string temp = as[i].amount;
      double number;
      number = atof(temp.c_str());
      if (number<0)
      {
        if (number<=from && number>=to)
        {
          display(as,i);
          count++;
        }
      }
    }
  }
  return count;
}
