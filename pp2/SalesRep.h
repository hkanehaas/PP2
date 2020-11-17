#pragma once
#include "GenericObject.h"
class SalesRep :
    public GenericObject
{
public:
    int CalculateBonus();
    int GetBonus();
};

