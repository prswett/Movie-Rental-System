#include "myHash.h"



//private function to get our hash value
int myHash::hashFunction(int customerID)
{
	//get hashnumber by % by the number of buckets
	int hashedResult  = customerID % myHashTable.size();
	//return hash
	return hashedResult;
}
//constructor with hardcoded number of buckets
myHash::myHash(int numBuckets)
{
	//sets the bucket number
	myHashTable.resize(numBuckets);
}

//destructor for myHash
myHash::~myHash()
{
	//loop for vector of vectors
  int size,
      bucketSize;
  size = myHashTable.size();

	for (int i = 0; i < size; i++) {
    bucketSize = myHashTable[i].size();
		//loop to loop through the bucket
		for (int j = 0; j < bucketSize; j++) {
			//deletes the object at each pointer
			//prevents memory leaks
			delete myHashTable[i][j];
		}
	}
}

//puts the customer pointer into the hash
void myHash::put(Customer * myCustomer)
{
	//get the hash number based on customer ID
	int whereToPut = hashFunction(myCustomer->getCustomerID());
	//push to the back of the specified bucket
	myHashTable[whereToPut].push_back(myCustomer);
}

//gets the customer given the id number from the hash
//will return nullptr if specified customer is not in the hash
Customer * myHash::get(int customerID)
{
	//get the index of the bucket from the customer ID
	int whereToPut = hashFunction(customerID);
  int bucketSize = myHashTable[whereToPut].size();

	//loop to look inside bucket for same customer id
	for (int i = 0; i < bucketSize; i++) {
		//if found
		if (customerID == myHashTable[whereToPut][i]->getCustomerID()) {
			//return customer pointer
			return myHashTable[whereToPut][i];
		}
	}
	//if not found return nullptr
	return nullptr;
}

//prints the customer information currently stored in hash table
void myHash::printList()
{
  int size,
      bucketSize;
  size = myHashTable.size();

	//loop for vector of vectors
	for (int i = 0; i < size; i++) {
    bucketSize = myHashTable[i].size();
		//loop to loop through the bucket
		for (int j = 0; j < bucketSize; j++) {
			//print statement
			cout << myHashTable[i][j]->getCustomerID() << " "
           << myHashTable[i][j]->getFirstName() << " "
           << myHashTable[i][j]->getLastName() << endl;
		}
	}
}
