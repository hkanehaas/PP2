#include "GenericObject.h"
#include <string>
using namespace std;


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
