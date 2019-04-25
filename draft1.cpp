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
    string pay_method;
};

char selection_menu();
// Print selecltion menu to screen and read user selection

int load_accountlist(string filename, AccRec * &as, int &as_size);
// Load accountlist data from a file into the array parameter with a maximium size
// specified by 'pb_size', and return the number of records loaded

void print_accountlist(AccRec as[], int nRec);
// Print accountlist records stored in the array parameter. 'nRec' specifies the
// number of records stored in the array parameter

int save_accountlist(string filename, AccRec as[], int nRec);
// Save accountlist data stored in the array parameter into a file. 'nRec' specifies
// the number of records stored in the array parameter. Return 0 if error in
// opening file

int add_record(AccRec as[], int nRec);
// Add a new record to the accountlist and return the new size

int search_date(AccRec as[], int nRec);

char selection_search();
int search_price(double from ,double to, AccRec as[], int nRec);
int search_type(AccRec as[], int nRec);
void display(AccRec as[],int i);
int search_method( AccRec as[], int nRec);
int main()
{
	int accountlist_size = 300;
    AccRec * accountlist = new AccRec[accountlist_size];

    int num_records = 0, count;
	string str = "purchase_info7.csv";
  num_records = load_accountlist(str, accountlist, accountlist_size);

	char choice = selection_menu();
  char choice_search;
	while (choice != '0')
	{
		switch (choice)
		{
			//case '1':
				//cout << "Please enter the filename: ";
				//cin >> str;
				//num_records = load_accountlist(str, accountlist, accountlist_size);
				//cout << endl << num_records << " record(s) loaded." << endl << endl;
				//break;

			case '2':
				print_accountlist(accountlist, num_records);
				break;

      case '4':
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
            double from,to;
            string str1;
            cout << "Please choose Income/Expense: ";
            cin >> str1;
            cout << endl;
            if (str1=="Income" || str1=="income")
            {
              cout << "Select your range: "<<endl;
              cout << "From: ";
              cin >> from;

              cout << "To: ";
              cin >> to;
              cout << endl;
              count=search_price(from,to,accountlist, num_records);
              cout << endl << count << " record(s) saved." << endl << endl;
            }
            else if (str1=="Expense" || str1=="expense")
            {
              cout << "Select your range: "<<endl;
              cout << "From: ";
              cin >> from;

              cout << "To: ";
              cin >> to;
              cout << endl;
              count=search_price(-1*from,-1*to,accountlist, num_records);
              cout << endl << count << " record(s) saved." << endl << endl;
            }




        }
        if (choice_search=='4')
        {
          count=search_method( accountlist, num_records);
          cout << endl << count << " record(s) saved." << endl << endl;
        }
        break;


      case '5':
  			cout << "Please enter the filename: ";
  			cin >> str;
				count = save_accountlist(str, accountlist, num_records);
				cout << endl << count << " record(s) saved." << endl << endl;
				break;

			case '6':
  			//if (num_records >= accountlist_size)
  				//grow_accountlist(accountlist, accountlist_size, 3);

				if (num_records < accountlist_size)
  				num_records = add_record(accountlist, num_records);
  				cout << "There are now " << num_records <<
  						" record(s) in the accountlist." << endl << endl;
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
	cout << "********************************" << endl;
	cout << "* Welcome to Accounting System Manager *" << endl;
	cout << "********************************" << endl;
	cout << "1. Load a Accounting System." << endl;
	cout << "2. Print all records." << endl;
	cout << "3. Sort the records by ascending order of the name." << endl;
	cout << "4. Search the records by partial match of the name." << endl;
	cout << "5. Save the Accounting System." << endl;
	cout << "6. Add a new record." << endl;
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
	cout << "********************************" << endl;
	cout << "* Search by *" << endl;
	cout << "********************************" << endl;
	cout << "1. Date." << endl;
	cout << "2. Type." << endl;
	cout << "3. Price." << endl;
	cout << "4. Pay method." << endl;


	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
int load_accountlist(string filename, AccRec * &as, int &as_size)
{
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
		//if (i >= as_size)
			//grow_accountlist(as, as_size, 10);

		// extract a name and a phone no. from a line
		if (i < as_size) {
	        istringstream iss(line);
	        if (!getline(iss, as[i].date,','))
	            break;
          if (!getline(iss, as[i].category,','))
    	        break;
          if (!getline(iss, as[i].price,','))
    	        break;
	        if (!getline(iss, as[i].pay_method))
	            break;
	        ++i;
	    }

    }

    fin.close();
    return i;
}

void print_accountlist(AccRec as[], int nRec)
{
    int i;

    for (i = 0; i < nRec; i++)
    {
        cout << "Date:  " << as[i].date << endl;
        cout << "Category:  " << as[i].category << endl;
        cout << "Price in HKD:  " << as[i].price << endl;
        cout << "Pay method:  " << as[i].pay_method << endl<<endl;
    }
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
        fout << as[i].date << "," << as[i].category<<","<<as[i].price<<","<<as[i].pay_method<<endl;
    }

    fout.close();
    return i;
}

