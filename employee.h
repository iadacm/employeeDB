#pragma once
#include <string>

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Employee {
	public:
		Employee();
		~Employee();
		void promote(int raiseAmount = 1000);
		void demote(int demoteAmount = 1000);
		void hire();
		void fire();
		void display() const;

		//getters, setters
		void setFirstName(const std::string firstname);
		const std::string& getFirstName() const;

		void setLastName(const std::string lastname);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool getIsHired() const;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;
	};
}