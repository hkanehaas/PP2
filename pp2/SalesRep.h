#pragma once
#include "GenericObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


class SalesRep :
    public GenericObject
{
public:
    int CalculateBonus();
    int GetBonus();
};

