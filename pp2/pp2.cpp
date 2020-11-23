//main function where menu selection and class testing should be set up
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "Clients.h"
#include "SalesReps.h"
#include "Products.h"
//#include "Sales.h"
#include "GenericObject.h"

char TopMenu() {

	char topSelection;

	cout << "MENU" << endl;
	cout << "c - Client Menu" << endl;
	cout << "s - Sales Rep Menu" << endl;
	cout << "p - Products and Purchases Menu" << endl;
	cout << "r - Sales Report Menu" << endl;
	cout << "q - Quit" << endl;		
	cin >> topSelection;

	return topSelection;
}


char ClientMenu() {

	char clientSelection;

	cout << "CLIENT MENU" << endl;
	cout << "f - Input a File" << endl;
	cout << "l - List Current Clients" << endl;
	cout << "o - List Specific Client" << endl;
	cout << "a - Add a new client" << endl;
	cout << "u - Update an existing client" << endl;
	cout << "s - Save client report" << endl;
	cout << "b - Back to Main Menu" << endl;
	cout << "q - Quit" << endl;
	cin >> clientSelection;

	return clientSelection;
}

char SalesRepMenu() {

	char salesRepSelection;

	cout << "SALES REP MENU" << endl;
	cout << "f - Input a File" << endl;
	cout << "l - List Current Sales Reps" << endl;
	cout << "o - List Specific Sales Rep" << endl;
	cout << "a - Add a new Sales Rep" << endl;
	cout << "u - Update an existing Sales Rep" << endl;
	cout << "s - Save Sales Rep Report" << endl;
	cout << "b - Back to Main Menu" << endl;
	cout << "q - Quit" << endl;
	cin >> salesRepSelection;

	return salesRepSelection;
}

char ProductsMenu() {

	char productsSelection;

	cout << "PRODUCTS MENU" << endl;
	cout << "f - Input a File" << endl;
	cout << "l - List All Products" << endl;
	cout << "o - List Specific Product" << endl;
	cout << "a - Add a new Product" << endl;
	cout << "u - Update an existing Product" << endl;
	cout << "s - Save Sales Monthly Sales Report" << endl;
	cout << "b - Back to Main Menu" << endl;
	cout << "q - Quit" << endl;
	cin >> productsSelection;

	return productsSelection;
}

char SalesMenu() {

	char salesSelection;

	cout << "SALES MENU" << endl;
	cout << "f - Input a File" << endl;
	cout << "l - List All Sales YTD" << endl;
	cout << "o - List YTD Sales for Specific Client" << endl;
	cout << "a - Record a Client Purchase" << endl;
	cout << "u - Update Previous Sale Info" << endl;
	cout << "s - Save Sales History File" << endl;
	cout << "b - Back to Main Menu" << endl;
	cout << "q - Quit" << endl;
	cin >> salesSelection;

	return salesSelection;
}


