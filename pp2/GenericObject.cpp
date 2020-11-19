#include "GenericObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

GenericObject::GenericObject()
{
    ObjectName = "noName";
    ObjectDescript = "noDescription";
    objectIntVar = -1;

}


void GenericObject::SetName(string name)
{
    ObjectName = name;
    return;
}


void GenericObject::SetDescriptor(string description)
{
    ObjectDescript = description;
    return;
}


void GenericObject::SetIntVar(int objtInt)
{
    objectIntVar = objtInt;
    return;
}


string GenericObject::GetName()
{
    return this->ObjectName;
}


string GenericObject::GetDescriptor()
{
    return this->ObjectDescript;
}

int GenericObject::GetIntVar()
{
    return this->objectIntVar;
}

void GenericObject::PrintObj()
{
    cout << "Name: " << this->GetName() << " Description: " << this->GetDescriptor() << " Int Val: " << this->GetIntVar() << endl;
    return;
}
