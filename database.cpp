#include <iostream>
#include <stdexcept>
#include "database.h"

using namespace std;

namespace Records {
	Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber) {

	}
	Database::~Database() {
		// nothing to do
	}

	Employee& Database::addEmployee(const string& firstname,
		const string& lastname) {
		Employee ee;
		ee.setFirstName(firstname);
		ee.setLastName(lastname);
		ee.setEmployeeNumber(mNextEmployeeNumber++);
		ee.hire();
		mEmployees.push_back(ee);

		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEmployee(int employeeNumber) {
		for (auto& ee : mEmployees) {
			if (ee.getEmployeeNumber() == employeeNumber) {
				return ee;
			}
		}
		throw runtime_error("no employee found");
	}

	void Database::displayAll() const {
		// int i = 0;
		cout << "----------- all employee -----------" << endl;
		for (auto& ee : mEmployees) {
			ee.display();
			// i++;
		}
		cout << "----------- all employee number: " << mEmployees.size() << endl;
	}
	void Database::displayCurrent() const {
		int i = 0;
		cout << "----------- current employee -----------" << endl;
		for (auto& ee : mEmployees) {
			if (ee.getIsHired()) {
				ee.display();
				i++;
			}		
		}
		cout << "----------- current employee number: " << i << endl;
	}
	void Database::displayFormer() const {
		int i = 0;
		cout << "----------- former employee -----------" << endl;
		for (auto& ee : mEmployees) {
			if (!ee.getIsHired()) {
				ee.display();
				i++;
			}	
		}
		cout << "----------- former employee number: " << i << endl;
	}
}