#include <iostream>
#include "employee.h"

namespace Records {
	// constructor of construct function
	Employee::Employee() : mFirstName(""), mLastName(""), mEmployeeNumber(-1), mSalary(kDefaultStartingSalary), mHired(false){

	}
	Employee::~Employee() {
		// nothing to do
	}
	void Employee::promote(int raiseAmount) {
		setSalary(getSalary() + raiseAmount);
	}
	void Employee::demote(int demoteAmount) {
		setSalary(getSalary() - demoteAmount);
	}
	void Employee::fire(){
		mHired = false;
	}
	void Employee::hire() {
		mHired = true;
	}
	void Employee::display() const{
		std::cout << "Employee infomation:\n" << getFirstName() << " " << getLastName() << " " << getEmployeeNumber() << " " << getSalary() << " " << getIsHired() << std::endl;
	}
	void Employee::setFirstName(std::string firstname) {
		mFirstName = firstname;
	}
	const std::string& Employee::getFirstName() const {
		return mFirstName;
	}
	void Employee::setLastName(std::string lastname) {
		mLastName = lastname;
	}
	const std::string& Employee::getLastName() const {
		return mLastName;
	}
	void Employee::setEmployeeNumber(int employeenumber) {
		mEmployeeNumber = employeenumber;
	}
	int Employee::getEmployeeNumber() const {
		return mEmployeeNumber;
	}
	void Employee::setSalary(int salary) {
		mSalary = salary;
	}
	int Employee::getSalary() const {
		return mSalary;
	}
	bool Employee::getIsHired() const {
		return mHired;
	}
}