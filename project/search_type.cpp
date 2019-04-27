#include <iostream>
#include <string>
#include "search.h"
#include "display.h"
using namespace std;

int search_type( AccRec as[], int nRec)
{
  int choice,pos;
  int choice2;
  int i, count = 0,check_type=0;
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list_income[4]={"Monthly income","Pocket money","Stock","Other"};
  string amount;
  cout<<"Search by 1.Expense 2.Income: ";
  cin>>choice;
  if (choice==1){
    cout<<"Search by 1.Food 2.Transportation 3.Entertainment"<<endl;
    cout<<"           4.Fashion/beauty 5.Telephone 6.Health"<<endl;
    cout<<"           7.Education 8.Supermarket 9.Other: ";
    cin>>choice2;
    cout<<endl;
    cout<<"The result for "+list[choice2-1]+" is/are the following:"<<endl<<endl;
    if(choice2!=9){
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        if (type==list[choice2-1]){
          display(as,k);
          count++;
        }
      }
    }
    else{
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        for(int i=0;i<9;i++){
            if(type!=list[i] and (as[k].amount).substr(0,1)=="-"){
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
  }
  else{
    cout<<"Search by 1.Monthly income 2.Pocket money 3.Stock"<<endl;
    cout<<"          4.Other: ";
    cin>>choice2;
    cout<<endl;
    cout<<"The result for "+ list_income[choice2-1] + " is/are the following:"<<endl<<endl;
    if(choice2!=4){
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        if (type==list_income[choice2-1]){
          display(as,k);
          count++;
        }
      }
    }
    else{
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        for(int i=0;i<4;i++){
            if(type!=list_income[i] and (as[k].amount).substr(0,1)!="-"){
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
  }
return count;
}
