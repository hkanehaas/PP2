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
    ObjectID = nextId; //Unique IDs - from section 11.18 in zybooks
    ++nextId; //Unique IDs - from section 11.18 in zybooks
}

int GenericObject::getNextId() { //Unique IDs - from section 11.18 in zybooks
    return nextId;
}

int GenericObject::GetID() {

    return this->ObjectID;
}

int GenericObject::nextId = 101; //Unique IDs - from section 11.18 in zybooks

void GenericObject::SetName(string name)
{
    ObjectName = name;
    ObjectID = nextId; //Unique IDs - from section 11.18 in zybooks
    ++nextId; //Unique IDs - from section 11.18 in zybooks

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
    cout << "ID: " << this->ObjectID << " " << this->GetName() << " - " << this->GetDescriptor() << " - " << this->GetIntVar() << endl;
    return;
}
