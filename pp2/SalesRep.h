#pragma once
#include "GenericObject.h"
#include <string>
using namespace std;


class SalesRep :
    public GenericObject
{
public:
    int CalculateBonus();
    int GetBonus();
};

