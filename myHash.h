#ifndef MYHASH_H
#define MYHASH_H

#include <vector>
#include "customer.h"

// myHash is a hash table used to keep track of customer objects.
// Users can place and retrieve customers, or print the list of customers.
class myHash{
private:
	// 2d vector to hold buckets containing customer pointers
	vector<vector<Customer*>> myHashTable;
	// private function to get our hash value
	int hashFunction(int customerID);

public:
	// constructor with hardcoded number of buckets
	myHash(int numBuckets);
	// destructor for myHash
	virtual ~myHash();
	// puts the customer pointer into the hash
	void put(Customer* myCustomer);
	// gets the customer given the id number from the hash
	// will return nullptr if specified customer is not in the hash
	Customer* get(int customerID);
	// prints the customer information currently stored in hash table
	void printList();
};

#endif
