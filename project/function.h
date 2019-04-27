#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
//#include <string>

struct AccRec {
    std::string date;
    std::string category;
    std::string amount;
    std::string account;
    std::string budget_list;
    int location_checker;
    int budget_counter;
};

//extern int location_checker=0;

int load_accountlist(AccRec *&as, int &as_size);
// Load accountlist data from a file into the array parameter with a maximium size
// specified by 'as_size', and return the number of records loaded

void print_accountlist(AccRec as[], int nRec);
// Print accountlist records stored in the array parameter. 'nRec' specifies the
// number of records stored in the array parameter

int save_accountlist (AccRec as[], int nRec);
// Save accountlist data stored in the array parameter into a file. 'nRec' specifies
// the number of records stored in the array parameter. Return 0 if error in
// opening file

int add_record(AccRec as[], int nRec);
// Add a new record to the accountlist and return the new size

void grow_accountlist(AccRec *&as, int &as_size, int n);
// Grow the accountlist by increasing the size of the array by n

void Update_list(AccRec as[],int nRec);
// Edit accountlist data stored in the array parameter

void delete_element(AccRec *&as, int nRec,int as_size);
// Delete accountlist data stored in the array parameter

void  Monthly_Analysis(AccRec as[],int n);
//provide monthly financial report of accountlist data stored in the array parameter

void Budget_setting(AccRec as[],int n);
//allow to set budget for the user

#endif
