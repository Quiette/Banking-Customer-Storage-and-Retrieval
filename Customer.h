/*
 * Customer.h
 *
 * Nicole Vavrukh; 301357534
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

using namespace std;

class Customer {
public:

	//Default contructor and 3 argument Constructor
	Customer();
	Customer(string x, char y, int z);

	//Functions that return private members
	string getLastName() const;
	char getfirstInitial() const;
	int getBalance() const;

	//Function to change private member Balance
	void setBalance(int newBalance);

	//Overload Functions
	bool operator<=(const Customer& c) const;
	bool operator<(const Customer& c) const;
	bool operator>=(const Customer& c) const;
	bool operator>(const Customer& c) const;
	bool operator==(const Customer& c) const;
	bool operator!=(const Customer& c) const;

	//Overload function of cout to print Customer
	friend ostream& operator<<(ostream & os, Customer & c);


private:

	//Private members holding relevent data
	string lastName;
	char firstInitial;
	int balance;

};

#endif /* CUSTOMER_H_ */
