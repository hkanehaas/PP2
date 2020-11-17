#pragma once
#include "GenericObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Clients

{
public:
	vector<GenericObject> clientList;
	void InputFile(string filePath);
	void OutputFile();
	void PrintClients();
	void PrintSingleClient(string clientName);
	void AddNewClient();
	void UpdateClientInfo(string clientName);
private:
	ifstream inputClientsFS;
	ofstream outputClientsFS;
	int GetNumLines(string filePath);
	int numLines;
};

