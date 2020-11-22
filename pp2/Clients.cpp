#include "GenericObject.h"
#include "Clients.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void Clients::InputFile(string filePath) //Opens file, runs through and adds each line to the clients vector, closes file
{
    int vectorSize = clientList.size() - 1;
    string stringHolder; //holds for input string
    int intHolder; //holds input ints
    inputClientsFS.open(filePath); //attempts to open file
    if (!inputClientsFS.is_open()) { //check if file path is valid and no issue opening
        cout << "Could not open file. Check file path and try again." << filePath << endl;
        //return 1; // 1 indicates error
    }

    numLines = GetNumLines(filePath); //get the number of lines to input
    //clientList.resize(vectorSize + numLines);

    int i = 0;
    int tabLocation;
    string subStringHolder;
    while (i < numLines) {
        
        getline(inputClientsFS, stringHolder); //get entire line and parse manually below due to spaces in client names and address

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currClient.SetName(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        tabLocation = stringHolder.find('\t');
        subStringHolder = stringHolder.substr(0, tabLocation);
        currClient.SetDescriptor(subStringHolder);
        stringHolder.replace(0, tabLocation + 1, "");

        stringstream intInput(stringHolder);

        intInput >> intHolder;
        currClient.SetIntVar(intHolder);
        clientList.push_back(currClient);
        ++i;

    }

    inputClientsFS.close(); // Done with file, so close it

}

int Clients::GetNumLines(string filename) { //CREDIT This function is from StackOverflow user: Abhay link: https://stackoverflow.com/questions/3072795/how-to-count-lines-of-a-file-in-c 

    ifstream inFile(filename);
    numLines = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n') + 1;

    return numLines;
}


void Clients::OutputFile ()
{
    outputClientsFS.open("ClientReport.txt"); //create file for output

    if (!outputClientsFS.is_open()) { //if file fails to generate
        cout << "Could not generate ClientReport.txt file." << endl;
        //return 1;
    }

    // Write to output grade report file

    outputClientsFS << setw(50) << "CLIENT MASTER LIST\t" << endl;
    outputClientsFS << setfill('*') << setw(75) << "" << endl;
    outputClientsFS << setfill(' ');


    outputClientsFS << setw(12) << "Name\t";
    outputClientsFS << setw(20) << "Address\t";
    outputClientsFS << setw(17) << "Sales to date\t";
    outputClientsFS << setw(10) << endl;

    for (GenericObject IterateClients : clientList) { //iterate through vector and add each client to the output file

        outputClientsFS << setw(20) << left << IterateClients.GetName() << "\t";
        outputClientsFS << setw(20) << left << IterateClients.GetDescriptor() << "\t";
        outputClientsFS << left << "$" << IterateClients.GetIntVar() << "\t";
        outputClientsFS << endl;
        outputClientsFS << setfill('-') << setw(75) << "" << endl;
        outputClientsFS << setfill(' ') << right;
        outputClientsFS << endl;

    }

}

void Clients::PrintClients()
{
   for (GenericObject IterateClients : clientList) { 
       
       IterateClients.PrintObj(); //print entire vector of clients to console
       cout << endl;
   }


}
void Clients::AddNewClient()
{
    string name;
    string address;
    int salesToDate; 

    cout << "Client name?" << endl;
    cin.ignore(); // clear cin buffer
    getline(cin, name); //retrieve client name from user

    cout << "Client Address?" << endl;
    getline(cin, address); //retrieve client name from user

    cout << "Sales to date?" << endl;
    cin >> salesToDate; //retrieve client name from user

    currClient.SetName(name); //set name into vector via client class
    currClient.SetDescriptor(address); //set address into client class holder
    currClient.SetIntVar(salesToDate); //set sales into vector via client class

    clientList.push_back(currClient);
    //currClient = clientList.back();

    cout << "New client: " << currClient.GetName() << " has been added." << endl;


    return;


}
void Clients::UpdateClientInfo(string clientName)
{
    char charHolder;
    string stringHolder;
    int intHolder;

    cout << "Searching for: " << clientName << endl;

    for (GenericObject &IterateClients : clientList) { //iterate through vector and add each client to the output file 

        if (IterateClients.GetName() == clientName) {
           
            cout << "Enter column to update: (n for name, a for address, s for sales to date, q for quit" << endl;
            cin >> charHolder;

            if (charHolder == 'q') {
                break;
            }

            else if (charHolder == 'n') {
                cin.ignore();
                cout << "Enter NEW client name:" << endl;
                getline(cin, stringHolder);
                IterateClients.SetName(stringHolder);
                break;
            }
            else if (charHolder == 'a') {
                cin.ignore();
                cout << "Enter NEW client address:" << endl;
                getline(cin, stringHolder);
                IterateClients.SetDescriptor(stringHolder);
                break;
            }
            else if (charHolder == 's') {
                cin.ignore();
                cout << "Enter NEW client sales to date number:" << endl;
                cin >> intHolder;
                IterateClients.SetIntVar(intHolder);
                break;
            }

        }
    }

   cout << "Client not found. Please check the name and try again." << endl;

    return;

}
void Clients::PrintSingleClient(string clientName)
{
    for (GenericObject IterateClients : clientList)
        if (clientName == IterateClients.GetName()) {
            cout << "Name: " << IterateClients.GetName() << endl;
            cout << "Address: " << IterateClients.GetDescriptor() << endl;
            cout << "Sales to date: $" << IterateClients.GetIntVar() << endl << endl;
            return;
            break;
        }
    cout << "Client not found. Please check the name and try again." << endl;
    return;
}
