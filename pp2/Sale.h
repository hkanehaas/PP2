#pragma once
#include "GenericObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Sale :
    public GenericObject
{
public:
    int SetMonth(string month);
    int SetProductPointer(string productID);
    int SetClientPointer(string clientID);
    int GetMonth();
    int GetProductPointer();
    int GetClientPointer();
private:
    string ClientID;
    string Month;
    string ProductID;
};

