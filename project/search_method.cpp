#include <iostream>
#include <string>
#include "search.h"
#include "display.h"
using namespace std;
int search_method( AccRec as[], int nRec)
{
  int pos;
  int choice2;
  int i, count = 0,check_type=0;
  string list[4]={"Cash","Bank account","Credit card","Other"};
//string list_income[4]={"Monthly income","Pocket money","Stock","Other"},amount;
  //cout<<"Search by 1.Expense 2.Income: ";
  //cin>>choice;

    cout<<"Search by 1.Cash 2.Bank account 3.Credit card"<<endl;
    cout<<"          4.Other: ";
    cin>>choice2;
    cout<<endl;
    cout<<"The result for "+list[choice2-1]+" is/are the following:"<<endl<<endl;
    if(choice2!=4){
      for(int k=0;k<nRec;k++){
        string type=as[k].account;
        if (type==list[choice2-1]){
          display(as,k);
          count++;
        }
      }
    }
    else{
      for(int k=0;k<nRec;k++){
        string type=as[k].account;
        for(int i=0;i<4;i++){
            if(type!=list[i] ){
              check_type=1;
            }
            else{
              check_type=0;
              break;
            }
        }
        if (check_type==1){
          display(as,k);
          count++;
        }
      }
    }


return count;
}
