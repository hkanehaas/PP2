#pragma once
#include "GenericObject.h"
using namespace std;
class Product :
    public GenericObject
{
public:
    void SetCurrentSales(int inputSales);
    int GetCurrentSales();
    void PrintObj();
private:
    int currentSales;

};

