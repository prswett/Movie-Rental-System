#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Customer {

private:
	//variable for customer id
	int _customerID;
	//variable for last name of the customer
	string _lastName;
	//variable for first name of the customer
	string _firstName;
	//order history of all customer actions
	//from latest to previous
	vector<string> _orderHistory;
	//current movies the customer has out
	map<string, int, less<string>> _current;



public:
	//constructor for customer
	Customer(int customerID, string lastName, string firstName);
	//destructor for customer
	virtual ~Customer();
	//getter for customer id
	int getCustomerID();
	//getter for last name of customer
	string getLastName();
	//getter for first name of customer
	string getFirstName();
	//adds the movieID to the order history and to current check out
	//(this may have problems check cpp for further description)
	void borrowMovie(string movieID);
	//removes movieID from current checkout
	//(this may have problems check cpp for further description)
	void returnMovie(string movieID);
	//returns true if movieID is in current checkout
	bool isInCurrent(string movieID);
	//prints out the customer action history
	void printCustomerHistory();
	//prints out the customer current check out
	void printCurrentCheckOut();




};

#endif
