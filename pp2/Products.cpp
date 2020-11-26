#include "Products.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void Products::InputFile(string filePath)
{
    string stringHolder; //holds for input string
    int intHolder; //holds input ints
    inputFS.open(filePath); //attempts to open file
    if (!inputFS.is_open()) { //check if file path is valid and no issue opening
        cout << "Could not open file. Check file path and try again." << filePath << endl;
        //return 1; // 1 indicates error
    }

    numLines = GetNumLines(filePath); //get the number of lines to input

    int i = 0;
    int tabLocation;
    string subStringHolder;
    string subStringHolder2;
    while (i < numLines) {

        getline(inputFS, stringHolder); //get entire line and parse manually below due to spaces in product names and descriptions

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currProduct.SetName(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currProduct.SetDescriptor(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        

        stringstream intInput(subStringHolder);

        intInput >> intHolder;
        currProduct.SetIntVar(intHolder);

        stringHolder.replace(0, tabLocation + 1, "");

        stringstream intInput2(stringHolder);
        intInput2 >> intHolder;

        currProduct.SetCurrentSales(intHolder);
        productList.push_back(currProduct);

        ++i;

    }

    inputFS.close(); // Done with file, so close it
}


void Products::OutputFile()
{
    int sumProductsSold = 0;
    int DollarValProductSold;

    outputFS.open("SalesYTD.txt"); //create file for output

    if (!outputFS.is_open()) { //if file fails to generate
        cout << "Could not generate MonthlySalesReport.txt file." << endl;
        //return 1;
    }

    // Write to output grade report file

    outputFS << setw(50) << "PRODUCT SALES YEAR TO DATE\t" << endl;
    outputFS << setfill('*') << setw(100) << "" << endl;
    outputFS << setfill(' ');


    outputFS << setw(15) << "Product Name\t";
    outputFS << setw(13) << "Price\t";
    outputFS << setw(17) << "Products sold\t";
    outputFS << setw(20) << "Monthly Cashflow in\t";
    outputFS << setw(10) << endl;

    for (Product IterateProducts : productList) { //iterate through vector and add each client to the output file
        DollarValProductSold = 0;
        DollarValProductSold = IterateProducts.GetCurrentSales() * IterateProducts.GetIntVar();

        sumProductsSold = DollarValProductSold + sumProductsSold;


        outputFS << setw(20) << left << IterateProducts.GetName() << "\t";
        outputFS << "$" << IterateProducts.GetIntVar() << "\t";
        outputFS << setw(15) << right << IterateProducts.GetCurrentSales() << "\t";
        outputFS << setw(15) << "$" << DollarValProductSold << "\t";
        outputFS << endl;
        outputFS << setfill('-') << setw(100) << "" << endl;
        outputFS << setfill(' ') << right;
        outputFS << endl;



    }

    outputFS << "Total Sales Year To Date: $" << sumProductsSold << endl;

    outputFS.close(); // Done with file, so close it
}


void Products::PrintProducts()
{

    for (Product IterateProducts : productList) {  //print entire vector of clients to console
        
        IterateProducts.PrintObj();
        cout << endl;
    }

    return;

}


void Products::PrintSingleProduct(string productName)
{
    for (Product IterateProducts : productList)
        if (productName == IterateProducts.GetName()) {
            cout << "Product: " << IterateProducts.GetName() << endl;
            cout << "Description: " << IterateProducts.GetDescriptor() << endl;
            cout << "Price: $" << IterateProducts.GetIntVar() << endl;
            cout << "Sold this month: " << IterateProducts.GetCurrentSales() << endl << endl;
            return;
            break;
        }
    cout << "Product not found. Please check the name and try again." << endl;
    return;
}


void Products::AddNewProduct()
{
    string name;
    string description;
    int price;
    int salesToDate;

    cout << "Product name?" << endl;
    cin.ignore(); // clear cin buffer
    getline(cin, name); //retrieve Product name from user

    cout << "Product Description?" << endl;
    getline(cin, description); //retrieve Product address from user

    cout << "Price?" << endl;
    cin >> price; //retrieve Product price from user

    cout << "Current Sales?" << endl;
    cin >> salesToDate; //retrieve Product sales from user

    currProduct.SetName(name); //set name into vector via Product class
    currProduct.SetDescriptor(description); //set address into Product class holder
    currProduct.SetIntVar(price); //set sales into vector via Product class
    currProduct.SetCurrentSales(salesToDate); //set sales into vector Product rep class

    productList.push_back(currProduct);

    cout << "New Product: " << currProduct.GetName() << " has been added." << endl;
}


void Products::UpdateProductInfo(string productName)
{
    
    char charHolder;
    string stringHolder;
    int intHolder;

    cout << "Searching for: " << productName << endl;

    for (Product& IterateProducts : productList) { //iterate through vector and search for product to update

        if (IterateProducts.GetName() == productName) {

            cout << "Enter column to update: (n for name, d for description, p for price, s for current sales, q for quit" << endl;
            cin >> charHolder;

            if (charHolder == 'q') {
                break;
            }

            else if (charHolder == 'n') {
                cin.ignore();
                cout << "Enter NEW Product name:" << endl;
                getline(cin, stringHolder);
                IterateProducts.SetName(stringHolder);
                break;
            }
            else if (charHolder == 'd') {
                cin.ignore();
                cout << "Enter NEW Product Description:" << endl;
                getline(cin, stringHolder);
                IterateProducts.SetDescriptor(stringHolder);
                break;
            }
            else if (charHolder == 'p') {
                cin.ignore();
                cout << "Enter NEW Price:" << endl;
                cin >> intHolder;
                IterateProducts.SetIntVar(intHolder);
                break;
            }
            else if (charHolder == 's') {
                cin.ignore();
                cout << "Enter NEW current sales:" << endl;
                cin >> intHolder;
                IterateProducts.SetCurrentSales(intHolder);
                break;
            }

        }
    }

    cout << "Product not found. Please check the name and try again." << endl;
    
}


int Products::GetNumLines(string filePath)
{
    ifstream inFile(filePath);
    numLines = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n') + 1;

    return numLines;
}
