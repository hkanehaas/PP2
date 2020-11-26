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


        //The following two for loops edit the client and product values based on the purchases input

        for (Product &IterateProducts : productList.productList) { 

            if (productName == IterateProducts.GetName()) {
                price = IterateProducts.GetIntVar();
                totlaUnitsSold = IterateProducts.GetCurrentSales() + unitsSold;
                IterateProducts.SetCurrentSales(totlaUnitsSold);
                break;
            }

        }
        
        for (GenericObject &IterateClients : clientList.clientList) {

            if (clientName == IterateClients.GetName()) {
                totalSoldToClient = IterateClients.GetIntVar() + (price * unitsSold);
                IterateClients.SetIntVar(totalSoldToClient);
                break;
            }
        }


        ++i;

    }

    inputFS.close(); // Done with file, so close it
}


void sales::OutputFile()
{
    int sumProductsSold = 0;
    int DollarValProductSold;

    outputFS.open("MonthlySalesReport.txt"); //create file for output

    if (!outputFS.is_open()) { //if file fails to generate
        cout << "Could not generate MonthlySalesReport.txt file." << endl;
        //return 1;
    }

    // Write to output grade report file

    outputFS << setw(50) << "MONTHLY SALES REPORT\t" << endl;
    outputFS << setfill('*') << setw(100) << "" << endl;
    outputFS << setfill(' ');

    outputFS << setw(5) << "Month\t";
    outputFS << setw(15) << "Product Name\t";
    outputFS << setw(17) << "Products sold\t";
    outputFS << setw(10) << endl;

    for (Sale IterateSales : saleList) { //iterate through vector and add each client to the output file

        outputFS << setw(5) << left << IterateSales.GetMonth() << "\t";
        outputFS << setw(20) << left << IterateSales.GetName() << "\t";
        outputFS << IterateSales.GetIntVar() << "\t";
        outputFS << endl;
        outputFS << setfill('-') << setw(100) << "" << endl;
        outputFS << setfill(' ') << right;
        outputFS << endl;

    }

    //outputFS << "Total Monthly Sales: $" << sumProductsSold << endl;

    outputFS.close(); // Done with file, so close it
}


void sales::PrintSales()
{
    for (Sale IterateSale : saleList)
        IterateSale.PrintObj();
}


void sales::PrintSpecificClientSales(string clientName)
{
    for (Sale IterateSale : saleList) {

        if (clientName == IterateClients.GetName()) {
            IterateClients.PrintObj();
        }
    }

}


void sales::AddNewPurchase()
{
    string productName;
    string clientName;
    int unitsSold;
    int monthSold;

    cout << "Product name?" << endl;
    cin.ignore(); // clear cin buffer
    getline(cin, productName); //retrieve Product name from user

    cout << "Client Name?" << endl;
    getline(cin, clientName); //retrieve Product address from user

    cout << "Units Sold?" << endl;
    cin >> unitsSold; //retrieve Product price from user

    cout << "Month Sold?" << endl;
    cin >> monthSold; //retrieve Product sales from user

    currSale.SetName(productName); //set name into vector via Product class
    currSale.SetDescriptor(clientName); //set address into Product class holder
    currSale.SetIntVar(unitsSold); //set sales into vector via Product class
    currSale.SetMonth(monthSold); //set sales into vector Product rep class

    saleList.push_back(currSale);

    cout << "New Sale of item: " << currSale.GetName() << " has been added." << endl;
}


void sales::UpdateSale(int purchaseID)
{
    char charHolder;
    string stringHolder;
    int intHolder;

    cout << "Searching for: " << purchaseID << endl;

    for (Sale& IterateSale : saleList) { //iterate through vector and search for product to update

        if (IterateSale.GetID() == purchaseID) {

            cout << "Enter column to update: (p for product name, c for client name, u for units sold, m for month purchased, q for quit" << endl;
            cin >> charHolder;

            if (charHolder == 'q') {
                break;
            }

            else if (charHolder == 'p') {
                cin.ignore();
                cout << "Enter NEW product name:" << endl;
                getline(cin, stringHolder);
                IterateSale.SetName(stringHolder);
                break;
            }
            else if (charHolder == 'c') {
                cin.ignore();
                cout << "Enter NEW client name:" << endl;
                getline(cin, stringHolder);
                IterateSale.SetDescriptor(stringHolder);
                break;
            }
            else if (charHolder == 'u') {
                cin.ignore();
                cout << "Enter NEW units sold:" << endl;
                cin >> intHolder;
                IterateSale.SetIntVar(intHolder);
                break;
            }
            else if (charHolder == 'm') {
                cin.ignore();
                cout << "Enter NEW month purchased:" << endl;
                cin >> intHolder;
                IterateSale.SetMonth(intHolder);
                break;
            }

        }
    }

    cout << "Purchase not found. Please check the purchase ID and try again." << endl;
}


int sales::GetNumLines(string filePath)
{
    ifstream inFile(filePath);
    numLines = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n') + 1;

    return numLines;
}
