#include "SalesRep.h"
#include "SalesReps.h"
//#include "Clients.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

void SalesReps::InputFile(string filePath)
{

    int vectorSize = salesRepList.size() - 1;
    string stringHolder; //holds for input string
    int intHolder; //holds input ints
    inputFS.open(filePath); //attempts to open file
    if (!inputFS.is_open()) { //check if file path is valid and no issue opening
        cout << "Could not open file. Check file path and try again." << filePath << endl;
        //return 1; // 1 indicates error
    }

    numLines = GetNumLines(filePath); //get the number of lines to input
    //salesRepList.resize(vectorSize + numLines);

    int i = 0;
    int tabLocation;
    string subStringHolder;
    while (i < numLines) {

        getline(inputFS, stringHolder); //get entire line and parse manually below due to spaces in rep names and address
        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currRep.SetName(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currRep.SetDescriptor(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        stringstream intInput(stringHolder);

        intInput >> intHolder;
        currRep.SetIntVar(intHolder);
        salesRepList.push_back(currRep);
        ++i;

    }

    inputFS.close(); // Done with file, so close it
}


void SalesReps::OutputFile()
{
    outputFS.open("SalesRepsReport.txt"); //create file for output

    if (!outputFS.is_open()) { //if file fails to generate
        cout << "Could not generate SalesRepsReport.txt file." << endl;
        //return 1;
    }

    // Write to output grade report file

    outputFS << setw(50) << "SALES REP INFO\t" << endl;
    outputFS << setfill('*') << setw(100) << "" << endl;
    outputFS << setfill(' ');


    outputFS << setw(12) << "Name\t";
    outputFS << setw(20) << "Address\t";
    outputFS << setw(12) << "Sales to date\t";
    outputFS << setw(12) << "Bonus\t";
    outputFS << setw(10) << endl;

    for (SalesRep IterateSalesReps : salesRepList) { //iterate through vector and add each sales rep to the output file

        outputFS << setw(20) << left << IterateSalesReps.GetName() << "\t";
        outputFS << setw(20) << left << IterateSalesReps.GetDescriptor() << "\t";
        outputFS << left << "$" << IterateSalesReps.GetIntVar() << "   \t";
        outputFS << "$" << IterateSalesReps.CalculateBonus() << "\t";
        outputFS << endl;
        outputFS << setfill('-') << setw(100) << "" << endl;
        outputFS << setfill(' ') << right;
        outputFS << endl;

    }
}


void SalesReps::UpdateSalesRep(string name)
{
    char charHolder;
    string stringHolder;
    int intHolder;

    cout << "Searching for: " << name << endl;

    for (SalesRep& IterateSalesReps : salesRepList) { //iterate through vector and add each sales rep to the output file 

        if (IterateSalesReps.GetName() == name) {

            cout << "Enter column to update: (n for name, a for address, s for sales to date, q for quit" << endl;
            cin >> charHolder;

            if (charHolder == 'q') {
                break;
            }

            else if (charHolder == 'n') {
                cin.ignore();
                cout << "Enter NEW sales rep name:" << endl;
                getline(cin, stringHolder);
                IterateSalesReps.SetName(stringHolder);
                break;
            }
            else if (charHolder == 'a') {
                cin.ignore();
                cout << "Enter NEW sales rep address:" << endl;
                getline(cin, stringHolder);
                IterateSalesReps.SetDescriptor(stringHolder);
                break;
            }
            else if (charHolder == 's') {
                cin.ignore();
                cout << "Enter NEW sales rep sales to date number:" << endl;
                cin >> intHolder;
                IterateSalesReps.SetIntVar(intHolder);
                break;
            }

        }
    }

    cout << "Sales Rep not found. Please check the name and try again." << endl;

    return;
}


void SalesReps::AddNewSalesRep()
{
    string name;
    string address;
    int salesToDate;

    cout << "Sales Rep name?" << endl;
    cin.ignore(); // clear cin buffer
    getline(cin, name); //retrieve sales rep name from user

    cout << "Sales Rep Address?" << endl;
    getline(cin, address); //retrieve sales rep address from user

    cout << "Sales to date?" << endl;
    cin >> salesToDate; //retrieve sales rep sales from user

    currRep.SetName(name); //set name into vector via sales rep class
    currRep.SetDescriptor(address); //set address into sales rep class holder
    currRep.SetIntVar(salesToDate); //set sales into vector via sales rep class

    salesRepList.push_back(currRep);

    cout << "New sales rep: " << currRep.GetName() << " has been added." << endl;
}


void SalesReps::FindSpecificRep(string name)
{
    for (SalesRep IterateSalesReps : salesRepList)
        if (name == IterateSalesReps.GetName()) {
            cout << "Name: " << IterateSalesReps.GetName() << endl;
            cout << "Address: " << IterateSalesReps.GetDescriptor() << endl;
            cout << "Sales to date: $" << IterateSalesReps.GetIntVar() << endl;
            cout << "Bonus: $" << IterateSalesReps.CalculateBonus() << endl << endl;
            return;
            break;
        }
    cout << "Client not found. Please check the name and try again." << endl;
    return;
}


void SalesReps::PrintSalesReps()
{

    for (SalesRep IterateSalesReps : salesRepList) {

        IterateSalesReps.PrintObj(); //print entire vector of reps to console
        cout << endl;
    }
}

int SalesReps::GetNumLines(string filename) { //CREDIT This function is from StackOverflow user: Abhay link: https://stackoverflow.com/questions/3072795/how-to-count-lines-of-a-file-in-c 

    ifstream inFile(filename);
    numLines = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n') + 1;

    return numLines;
}
