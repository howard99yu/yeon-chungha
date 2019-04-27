#include <iostream>
#include <string>
#include <sstream>
#include "function.h"
#include "display.h"
using namespace std;

int add_record(AccRec as[], int nRec)
{
	char ans;
	string str,choice,amount;
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"};
  string list3[4]={"Cash","Bank account","Credit card","Other"};
  int choice_category,choice_account;
	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter the date: ";
	getline(cin, as[nRec].date);
	cout << "Please choose (Income/Expense): ";
  cin>>choice;
  if (choice=="Expense" or choice=="expense"){
    cout<<"Please choose the number of category: 1.Food 2.Transportation 3.Entertainment"<<endl;
    cout<<"                                      4.Fashion/beauty 5.Telephone 6.Health"<<endl;
    cout<<"                                      7.Education 8.Supermarket 9.Other: ";
    cin>>choice_category;
    if(choice_category==9)
    {
      cout<<"Specify the use of expense: ";
      cin>>str;
      as[nRec].category=str;
    }
    else
    {
      as[nRec].category=list[choice_category-1];
    }
    cout << "Please enter the amount: HKD ";
  	cin>>amount;
    as[nRec].amount="-"+amount;
  }
  else{
    cout<<"please choose the number of category: 1.Monthly income 2.Pocket money 3.Stock"<<endl;
    cout<<"                                      4.Other: ";
    cin>>choice_category;
    if (choice_category==4){
      cout<<"Specify the use of income: ";
      cin>>str;
      as[nRec].category=str;
    }
    else{
      as[nRec].category=list2[choice_category-1];
    }
    cout << "Please enter the amount in HKD: ";
    cin>>amount;
    as[nRec].amount=amount;
  }
  getline(cin,str);

  cout<<"please choose the number of category: 1.Cash 2.Bank account 3.Credit card"<<endl;
  cout<<"                                      4.Other: ";
  cin>>choice_account;
  if (choice_account==4){
    cout<<"Specify the type: ";
    cin>>str;
    as[nRec].account=str;
  }
  else{
    as[nRec].account=list3[choice_account-1];
  }
	cout << endl;
  display(as,nRec);
  cout << "Add to account list (y/n) ";
	cin >> ans;
	if (ans == 'y')
	{
		cout << "1 record added." << endl;
		nRec++;
	}

	return nRec;
}
