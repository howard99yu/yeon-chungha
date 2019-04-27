#include <iostream>
#include <string>
#include "function.h"
#include "search.h"

using namespace std;
void delete_element(AccRec * &as, int n,int as_size)
{
    int choice;
    as[0].location_checker=1;
    search_date(as,n);
    cout<<"Select the Location number to delete: ";
    cin>>choice;
    AccRec * as_new2= new AccRec[as_size];
    for(int i=0;i<n+1;i++)
    {
      if(i<choice){
        as_new2[i]=as[i];
      }
      else if(i==choice){
        continue;
      }
      else{
        as_new2[i-1]=as[i];
      }
    }
    delete [] as;
    as=as_new2;
    n=n-1;
    cout<<"There are now "<<n<<" record(s) in the accountlist"<<endl;
    as[0].location_checker=0;
    return;
}
