#include "customer.h"

//constructor for the customer object
Customer::Customer(int customerID, string lastName, string firstName)
{
	//setting the customer variables
	_customerID = customerID;
	_lastName = lastName;
	_firstName = firstName;
}

//getter for customer ID
int Customer::getCustomerID()
{
	return _customerID;
}

//getter for last name of the customer
string Customer::getLastName()
{
	return _lastName;
}

//getter for first name of the customer
string Customer::getFirstName()
{
	return _firstName;
}

//adds the movieID to the order history and to current check out
//(///////////////////be carefull with emplace because it will not add more then 1 copy/////////////////////////////)
//this is a problem if a customer tries to borrow more then one copy
//but this may not be a problem depending on design
void Customer::borrowMovie(string movieID)
{
	//adding borrowed to the current movie ID
	string finalResult = "borrowed " + movieID;
	//set iterator to start of _orderhistory vector
	auto iterator = _orderHistory.begin();
	//inserts it into index 0 so that it will be sorted latest to past
	_orderHistory.insert(iterator,finalResult);
	//puts movie into current checkout with a value of 1 copy
	_current.emplace(movieID, 1);
}

//removes movieID from current checkout
//(////////////////same problem as above with the _current.erase////////////////)
//if there is more then 1 copy is will erase all of them
//but is a customer can only take out one copy then we are fine
void Customer::returnMovie(string movieID)
{
	//adding returned to the current movie ID
	string finalResult = "returned " + movieID;
	//set iterator to start of _orderhistory vector
	auto iterator = _orderHistory.begin();
	//inserts it into index 0 so that it will be sorted latest to past
	_orderHistory.insert(iterator, finalResult);
	//erases the movie from the current check out list (THIS MAY BE A PROBLEM)
	_current.erase(movieID);
}

//returns true if movieID is in current checkout
bool Customer::isInCurrent(string movieID)
{
	//sets an iterator to the first item in the _current map
	auto iterator = _current.begin();
	//while there are still more elements in the map
	while (iterator != _current.end()) {
		//check if the key value in the map is equivalent to the movieID
		//that we are looking for
		if (iterator->first == movieID) {
			//return true if found
			return true;
		}
		++iterator;
	}
	//return false if not found
	return false;
}

//prints all customer history
void Customer::printCustomerHistory()
{
	//loop to print out the contents of the history vector
	for (int i = 0; i < _orderHistory.size(); i++) {
		cout << _orderHistory[i] << endl;
	}
}

//prints customer current checkout
void Customer::printCurrentCheckOut()
{
	// set iterator
	auto tempIt = _current.begin();
	// loop through list and print out first and second element
	for (tempIt = _current.begin(); tempIt != _current.end(); ++tempIt) {
		cout << tempIt->first << "->" << tempIt->second << endl;
	}
}