int add_record(AccRec as[], int nRec)
{
	char ans;
	string str,choice,choice3,list[9]={"Food","Transportation","Entertainment","Fashion/beauty","Telephone","Health","Education","Supermarket","Other"};
  string list2[4]={"Monthly income","Pocket money","Stock","Other"},price;
  string list3[4]={"cash","bank account","credit card","other"};
  int choice2,choice5;
	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter the date: ";
	getline(cin, as[nRec].date);
	cout << "Please choose (Income/Expense):  ";
  cin>>choice;
  if (choice=="Expense" or choice=="expense"){
    cout<<"please choose the number of category: 1.Food 2.Transportation 3.Entertainment"<<endl;
    cout<<"                                      4.Fashion/beauty 5.Telephone 6.Health"<<endl;
    cout<<"                                      7.Education 8.Supermarket 9.other: ";
    cin>>choice2;
    if(choice2==9){
      cout<<"Specify the use of expense: ";
      cin>>str;
      as[nRec].category=str;
    }
    else{
      as[nRec].category=list[choice2-1];
    }
    cout << "Please enter the price in HKD: ";
  	cin>>price;
    as[nRec].price="-"+price;
  }
  else{
    cout<<"please choose the number of category: 1.Monthly income 2.Pocket money 3.Stock"<<endl;
    cout<<"                                      4.other: ";
    cin>>choice2;
    if (choice2==4){
      cout<<"Specify the use of income: ";
      cin>>str;
      as[nRec].category=str;
    }
    else{
      as[nRec].category=list2[choice2-1];
    }
    cout << "Please enter the price in HKD: ";
    cin>>price;
    as[nRec].price=price;
  }
  getline(cin,str);

  cout<<"please choose the number of category: 1.Cash 2.Bank account 3.credit card"<<endl;
  cout<<"                                      4.other: ";
  cin>>choice5;
  if (choice5==4){
    cout<<"Specify the type: ";
    cin>>str;
    as[nRec].pay_method=str;
  }
  else{
    as[nRec].pay_method=list3[choice5-1];
  }
	cout << endl;
	cout << "Date:\t" << as[nRec].date << endl;
  cout << "Category:\t" << as[nRec].category << endl;
  cout<< "Price:\t"<<as[nRec].price<<endl;
  cout<<"Method:\t"<<as[nRec].pay_method<<endl<<endl;
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
         cout << "Date:  " << as[i].date << endl;
         cout << "Category:  " << as[i].category << endl;
         cout<<"Price in HKD:   "<<as[i].price<<endl;
         cout<<"Pay Method:  "<<as[i].pay_method<<endl<<endl;
         count++;
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
        cout << "Date:  " << as[i].date << endl;
        cout << "Category:  " << as[i].category << endl;
        cout<<"Price in HKD:  "<<as[i].price<<endl;
        cout<<"Pay Method:  "<<as[i].pay_method<<endl<<endl;
        count++;
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
        cout << "Date:  " << as[i].date << endl;
        cout << "Category:  " << as[i].category << endl;
        cout<<"Price in HKD:  "<<as[i].price<<endl;
        cout<<"Pay Method:  "<<as[i].pay_method<<endl<<endl;
        count++;
      }
    }
  }
  return count;
}
int search_price(double from ,double to, AccRec as[], int nRec)
{
  int i,count=0;



  for (i = 0; i < nRec; i++)
	{
    string temp = as[i].price;
    double number;
    number = atof(temp.c_str());
    if (number>0)
    {
      if (number>=from && number<=to)
      {
        cout << "Date:  " << as[i].date << endl;
        cout << "Category:  " << as[i].category << endl;
        cout << "Price in HKD: " << as[i].price << endl;
        cout << "Pay Method:  " << as[i].pay_method << endl << endl;
        count++;
      }
    }
    else if (number<0)
    {
      if (number<=from && number>=to)
      {
        cout << "Date:  " << as[i].date << endl;
        cout << "Category:  " << as[i].category << endl;
        cout << "Price in HKD: " << as[i].price << endl;
        cout << "Pay Method:  " << as[i].pay_method << endl << endl;
        count++;
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
    cout<<"           7.Education 8.Supermarket 9.other: ";
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
    cout<<"          4.other: ";
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
  string list[4]={"cash","bank account","credit card","other"};
//string list2[4]={"Monthly income","Pocket money","Stock","Other"},price;
  //cout<<"Search by 1.Expense 2.Income: ";
  //cin>>choice;

    cout<<"Search by 1.cash 2.bank account 3.credit card"<<endl;
    cout<<"          4.other: ";
    cin>>choice2;
    cout<<endl;
    cout<<"The result for "+list[choice2-1]+" is/are the following:"<<endl<<endl;
    if(choice2!=4){
      for(int k=0;k<nRec;k++){
        string type=as[k].pay_method;
        if (type==list[choice2-1]){
          display(as,k);
          count++;
        }
      }
    }
    else{
      for(int k=0;k<nRec;k++){
        string type=as[k].pay_method;
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
  cout<<"Pay Method:  "<<as[i].pay_method<<endl<<endl;
}
