#include <iostream>
#include <string>
#include <cstdlib>
#include "function.h"
using namespace std;

void Budget_setting(AccRec as[],int n){
  string month;
  cin >> month;
  if (month.substr(0,1)=="0")
  {
  	month.erase(0,1);
  }

  double budget;
  string response;
  int contain=0;
  cout<<endl<<endl<<"Type in the budget to set in "<<month<<": ";
  cin>>budget;
  if (as[0].budget_counter==0){
    as[(as[0].budget_counter)].budget_list=month+"!"+to_string(budget);
    (as[0].budget_counter)++;
    cout<<endl<<endl<<budget<< " set for "<<month<<endl;
  }
  else{
    for(int i=0;i<as[0].budget_counter;i++){
      if((as[i].budget_list).find(month)!=-1){
        (as[i].budget_list)=month+"!"+to_string(budget);
        cout<<endl<<endl<<budget<< " changed for "<<month<<endl;
        break;
      }
      else{
        contain++;
      }
    }
    if(contain==as[0].budget_counter){
        as[(as[0].budget_counter)].budget_list=month+"!"+to_string(budget);
        (as[0].budget_counter)++;
        cout<<endl<<endl<<budget<< " set for "<<month<<endl;
    }
  }
}
