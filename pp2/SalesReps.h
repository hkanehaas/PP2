#pragma once
#include "SalesRep.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
class SalesReps
{
public:
    vector<SalesRep> salesRepList;
    void InputFile(string filePath);
    void OutputFile();
    void UpdateSalesRep(string name);
    void AddNewSalesRep();
    void FindSpecificRep(string name);
    void PrintSalesReps();
private:
    SalesRep currRep;
    SalesRep IterateReps;
    ifstream inputFS;
    ofstream outputFS;
    int GetNumLines(string filePath);
    int numLines;
};

