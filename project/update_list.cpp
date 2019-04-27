#include <iostream>
#include <string>
#include "function.h"
#include "search.h"
#include "display.h"
using namespace std;
void Update_list(AccRec as[],int nRec)
{
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"},name_Other,amount;
  string list3[4]={"Cash","Bank account","Credit card","Other"};
  int choice,choice_category,choice_pay;
  string choice2,choice_IE="N",temp;
  as[0].location_checker=1;
  search_date(as,nRec);
  cout<<"Choose the Location Number you want to edit: ";
  cin>>choice;
  cout<<endl;
  cout<<"Change date (Y/N): ";
  cin>>choice2;
  if (choice2=="Y"){
    cout<<"Please enter in the new date in DD/MM/YYYY or D/M/YYYY format: ";
    cin>>choice2;
    as[choice].date=choice2;
  }
  cout<<"Change Category (Y/N): ";
  cin>>choice2;
  if (choice2=="Y"){
    cout<<"Is it income or expense?(type I/E):";
    cin>>choice_IE;
    if (choice_IE=="E"){
      cout<<"Please choose the new category number:1.Food 2.Transportation 3.Entertainment"<<endl;
      cout<<"                                      4.Fashion/beauty 5.Telephone 6.Health"<<endl;
      cout<<"                                      7.Education 8.Supermarket 9.Other: ";
      cin>>choice_category;
      if (choice_category!=9){
        as[choice].category=list[choice_category-1];
      }
      else{
        cout<<"Please Specity the name: ";
        cin>>name_Other;
        as[choice].category=name_Other;
      }
    }
    else{
      cout<<"Please choose the new category number: 1.Monthly income 2.Pocket money 3.Stock"<<endl;
      cout<<"                                       4.Other: ";
      cin>>choice_category;
      if (choice_category!=4){
        as[choice].category=list2[choice_category-1];
      }
      else{
        cout<<"Please Specify the name: ";
        cin>>name_Other;
        as[choice].category=name_Other;
      }
    }
  }
  cout<<"Change amount? (Y/N): ";
  cin>>choice2;
  if ((as[choice].amount).substr(0,1)=="-"){
    temp="E";
  }
  else{
    temp="I";
  }
  if (choice2=="Y"){
    cout<<"Type in the new amount in HKD: ";
    cin>>amount;
    if ((choice_IE=="E" and temp=="I") or (choice_IE=="E" and temp=="E")){
      as[choice].amount="-"+ amount;
    }
    if ((choice_IE=="I" and temp=="I") or (choice_IE=="I" and temp=="E")){
      as[choice].amount=amount;
    }
  }
  else{
    if (choice_IE=="E" and temp=="I")
    {
      as[choice].amount="-"+as[choice].amount;
    }
    if (choice_IE=="I" and temp=="E")
    {
      as[choice].amount=(as[choice].amount).substr(1);
    }
    if(choice_IE=="E" and temp=="E")
    {
      as[choice].amount=as[choice].amount;
    }
    if (choice_IE=="I" and temp=="I")
    {
      as[choice].amount=as[choice].amount;
    }

  }
  cout<<"Change Pay method? (Y/N): ";
  cin>>choice2;
  if (choice2=="Y"){
    cout<<"Please choose the new pay method: 1.Cash 2.Bank account 3.Credit card"<<endl;
    cout<<"                                  4.Other: ";
    cin>>choice_pay;
    if (choice_pay!=4){
      as[choice].account=list3[choice_pay-1];
    }
    else{
      cout<<"Please Specify the name: ";
      cin>>name_Other;
      as[choice].account=name_Other;
    }
  }
  cout<<endl;
  cout<<"Changed result is:"<<endl;
  display_for_search(as,choice);
  cout<<"Save changed!"<<endl;
  as[0].location_checker=0;
}
