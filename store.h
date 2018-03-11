#ifndef STORE_H
#define STORE_H

#include "inventory.h"
#include "myHash.h"

// A Store keeps track of a list of customers and an Inventory of movies.
// It can populate the list and inventory using data from specially formatted
// files, and it can read commands to execute on the store (also from a
// specially formatted file). Users can print the current state of the
// customer list and inventory.
class Store {
private:
	myHash customerList = myHash(20000);  // to keep track of customers
	Inventory inventory;  // to keep track of movie stock

public:
  // empty constructor
	Store();
  // destructor
	virtual ~Store();
  // populates the customerList using data from a file
	void initializeCustomers(string filename);
  // populates the inventory using data from a file
	void initializeMovies(string filename);
  // executes commands from a file
	void initializeCommands(string filename);
  // executes tests for special cases (e.g. duplicate checkouts)
  void runExtraTests();
  // outputs the current state of the customerList
	void printCustomerList();
  // outputs the current state of the inventory
	void printInventory();
};

#endif