int main()
{

	char menuSelection = TopMenu(); //get initial menu char
	char subMenuSelection = 'z';
	string filepath;
	string stringHolder;
	Clients clientList;
	SalesReps salesRepsList;
	Products productsList;
	string updateObjectName;

	while (menuSelection != 'q') {

		if (menuSelection == 'c') { //clients sub-menu selected

			subMenuSelection = ClientMenu();

			while (subMenuSelection != 'q') {

				if (subMenuSelection == 'f') {
					cout << "Enter a filepath location:" << endl;
					cin >> filepath;
					clientList.InputFile(filepath);
				}
				else if (subMenuSelection == 'l') {
					clientList.PrintClients();
				}
				else if (subMenuSelection == 's') {
					clientList.OutputFile();
				}
				else if (subMenuSelection == 'a') {
					clientList.AddNewClient();
				}
				else if (subMenuSelection == 'u') {
					cin.ignore();
					cout << "Enter client name:" << endl;
					getline(cin, updateObjectName);
					
					clientList.UpdateClientInfo(updateObjectName);
				}
				else if (subMenuSelection == 'o') {
					cin.ignore();
					cout << "Enter client name:" << endl;
					getline(cin, updateObjectName);

					cout << "Entered: " << updateObjectName << endl;

					clientList.PrintSingleClient(updateObjectName);
				}
				else if (subMenuSelection == 'b') {
					break;
				}

				subMenuSelection = ClientMenu();
			}

		}
		else if (menuSelection == 's' ) { //sales reps sub-menu selected

			subMenuSelection = SalesRepMenu();

			while (subMenuSelection != 'q') {

				if (subMenuSelection == 'f') {
					cout << "Enter a filepath location:" << endl;
					cin >> filepath;
					salesRepsList.InputFile(filepath);
				}
				else if (subMenuSelection == 'l') {
					salesRepsList.PrintSalesReps();
				}
				else if (subMenuSelection == 's') {
					salesRepsList.OutputFile();
				}
				else if (subMenuSelection == 'a') {
					salesRepsList.AddNewSalesRep();
				}
				else if (subMenuSelection == 'u') {
					cin.ignore();
					cout << "Enter sales rep name:" << endl;
					getline(cin, updateObjectName);

					cout << "Entered: " << updateObjectName << endl;

					salesRepsList.UpdateSalesRep(updateObjectName);
				}
				else if (subMenuSelection == 'o') {
					cin.ignore();
					cout << "Enter sales rep name:" << endl;
					getline(cin, updateObjectName);

					cout << "Entered: " << updateObjectName << endl;

					salesRepsList.FindSpecificRep(updateObjectName);
				}
				else if (subMenuSelection == 'b') {
					break;
				}

				subMenuSelection = SalesRepMenu();
			}


		}
		else if (menuSelection == 'p') { //products sub-menu selected

		subMenuSelection = ProductsMenu();

			while (subMenuSelection != 'q') {

				if (subMenuSelection == 'f') {
						cout << "Enter a filepath location:" << endl;
						cin >> filepath;
						productsList.InputFile(filepath);

				}
				else if (subMenuSelection == 'l') {
					productsList.PrintProducts();
				}
				else if (subMenuSelection == 's') {
					productsList.OutputFile();
				}
				else if (subMenuSelection == 'a') {
					productsList.AddNewProduct();
				}
				else if (subMenuSelection == 'u') {
					cin.ignore();
					cout << "Enter product name:" << endl;
					getline(cin, updateObjectName);

					cout << "Entered: " << updateObjectName << endl;

					productsList.UpdateProductInfo(updateObjectName);
				}
				else if (subMenuSelection == 'o') {
					
					cin.ignore();
					cout << "Enter product name:" << endl;
					getline(cin, updateObjectName);

					cout << "Entered: " << updateObjectName << endl;

					productsList.PrintSingleProduct(updateObjectName);
				}
				else if (subMenuSelection == 'b') {
					break;
				}

				subMenuSelection = ProductsMenu();
			}


		}
		else if (menuSelection == 'r') { //sales sub-menu selected
		subMenuSelection = SalesMenu();

			while (subMenuSelection != 'q') {

				if (subMenuSelection == 'f') {
					/*	cout << "Enter a filepath location:" << endl;
						cin >> filepath;
						clientList.InputFile(filepath); */

					cout << "TODO: MENU OPTION NOT AVAILABLE." << endl;

				}
				else if (subMenuSelection == 'l') {
					//clientList.PrintClients();
					cout << "TODO: MENU OPTION NOT AVAILABLE." << endl;
				}
				else if (subMenuSelection == 's') {
					//clientList.OutputFile();
					cout << "TODO: MENU OPTION NOT AVAILABLE." << endl;
				}
				else if (subMenuSelection == 'a') {
					//clientList.AddNewClient();
				}
				else if (subMenuSelection == 'u') {
					/*cin.ignore();
					cout << "Enter client name:" << endl;
					getline(cin, inputClientName);

					cout << "Entered: " << inputClientName << endl;

					clientList.UpdateClientInfo(inputClientName); */
					cout << "TODO: MENU OPTION NOT AVAILABLE." << endl;
				}
				else if (subMenuSelection == 'o') {
					/*
					cin.ignore();
					cout << "Enter client name:" << endl;
					getline(cin, inputClientName);

					cout << "Entered: " << inputClientName << endl;

					clientList.PrintSingleClient(inputClientName); */
					cout << "TODO: MENU OPTION NOT AVAILABLE." << endl;
				}
				else if (subMenuSelection == 'b') {
					break;
				}

				subMenuSelection = SalesMenu();
			}
		}

	

		menuSelection = TopMenu();
	
	}
	
   
}

