#pragma once
#include "GenericObject.h"
#include <string>
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
};

