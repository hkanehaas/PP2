#pragma once
#include "GenericObject.h"
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

