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
    void SetMonth(int month);
    void SetProductPointer(int productID);
    void SetClientPointer(int clientID);
    int GetMonth();
    int GetProductPointer();
    int GetClientPointer();
private:
    int ClientID;
    int Month;
    int ProductID;
};

