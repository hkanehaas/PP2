#pragma once
#include <string>
using namespace std;

class GenericObject
{
public:
//	void SetName;
	void SetName(string name);
	void SetDescriptor(string description);
	void SetIntVar(int objtInt);
	string GetName();
	string GetDescriptor();
	int GetIntVar();
private:
	string ObjectName;
	string ObjectDescript;
	int objectIntVar;
};

