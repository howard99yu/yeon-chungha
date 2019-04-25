// accountlist Manager (dynamic array version)
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

struct AccRec {
    string date;
    string category;
    string price;
    string account;
};
int location_checker=0;
char selection_menu();
// Print selecltion menu to screen and read user selection

char selection_search();
// Print selecltion menu to screen and read user selection for search function

int load_accountlist(string filename, AccRec * &as, int &as_size);
// Load accountlist data from a file into the array parameter with a maximium size
// specified by 'as_size', and return the number of records loaded

void print_accountlist(AccRec as[], int nRec);
// Print accountlist records stored in the array parameter. 'nRec' specifies the
// number of records stored in the array parameter

int search_date(AccRec as[], int nRec);
// Search the recrods of the accountlist by date and return
// the number of records found

int search_price(AccRec as[], int nRec);
// Search the recrods of the accountlist by price and return
// the number of records found

int search_type(AccRec as[], int nRec);
// Search the recrods of the accountlist by type and return
// the number of records found

int search_method( AccRec as[], int nRec);
// Search the recrods of the accountlist by account and return
// the number of records found

int save_accountlist(string filename, AccRec as[], int nRec);
// Save accountlist data stored in the array parameter into a file. 'nRec' specifies
// the number of records stored in the array parameter. Return 0 if error in
// opening file

int add_record(AccRec as[], int nRec);
// Add a new record to the accountlist and return the new size

void display(AccRec as[],int i);
//Display the accountlist information

void display_for_search(AccRec as[],int i);
//Display the accountlist information for edit

void grow_accountlist(AccRec * &as, int &as_size, int n);
// Grow the accountlist by increasing the size of the array by n

void Update_list(AccRec as[],int nRec);
// Edit accountlist data stored in the array parameter

void delete_element(AccRec * &as, int n,int as_size);

int main()
{
	int as_size = 200;
  AccRec * accountlist = new AccRec[as_size];
  int num_records = 0, count;
  //string str;
	string str = "purchase_info7.csv";
  num_records = load_accountlist(str, accountlist, as_size);
  char choice = selection_menu();
  char choice_search;
	while (choice != '0')
	{
		switch (choice)
		{
			//case '1':
				//cout << "Please enter the filename: ";
				//cin >> str;
				//num_records = load_accountlist(str, accountlist, as_size);
				//cout << endl << num_records << " record(s) loaded." << endl << endl;
				//break;

      case '2':
				print_accountlist(accountlist, num_records);
				break;

      case '3':
  			cout << "Please enter a choice: ";
        cout << endl;
        choice_search = selection_search();

        if (choice_search=='1')
        {
            count=search_date(accountlist, num_records);
            cout << endl << count << " record(s) saved." << endl << endl;
        }

        if (choice_search=='2')
        {
            count=search_type( accountlist, num_records);
            cout << endl << count << " record(s) saved." << endl << endl;
        }

        if (choice_search=='3')
        {
          count=search_price( accountlist, num_records);
          cout << endl << count << " record(s) saved." << endl << endl;
        }
        if (choice_search=='4')
        {
          count=search_method( accountlist, num_records);
          cout << endl << count << " record(s) saved." << endl << endl;
        }
        break;

      case '4':
  			cout << "Please enter the filename: ";
  			cin >> str;
				count = save_accountlist(str, accountlist, num_records);
				cout << endl << count << " record(s) saved." << endl << endl;
				break;

			case '5':
  			if (num_records >= as_size)
  				grow_accountlist(accountlist, as_size, 100);

				if (num_records < as_size)
  				num_records = add_record(accountlist, num_records);
  				cout << "There are now " << num_records <<
  				" record(s) in the accountlist." << endl << endl;
  				break;

      case '6':
        Update_list(accountlist,num_records);
        break;

      case '7':
        delete_element(accountlist,num_records,as_size);
        break;

      default:
				cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}
  cout << "Goodbye!" << endl << endl;
  delete [] accountlist;
  return 0;
}

char selection_menu()
{
	char choice;

	// print selection menu
	cout << "****************************************" << endl;
	cout << "* Welcome to Accounting System Manager *" << endl;
	cout << "****************************************" << endl;
	cout << "1. Load a Accounting System." << endl;
	cout << "2. Print all records." << endl;
	//cout << "3. Sort the records by ascending order of the name." << endl;
	cout << "3. Search the records by partial match of the name." << endl;
	cout << "4. Save the Accounting System." << endl;
	cout << "5. Add a new record." << endl;
  cout << "6. Edit a record." << endl;
  cout << "7. Delete a record." << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;
  return choice;
}

char selection_search()
{
	char choice;

	// print selection menu
	cout << "*************" << endl;
	cout << "* Search by *" << endl;
	cout << "*************" << endl;
	cout << "1. Date." << endl;
	cout << "2. Type." << endl;
	cout << "3. Price." << endl;
	cout << "4. Account." << endl;
  cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;
  return choice;
}
int load_accountlist(string filename, AccRec * &as, int &as_size)
{
    int count = 0;
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i = 0;
    string line;
    while (getline(fin, line))
    {
		if (i >= as_size)
			grow_accountlist(as, as_size, 100);

		// extract a name and a phone no. from a line
		if (i < as_size) {
	        istringstream iss(line);
	        if (!getline(iss, as[i].date,','))
	            break;
          if (!getline(iss, as[i].category,','))
    	        break;
          if (!getline(iss, as[i].price,','))
    	        break;
	        if (!getline(iss, as[i].account))
	            break;
	        ++i;
	    }
    count++;
    }
    fin.close();
    cout << count << " record(s) loaded." << endl << endl;
    return i;
}

void print_accountlist(AccRec as[], int nRec)
{
    int count = 0;
    int i;
    for (i = 0; i < nRec; i++)
    {
        display(as,i);
        count++;
    }
    cout << count << " record(s) printed." << endl << endl;
}

int save_accountlist(string filename, AccRec as[], int nRec)
{
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }
    int i;
    for (i = 0; i < nRec; i++)
    {
        fout << as[i].date << "," << as[i].category<<","<<as[i].price<<","<<as[i].account<<endl;
    }
    fout.close();
    return i;
}

