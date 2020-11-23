#pragma once
#include "GenericObject.h"
#include <string>
using namespace std;


class SalesRep :
    public GenericObject
{
public:
    int CalculateBonus();
    void PrintObj();
private: 
    int bonus;
};

