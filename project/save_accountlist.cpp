#include <iostream>
#include <fstream>
#include "function.h"
using namespace std;

int save_accountlist(AccRec as[], int nRec)
{
    string filename;
    cin >> filename;
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
        fout << as[i].date << "," << as[i].category<<","<<as[i].amount<<","<<as[i].account<<endl;
    }
    fout.close();
    return i;
}
