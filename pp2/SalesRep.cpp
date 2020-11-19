#include "SalesRep.h"
#include <string>
using namespace std;


int SalesRep::CalculateBonus()
{
    int saleAmount;
    float bonus;
    while (saleAmount != -1) {
        if (saleAmount >=20) {
            bonus = saleAmount*10/100;
        }
        else if (saleAmount <20) {
            bonus = saleAmount*5/100;
        }
        cout << "Sales bonus: "<<endl;
  
    return 0;
}


int SalesRep::GetBonus()
{
  
    return 0;
}