int add_record(AccRec as[], int nRec)
{
	char ans;
	string str,choice,price;
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
    cout << "Please enter the price: HKD ";
  	cin>>price;
    as[nRec].price="-"+price;
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
    cout << "Please enter the price in HKD: ";
    cin>>price;
    as[nRec].price=price;
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
	   for (i = 0; i < nRec; i++)
     {
       string date_now = as[i].date;
		   if (date_now==str)
       {
         if (location_checker==0){
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

    for (i=0;i<nRec;i++)
    {
      string date_now = as[i].date;
      pos=date_now.find("/");
      date_now=date_now.substr(pos+1);
      if(date_now==str)
      {
        if (location_checker==0){
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
        if (location_checker==0){
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
  location_checker=0;
  return count;
}
int search_price(AccRec as[], int nRec)
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
      string temp = as[i].price;
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
      string temp = as[i].price;
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

int search_type( AccRec as[], int nRec)
{
  int choice,pos;
  int choice2;
  int i, count = 0,check_type=0;
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"},price;
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
            if(type!=list[i] and (as[k].price).substr(0,1)=="-"){
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
    cout<<"The result for "+ list2[choice2-1] + " is/are the following:"<<endl<<endl;
    if(choice2!=4){
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        if (type==list2[choice2-1]){
          display(as,k);
          count++;
        }
      }
    }
    else{
      for(int k=0;k<nRec;k++){
        string type=as[k].category;
        for(int i=0;i<4;i++){
            if(type!=list2[i] and (as[k].price).substr(0,1)!="-"){
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
int search_method( AccRec as[], int nRec)
{
  int pos;
  int choice2;
  int i, count = 0,check_type=0;
  string list[4]={"Cash","Bank account","Credit card","Other"};
//string list2[4]={"Monthly income","Pocket money","Stock","Other"},price;
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
void display(AccRec as[],int i){
  cout << "Date:  " << as[i].date << endl;
  cout<<"Price:  HKD "<<as[i].price<<endl;
  cout<<"Type:  "<<as[i].category<<endl;
  cout<<"Account:  "<<as[i].account<<endl<<endl;
}

void grow_accountlist(AccRec * &as, int &as_size, int n)
{
	// create a new dynamic array with a new size = max_size + n
	AccRec * as_new = new AccRec[as_size + n];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < as_size; i++)
	{
		as_new[i] = as[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] as;
	// assign the pointer to the new dynamic array to the pointer variable
	as = as_new;
	// update the size of the array
	as_size += n;

	cout << "---> accountlist size enlarged to hold a maximum of " << as_size << " records." << endl;

	return;
}
void Update_list(AccRec as[],int nRec)
{
  string list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"},name_Other,price;
  string list3[4]={"Cash","Bank account","Credit card","Other"};
  int choice,choice_category,choice_pay;
  string choice2,choice_IE="N",temp;
  location_checker=1;
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
  cout<<"Change Price? (Y/N): ";
  cin>>choice2;
  if ((as[choice].price).substr(0,1)=="-"){
    temp="E";
  }
  else{
    temp="I";
  }
  if (choice2=="Y"){
    cout<<"Type in the new price in HKD: ";
    cin>>price;
    if ((choice_IE=="E" and temp=="I") or (choice_IE=="E" and temp=="E")){
      as[choice].price="-"+ price;
    }
    if ((choice_IE=="I" and temp=="I") or (choice_IE=="I" and temp=="E")){
      as[choice].price=price;
    }
  }
  else{
    if (choice_IE=="E" and temp=="I")
    {
      as[choice].price="-"+as[choice].price;
    }
    if (choice_IE=="I" and temp=="E")
    {
      as[choice].price=(as[choice].price).substr(1);
    }
    if(choice_IE=="E" and temp=="E")
    {
      as[choice].price=as[choice].price;
    }
    if (choice_IE=="I" and temp=="I")
    {
      as[choice].price=as[choice].price;
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
  location_checker=0;
}
void display_for_search(AccRec as[],int i)
{
  cout<<"Location Number= "<<i<<endl;
  cout << "Date:  " << as[i].date << endl;
  cout<<"Price:  HKD "<<as[i].price<<endl;
  cout<<"Type:  "<<as[i].category<<endl;
  cout<<"Pay Method:  "<<as[i].account<<endl<<endl;
}

void delete_element(AccRec * &as, int n,int as_size)
{
    int choice;
    location_checker=1;
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
    location_checker=0;
    return;
}
