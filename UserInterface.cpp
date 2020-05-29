#include <iostream>
#include <stdexcept>
#include <exception>
#include "database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main() {
	Database db;
	bool done = false;

	while (!done)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 1:
			doHire(db);
			break;
		case 2:
			doFire(db);
			break;
		case 3:
			doPromote(db);
			break;
		case 4:
			db.displayAll();
			break;
		case 5:
			db.displayCurrent();
			break;
		case 6:
			db.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "unknown command" << endl;
			break;
		}
	}

	return 0;
}

int displayMenu() {
	int selection;
	cout << endl;
	cout << "employee database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire an employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employee" << endl;
	cout << "5) List current employee" << endl;
	cout << "6) List former employee" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "-------> ";
	cin >> selection;
	return selection;
}

void doHire(Database& db) {
	string firstname;
	string lastname;
	cout << "First Name? ";
	cin >> firstname;
	cout << "Last Name? ";
	cin >> lastname;

	try {
		db.addEmployee(firstname, lastname);
	}
	catch(const std::exception& e){
		cerr << "Unable to add new employee: " << e.what() << endl;
	}
}

void doFire(Database& db) {
	int employeeNumber;
	cout << "Employee Number? ";
	cin >> employeeNumber;
	try {
		Employee& ee = db.getEmployee(employeeNumber);
		ee.fire();
	}
	catch (const std::exception& e) {
		cerr << "Unable to terminate employee: " << e.what() << endl;
	}
}

void doPromote(Database& db) {
	int employeeNumber;
	int raiseNumber;

	cout << "Employee Number? ";
	cin >> employeeNumber;
	cout << "How much of raise? ";
	cin >> raiseNumber;
	try {
		Employee& ee = db.getEmployee(employeeNumber);
		ee.promote(raiseNumber);
	}
	catch (const std::exception e) {
		cerr << "Unable to promote employee: " << e.what() << endl;
	}
}