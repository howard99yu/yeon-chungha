#include <iostream>
#include <string>
#include <cstdlib>
#include "function.h"
#include "display.h"
using namespace std;

void Monthly_Analysis(AccRec as[],int n){
  int pos,contain_result=0,pos2;
  string month,date_now;
  double price_type_list[9],price_type_list2[9],sum=0;
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"},price,temp;
  double total=0,income=0,expense=0,number=0;
  cout<<"Type in month and year in MM/YYYY or M/YYYY: ";
  cin>>month;
  if (month.substr(0,1)=="0")
  {
    month.erase(0,1);
  }
  cout<<endl;
  for (int i=0;i<n;i++){
    date_now=as[i].date;
    pos=date_now.find("/");
    date_now=date_now.substr(pos+1);
    temp=as[i].amount;
    number=atof(temp.c_str());
    if(date_now==month){
      //display(as,i);
      if(number>=0){
        income=income+number;
      }
      else{
        expense=expense+number;
      }
    }
    else{
      contain_result++;
    }
  }
  if(contain_result==n){
    cout<<"No record of money flow in this month!"<<endl<<endl;
  }
  else{
    total=income+expense;
    cout<<"In "+month+", Income is " << income<<endl;
    cout<<"           Expense is " << expense<<endl;
    cout<<"           Total spent(-)/profit(+) is (in HKD) " << total<<endl<<endl;
    contain_result=0;
    for(int i=0; i<as[0].budget_counter;i++){
      date_now=as[i].budget_list;
      pos=date_now.find("!");
      date_now=date_now.substr(0,pos);
      if(date_now==month){
        pos=(as[i].budget_list).find("!");
        cout<<"Budget set for this month was "<<(as[i].budget_list).substr(pos+1)<<endl<<endl;
        temp=(as[i].budget_list).substr(pos+1);
        number=atof(temp.c_str());
        if(total<0){
          if(number+total>0){
            cout<<"\t You have "<<number+total <<" amount of money left for this month"<<endl;
          }
          else{
            cout<<"\t You have exceeded your budget by "<<-1*(total+number)<<endl<<endl;
          }
        }
        else{
          cout<<"\t You have "<<number+total <<" amount of money left for this month"<<endl<<endl;
        }
      }
      else{
        contain_result++;
      }
      if(contain_result==as[0].budget_counter){
        cout<<"\t No budget set for this Month. Set Budget first to see Analysis!"<<endl<<endl;
      }
    }
    if(as[0].budget_counter==0){
      cout<<"\t No budget set for this Month. Set Budget first to see Analysis!"<<endl<<endl;
    }
    cout<<"The distribution of monthly income: "<<endl<<endl;
    for(int i=0;i<3;i++){
      price_type_list[i]=0;
      for(int k=0;k<n;k++){
        date_now=as[k].date;
        pos=(as[k].date).find("/");
        date_now=date_now.substr(pos+1);
        if(list2[i]==as[k].category and (as[k].amount).substr(0,1)!="-" and date_now==month){
          temp=as[k].amount;
          number=atof(temp.c_str());
          price_type_list[i]=price_type_list[i]+number;
        }
      }
    }
    price_type_list[3]=income-(price_type_list[2]+price_type_list[1]+price_type_list[0]);
    for(int i=0;i<4;i++){
        if(price_type_list[i]!=0){
          cout<<"\t"<<list2[i]<<": "<<(price_type_list[i]/income)*100<<"% of income"<<endl<<endl;
        }
      }
      cout<<"The distribution of monthly expense: "<<endl<<endl;
      for(int i=0;i<8;i++){
        price_type_list2[i]=0;
        for(int k=0;k<n;k++){
          date_now=as[k].date;
          pos=(as[k].date).find("/");
          date_now=date_now.substr(pos+1);
          if(list[i]==as[k].category and (as[k].amount).substr(0,1)=="-" and date_now==month){
            temp=as[k].amount;
            number=atof(temp.c_str());
            price_type_list2[i]=price_type_list2[i]+number;
          }
        }
        sum=sum+price_type_list2[i];
      }
      price_type_list2[8]=expense-(sum);
      for(int i=0;i<9;i++){
        if(price_type_list2[i]!=0){
          cout<<"\t"<<list[i]<<": "<<(price_type_list2[i]/expense)*100<<"% of expense"<<endl<<endl;
        }
      }
    }
}
