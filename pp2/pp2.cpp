//main function where menu selection and class testing should be set up
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "Clients.h"

char TopMenu() {

	char topSelection;

	cout << "MENU" << endl;
	cout << "c - Client Menu" << endl;
	cout << "s - Sales Rep Menu" << endl;
	cout << "p - Purchase Menu" << endl;
	cout << "r - Sales Report Menu" << endl;
	cout << "q - quit" << endl;		
	cin >> topSelection;



	return topSelection;
}


char ClientMenu() {

	char clientSelection;

	cout << "CLIENT MENU" << endl;
	cout << "f - Input a File" << endl;
	cout << "l - List Current Clients" << endl;
	cout << "a - Add a new client" << endl;
	cout << "u - Update an existing client" << endl;
	cout << "b - Back to Main Menu" << endl;
	cout << "s - Save client report" << endl;
	cout << "q - quit" << endl;
	cin >> clientSelection;

	return clientSelection;
}





int main()
{

	char menuSelection = TopMenu(); //get initial menu char
	string filepath;
	Clients clientList;

	while (menuSelection != 'q') {

		if (menuSelection == 'c') { //clients selected

			menuSelection = ClientMenu();

			while (menuSelection != 'q') {

				if (menuSelection == 'f') {

					cout << "eneter a filepath location:" << endl;
					cin >> filepath;
					clientList.InputFile(filepath);



				}

			}




		}

	}
	

   
}

