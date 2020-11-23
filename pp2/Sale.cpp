#include "Sale.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void Sale::SetMonth(string month)
{
    Month = month;
    return;
}


void Sale::SetProductPointer(string productID)
{
    ProductID = productID;
    return ;
}


void Sale::SetClientPointer(string clientID)
{
    ClientID = clientID;
    return;
}


string Sale::GetMonth()
{
    return this->Month;
}

string Sale::GetClientPointer()
{
    return this->ClientID;
}

string Sale::GetProductPointer()
{
    return this->ProductID;
}
