#include "SalesRep.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int SalesRep::CalculateBonus()
{
    int saleAmount = this->GetIntVar();
        if (saleAmount >= 2000) {
            bonus = saleAmount * 10 / 100;
        }
        else if (saleAmount < 2000) {
            bonus = saleAmount * 5 / 100;
        }

    return bonus;
}

void SalesRep::PrintObj() {

    GenericObject::PrintObj();
    cout << "Yearly Bonus: $" << this->CalculateBonus() << endl;
}

