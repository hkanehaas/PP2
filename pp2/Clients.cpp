#include "GenericObject.h"
#include "Clients.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Clients::InputFile(string filePath) //Opens file, runs through and adds each line to the clients vector, closes file
{
    string stringHolder; //holds for input string
    int intHolder; //holds input ints
    inputClientsFS.open(filePath); //attempts to open file
    if (!inputClientsFS.is_open()) { //check if file path is valid and no issue opening
        cout << "Could not open file. Check file path and try again." << filePath << endl;
        //return 1; // 1 indicates error
    }

    numLines = GetNumLines(filePath); //get the number of lines to input


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
    // TODO: Add your implementation code here.

}
void Clients::AddNewClient()
{
    // TODO: Add your implementation code here.

}
void Clients::UpdateClientInfo(string clientName)
{
    // TODO: Add your implementation code here.

}

