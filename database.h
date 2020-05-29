#pragma once
#include <iostream>
#include <vector>
#include "employee.h"

namespace Records {
	const int kFirstEmployeeNumber = 100;
	class Database {
	public:
		Database();
		~Database();
		Employee& addEmployee(const std::string& firstname,
			const std::string& lastname);
		Employee& getEmployee(const int employeeNumber);
		Employee& getEmployee(const std::string& firstname,
			const std::string& lastname);
		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;
	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}