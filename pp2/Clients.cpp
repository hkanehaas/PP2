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
    clientList.resize(vectorSize + numLines);


    int i = 0;
    while (i < numLines) {
        
        inputClientsFS >> stringHolder; //retrieve client name from file
        clientList.at(i).SetName(stringHolder); //set name into vector via client class

        inputClientsFS >> stringHolder; //retrieve client address string from file
        clientList.at(i).SetDescriptor(stringHolder); //set address string into vector via client class

        inputClientsFS >> intHolder; //retrieve client address string from file
        //TODO convert string to int?
        clientList.at(i).SetIntVar(intHolder); //set address string into vector via client class

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

    for (int i = 0; i < numLines; ++i) {

        outputClientsFS << clientList.at(i).GetName() << "\t";
        outputClientsFS << clientList.at(i).GetDescriptor() << "\t";
        outputClientsFS << clientList.at(i).GetIntVar() << "\t";
        outputClientsFS << endl;
    }

}

void Clients::PrintClients()
{
    // TODO: Add your implementation code here.

}
void Clients::PrintSingleClient(string clientName)
{
    for (int i = 0; i < numLines; ++i) {
        if (clientName == clientList.at(i).GetName()) {
            cout << "Name: " << clientList.at(i).GetName() << " Address: " << clientList.at(i).GetDescriptor()
                << "Sales to date: " << clientList.at(i).GetIntVar() << endl;
        }
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

