#include <iostream>
#include "customer.h"

// constructor for the customer object
Customer::Customer(int customerID, string lastName, string firstName)
{
	// setting the customer variables
	_customerID = customerID;
	_lastName = lastName;
	_firstName = firstName;
}

// destructor for customer
Customer::~Customer()
{
}

// getter for customer ID
int Customer::getCustomerID()
{
	return _customerID;
}

// getter for last name of the customer
string Customer::getLastName()
{
	return _lastName;
}

// getter for first name of the customer
string Customer::getFirstName()
{
	return _firstName;
}

// adds the movieID to the order history and to current check out
// it is assumed that the customer can only borrow out one movie at a time,
// but they can have more than one copy of a movie checked out.
void Customer::borrowMovie(string movieID)
{
	// adding borrowed to the current movie ID
	string finalResult = "borrowed " + movieID;
	// set iterator to start of _orderhistory vector
	auto iterator = _orderHistory.begin();
	// inserts it into index 0 so that it will be sorted latest to past
	_orderHistory.insert(iterator,finalResult);

	// puts movie into current checkout with a value of 1 copy
  if (_current.count(movieID) > 0) {  // already in _current
    _current.find(movieID)->second++;
  } else {  // not in current, so add it
    _current.emplace(movieID, 1);
  }
}

// decreases the number of copies of the inputted movie the user has checked out
// by 1 or, erases it from the list if the user only had one copy checked out.
void Customer::returnMovie(string movieID)
{
	// adding returned to the current movie ID
	string finalResult = "returned " + movieID;
	// set iterator to start of _orderhistory vector
	auto iterator = _orderHistory.begin();
	// inserts it into index 0 so that it will be sorted latest to past
	_orderHistory.insert(iterator, finalResult);

	// decrements number of copies or erases movie from the current check out list
  auto it = _current.find(movieID);
  if (it->second > 1) {
    it->second--;
  } else {
    _current.erase(movieID);
  }
}

// returns true if movieID is in current checkout
bool Customer::isInCurrent(string movieID)
{
	// sets an iterator to the first item in the _current map
	auto iterator = _current.begin();
	// while there are still more elements in the map
	while (iterator != _current.end()) {
		// check if the key value in the map is equivalent to the movieID
		// that we are looking for
		if (iterator->first == movieID) {
			// return true if found
			return true;
		}
		++iterator;
	}
	// return false if not found
	return false;
}

// prints all customer history
void Customer::printCustomerHistory()
{
  cout << "Customer " << _customerID << "'s History:" << endl;
  int size = _orderHistory.size();
	// loop to print out the contents of the history vector
	for (int i = size - 1; i >= 0; i--) {
		cout << _orderHistory[i] << endl;
	}
}

// prints customer current checkout
void Customer::printCurrentCheckOut()
{
	// set iterator
	auto tempIt = _current.begin();
	// loop through list and print out first and second element
	for (tempIt = _current.begin(); tempIt != _current.end(); ++tempIt) {
		cout << tempIt->first << "->" << tempIt->second << endl;
	}
}
