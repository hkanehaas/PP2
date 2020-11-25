#include "Sale.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void Sale::SetMonth(int month)
{
    Month = month;
    return;
}


void Sale::SetProductPointer(int productID)
{
    ProductID = productID;
    return ;
}


void Sale::SetClientPointer(int clientID)
{
    ClientID = clientID;
    return;
}


int Sale::GetMonth()
{
    return this->Month;
}

int Sale::GetClientPointer()
{
    return this->ClientID;
}

int Sale::GetProductPointer()
{
    return this->ProductID;
}
