#include <iostream>
#include "function.h"
#include "display.h"
using namespace std;

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
