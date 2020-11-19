#include "GenericObject.h"
#include "Clients.h"
#include <iostream>
#include <fstream>
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
    while (i < numLines) {
        
        inputClientsFS >> stringHolder; //retrieve client name from file
        
        
        currClient.SetName(stringHolder); //set name into vector via client class

        inputClientsFS >> stringHolder; //retrieve client address string from file
        currClient.SetDescriptor(stringHolder); //set address string into vector via client class

        inputClientsFS >> intHolder; //retrieve client address string from file
        //TODO convert string to int?
        currClient.SetIntVar(intHolder); //set address string into vector via client class

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

    outputClientsFS << "CLIENT MASTER LIST\t";
    //TODO: make this cenetered at the top
    //TODO: make sparating line *******

    outputClientsFS << "Name\t";
    outputClientsFS << "Address\t";
    outputClientsFS << "Sales to date\t";
    outputClientsFS << endl;

    for (GenericObject IterateClients : clientList) { //iterate through vector and add each client to the output file

        outputClientsFS << IterateClients.GetName() << "\t";
        outputClientsFS << IterateClients.GetDescriptor() << "\t";
        outputClientsFS << IterateClients.GetIntVar() << "\t";
        outputClientsFS << endl;
    }

}

void Clients::PrintClients()
{
   for (GenericObject IterateClients : clientList) { 
       
       IterateClients.PrintObj(); //print entire vector of clients to console
   }


}
void Clients::PrintSingleClient(string clientName)
{
    for (GenericObject IterateClients : clientList)
        if (clientName == IterateClients.GetName()) {
            cout << "Name: " << IterateClients.GetName() << " Address: " << IterateClients.GetDescriptor()
                << "Sales to date: " << IterateClients.GetIntVar() << endl;
        }
}
void Clients::AddNewClient()
{
    string name;
    string address;
    int salesToDate;    
    int vectorSize = clientList.size() - 1;

    cout << "Client name?" << endl;
    inputClientsFS >> name; //retrieve client name from user

    inputClientsFS >> address; //retrieve client name from user

    inputClientsFS >> salesToDate; //retrieve client name from user
    clientList.resize(vectorSize + 1);
    vectorSize = clientList.size() - 1;
    clientList.at(vectorSize).SetName(name); //set name into vector via client class
    clientList.at(vectorSize).SetDescriptor(address); //set name into vector via client class
    clientList.at(vectorSize).SetIntVar(salesToDate); //set name into vector via client class
    cout << "New client: " << clientList.at(vectorSize).GetName() << " has been added." << endl;

    return;


}
void Clients::UpdateClientInfo(string clientName)
{
    char charHolder;
    string stringHolder;
    int intHolder;



            cout << "Enter column to update: (n for name, a for address, s for sales to date, q for quit" << endl;
        cin >> charHolder;

        while (charHolder != 'q') {

            if (charHolder == 'n') {
                cout << "Enter update name:" << endl;
                cin >> stringHolder;

            }

        }

}

