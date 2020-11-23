#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Product::SetCurrentSales(int inputSales)
{
    currentSales = inputSales;

    return;
}
int Product::GetCurrentSales() {

    return this->currentSales;
}

void Product::PrintObj() {

    cout << "ID: " << this->ObjectID << " Name: " << this->GetName()
        << " Price: $" << this->GetIntVar() << " Current Sales: "
        << this->GetCurrentSales() << endl;
    cout << "Description: " << endl;
    cout << this->GetDescriptor() << endl; //put description on it's own line

    cout  << endl;
    return;

}

