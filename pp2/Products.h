#pragma once
#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
class Products
{
public:
	vector<Product> productList;
	void InputFile(string filePath);
	void OutputFile();
	void PrintProducts();
	void PrintSingleProduct(string productName);
	void AddNewProduct();
	void UpdateProductInfo(string productName);
	
private:
	Product currProduct;
	Product IterateProduct;
	ifstream inputFS;
	ofstream outputFS;
	int GetNumLines(string filePath);
	int numLines;
};

