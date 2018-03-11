#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "customer.h"
#include "inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "myHash.h"

class Store {
private:
	myHash customerList = myHash(20000);
	Inventory inventory;

public:

	Store();
	virtual ~Store();
	void initializeCustomers(string filename);
	void initializeMovies(string filename);
	void initializeCommands(string filename);
	void printCustomerList();
	void printInventory();





};
