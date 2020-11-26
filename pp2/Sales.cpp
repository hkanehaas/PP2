#include "Sales.h"
#include "GenericObject.h"
#include "Clients.h"
#include "Product.h"
#include "Products.h"
#include "Sale.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void sales::InputFile(string filePath, Clients& clientList, Products& productList)
{
    string stringHolder;
    string productName;
    string clientName;
    int unitsSold;
    int totlaUnitsSold;
    int totalSoldToClient;
    int price;
    int monthSold;
    int i = 0;
    int tabLocation;
    string subStringHolder;


    int intHolder; //holds input ints
    inputFS.open(filePath); //attempts to open file
    if (!inputFS.is_open()) { //check if file path is valid and no issue opening
        cout << "Could not open file. Check file path and try again." << filePath << endl;
        //return 1; // 1 indicates error
    }

    numLines = GetNumLines(filePath); //get the number of lines to input

    
    while (i < numLines) {

        getline(inputFS, stringHolder); //get entire line and parse manually below due to spaces in input strings

        tabLocation = stringHolder.find('\t');
        productName = stringHolder.substr(0, tabLocation);
        currSale.SetName(productName);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        clientName = stringHolder.substr(0, tabLocation);
        currSale.SetDescriptor(clientName);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);


        stringstream intInput(subStringHolder);

        intInput >> unitsSold;
        currSale.SetIntVar(unitsSold);

        stringHolder.replace(0, tabLocation + 1, "");

        stringstream intInput2(stringHolder);
        intInput2 >> monthSold;

        currSale.SetMonth(monthSold);
        saleList.push_back(currSale);


        //below is adding purchase details to clients and products vectors
        for (Product IterateProducts : productList.productList) {  //print entire vector of clients to console

            if (productName == IterateProducts.GetName()) {

                price = IterateProducts.GetIntVar();
                totlaUnitsSold = IterateProducts.GetCurrentSales() + unitsSold;
                IterateProducts.SetCurrentSales(totlaUnitsSold);
                break;
            }

        }


        for (GenericObject IterateClients : clientList.clientList)
            if (clientName == IterateClients.GetName()) {
                totalSoldToClient = IterateClients.GetIntVar() + (price * unitsSold);
                IterateClients.SetIntVar(totalSoldToClient);
                break;
            }


        ++i;

    }

    inputFS.close(); // Done with file, so close it
}


void sales::OutputFile()
{
    // TODO: Add your implementation code here.
}


void sales::PrintSales()
{
    // TODO: Add your implementation code here.
}


void sales::PrintSpecificClientSales(string clientName)
{
    // TODO: Add your implementation code here.
}


void sales::AddNewPurchase()
{
    // TODO: Add your implementation code here.
}


void sales::UpdateSale(string purchaseID)
{
    // TODO: Add your implementation code here.
}


int sales::GetNumLines(string filePath)
{
    ifstream inFile(filePath);
    numLines = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n') + 1;

    return numLines;
}
