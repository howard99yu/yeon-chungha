#include <iostream>
#include <string>
#include "search.h"
#include "display.h"
using namespace std;

int search_date(AccRec as[], int nRec)
{
  int choice,pos;
  int i, count = 0;
  string str;
  cout<<"Search by 1.Day 2.Month 3.Year: ";
  cin>>choice;
  cout << endl;
  if (choice==1)
  {
    cout<<"Type in the full date in DD/MM/YYYY or D/M/YYYY format: ";
    cin >> str;
    if (str.substr(3,1)=="0" && str.substr(1,1)!="/")
    {
      str.erase(3,1);
    }
    if (str.substr(0,1)=="0")
    {
      str.erase(0,1);
    }

	   for (i = 0; i < nRec; i++)
     {
       string date_now = as[i].date;
		   if (date_now==str)
       {
         if (as[0].location_checker==0){
           display(as,i);
           count++;
         }
         else{
           display_for_search(as,i);
           count++;
         }
		   }
	   }
  }
  else if (choice==2)
  {
    cout<<"Type in month and year in MM/YYYY or M/YYYY format: ";
    cin >> str;
    if (str.substr(0,1)=="0")
    {
      str.erase(0,1);
    }
    for (i=0;i<nRec;i++)
    {
      string date_now = as[i].date;
      pos=date_now.find("/");
      date_now=date_now.substr(pos+1);
      if(date_now==str)
      {
        if (as[0].location_checker==0){
          display(as,i);
          count++;
        }
        else{
          display_for_search(as,i);
          count++;
        }
      }
    }
  }
  else
  {
    cout<<"Type in the full year in YYYY format: ";
    cin >> str;
    for (i=0;i<nRec;i++)
    {
      string date_now = as[i].date;
      pos=date_now.length();
      if(date_now.substr(pos-4)==str)
      {
        if (as[0].location_checker==0){
          display(as,i);
          count++;
        }
        else{
          display_for_search(as,i);
          count++;
        }
      }
    }
  }
  as[0].location_checker=0;
  return count;
}
