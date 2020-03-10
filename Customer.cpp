/*
 * Customer.cpp
 *
 * Nicole Vavrukh 301357534
 *      
 */

#include "Customer.h"

//Default Customer has NULLS last nam, inital and a balance of 0
Customer::Customer()
	: lastName(NULL), firstInitial(NULL), balance(0){
 }

//Sets Lastname to x, Initial to y and balance as z
 Customer::Customer(string x, char y, int z) 
	: lastName(x), firstInitial(y), balance(z) {
 }

//Returns lastname
 string Customer::getLastName() const{
	 return lastName;
 }

//Returns first intial
 char Customer::getfirstInitial() const{
	 return firstInitial;
 }

//Returns balance in account
 int Customer::getBalance() const{
	 return balance;
 }

//Sets balance in account to a new value
 void Customer::setBalance(int newBalance){
	 balance = newBalance;
 }

 bool Customer::operator<=(const Customer & c) const{

 	//if string lastname is less than c's, then customer<=c automatically
	 if (lastName<c.getLastName()){
		 return true;
	 }

	 //if last names are equal, but initials are less than or equal, customer<=c
	 if (lastName==c.getLastName() && firstInitial <= c.getfirstInitial()) {
		 return true;
	 }

	 //otherwise, customer is not <=c so false
	 return false;
 }

 bool Customer::operator<(const Customer & c) const{

 	//If last name is less than c's last name, then customer<c automatically
	if (lastName<c.getLastName()){
		 return true;
	 }

	 //If last names equal, first inital mst be less than c's for customer<c
	 if (lastName==c.getLastName() && firstInitial < c.getfirstInitial()) {
		 return true;
	 }

	 //All other scenarios have customer not less than c, so false
	 return false;
 }

 bool Customer::operator>=(const Customer & c) const{
 	 //If last name greater than c's, customer>=c
	 if (lastName > c.getLastName()) {
		 return true;
	 }

	 //If last names equal, customer's first initial must be >= for customer>=c to be true
	 if (lastName==c.getLastName() && firstInitial >= c.getfirstInitial()) {
		 return true;
	 }
	 return false;
 }

 bool Customer::operator>(const Customer & c) const{

 	//If last name greater than c's, customer>c
	if (lastName > c.getLastName()) {
		 return true;
	 }

	 //If last names equal, customer's first initial must be greater for customer>c to be true
	 if (lastName==c.getLastName() && firstInitial > c.getfirstInitial()) {
		 return true;
	 }

	 //Otherwise customer is not > c
	 return false;
 }

 bool Customer::operator==(const Customer & c) const{

 	//If both last name and initial are same, by definition customers are equal
	 if (c.getLastName() == lastName && c.getfirstInitial() == firstInitial) {
		 return true;
	 }

	 //otherwise customers are not equal, so false
	 return false;
 }

 bool Customer::operator!=(const Customer & c) const{

 	//If either last names or initials are not equal, customers are not equal
	 if (c.getLastName() != lastName || c.getfirstInitial() != firstInitial) {
		 return true;
	 }

	 //Otherwise, customers are equal and therefore return false
	 return false;
 }


ostream& operator<<(ostream & os,  Customer & c) {

	//Sets printing of customer's data to format "lastname, initial. (balance)"
	os << c.getLastName() << ", " << c.getfirstInitial() << ". (" << c.getBalance() << ")";
	return os;
}