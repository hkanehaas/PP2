//main function where menu selection and class testing should be set up
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "Clients.h"
#include "GenericObject.h"

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
    Clients clientList; //Testing out the generic object class DELETE THIS SECTION
/*		GenericObject objct1;
	GenericObject objct2;

	//objct1.GenericObject();
	objct2.SetName("Hannah");
	objct2.SetDescriptor("This is a great description.");
	objct2.SetIntVar(521);

	objct1.PrintObj();
	objct2.PrintObj();
	*/

	while (menuSelection != 'q') {

		if (menuSelection == 'c') { //clients selected

			menuSelection = ClientMenu();

			while (menuSelection != 'q') {

				if (menuSelection == 'f') {
					cout << "Enter a filepath location:" << endl;
					cin >> filepath;
					clientList.InputFile(filepath);
				}
				else if (menuSelection == 'l') {
					clientList.PrintClients();
				}

				menuSelection = ClientMenu();


			}




		}

	}
	
   
}

