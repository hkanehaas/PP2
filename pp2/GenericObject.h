#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class GenericObject
{
public:
	GenericObject();
	void SetName(string name);
	void SetDescriptor(string description);
	void SetIntVar(int objtInt);
	string GetName();
	string GetDescriptor();
	int GetIntVar();
	void PrintObj();
private:
	
	string ObjectName;
	string ObjectDescript;
	int objectIntVar;
};

