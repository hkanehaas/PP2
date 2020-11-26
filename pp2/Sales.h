#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Clients.h"
#include "Products.h"
#include "Sale.h"
using namespace std;
class sales
{
public:
	vector<Sale> saleList;
	void InputFile(string filePath, Clients &clientList, Products &productList);
	void OutputFile();
	void PrintSales();
	void PrintSpecificClientSales(string clientName);
	void AddNewPurchase();
	void UpdateSale(string purchaseID);
private:
	int GetNumLines(string filePath);
	int numLines;
	Sale IterateSale;
	Sale currSale;
	ifstream inputFS;
	ofstream outputFS;
};

