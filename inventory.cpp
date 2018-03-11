#include <iostream>
#include "inventory.h"

using namespace std;

// no args constructor
Inventory::Inventory()
{
}

// destructor of inventory
Inventory::~Inventory()
{
}

// checks to see if we can actually borrow a movie from the inventory
// returns -1 if invalid movie, 0 if out of stock, and 1 if checkout successful.
int Inventory::borrowComedyMovie(string movieID)
{
	// sets iterator to the movie we are looking for
	auto iterator = _comedy.find(movieID);
	// if the movie is not in the inventory
	if (iterator == _comedy.end()) {
		// then we cannot rent it
		return -1;
	}
	// if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		// decrement the stock of movies
		iterator->second.borrowMovie();
		// and tell the driver we rented it
		return 1;
	}
	// else if movie is found and stock is 0
	// then we cannot rent the movie
	return -1;
}

// finds the comedy movie we want by passing in the key
// increments the stock of the movie by 1
void Inventory::returnComedyMovie(string movieID)
{
	// sets iterator to where the movie is
	auto iterator = _comedy.find(movieID);
	// increments the stock of the movie
	iterator->second.returnMovie();
}

// checks to see if we can actually borrow a movie from the inventory
// returns -1 if invalid movie, 0 if out of stock, and 1 if checkout successful.
int Inventory::borrowDramaMovie(string movieID)
{
	// sets iterator to the movie we are looking for
	auto iterator = _drama.find(movieID);
	// if the movie is not in the inventory
	if (iterator == _drama.end()) {
		// then we cannot rent it
		return -1;
	}
	// if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		// decrement the stock of movies
		iterator->second.borrowMovie();
		// tell driver we rented movie
		return 1;
	}
	// else if movie is found and stock is 0
	// then we cannot rent the movie
	return 0;
}

// finds the drama movie we want by passing in the key
// increments the stock of the movie by 1
void Inventory::returnDramaMovie(string movieID)
{
	// sets iterator to where the movie is
	auto iterator = _drama.find(movieID);
	// increments the stock of the movie
	iterator->second.returnMovie();
}

// checks to see if we can actually borrow a movie from the inventory
// returns -1 if invalid movie, 0 if out of stock, and 1 if checkout successful.
int Inventory::borrowClassicMovie(string movieID)
{
	// sets iterator to the movie we are looking for
	auto iterator = _classic.find(movieID);
	// checks to see if movie is not in inventory
	if (iterator == _classic.end()) {
		// if it isn't we can't rent it
		return -1;
	}
	// if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		// decrement the stock of movies
		iterator->second.borrowMovie();
		// tell driver we rented movie
		return 1;
	}
	// else if movie is found and stock is 0
	// then we cannot rent the movie
	return 0;
}

// finds the classic movie we want by passing in the key
// increments the stock of the movie by 1
void Inventory::returnClassicMovie(string movieID)
{
	// sets iterator to where the movie is
	auto iterator = _classic.find(movieID);
	// increments the stock of the movie by 1
	iterator->second.returnMovie();
}


// prints out a list of comedy movies in order
void Inventory::printComedy()
{
	// sets iterator to start of the map
	auto iterator = _comedy.begin();
	// while there are still things in the map
	while (iterator != _comedy.end()) {
		// print out the movie
		cout << iterator->second.getFullComedyInfo() << endl;
		// increment iterator
		++iterator;
	}
}

// prints out a list of drama movies in order
void Inventory::printDrama()
{
	// sets iterator to start of the map
	auto iterator = _drama.begin();
	// while there are still things in the map
	while (iterator != _drama.end()) {
		// print out the movie
		cout << iterator->second.getFullDramaInfo() << endl;
		// increment iterator
		++iterator;
	}
}

// prints out a list of classic movies in order
void Inventory::printClassic()
{
	// sets iterator to start of the map
	auto iterator = _classic.begin();
	// while there are still things in the map
	while (iterator != _classic.end()) {
		// print out the movie
		cout << iterator->second.getFullClassicInfo() << endl;
		// increment iterator
		++iterator;
	}
}

// prints all the movies availible in correct order
void Inventory::printMovieList()
{
  cout << "Current inventory:" << endl;
	printComedy();
	printDrama();
	printClassic();
}

// Adds a comedy movie object to the list of comedy movies.
// If the movie already exists in the list, the movie's stock will be updated
// instead and no new object is added.
void Inventory::addComedy(string movieID, Comedy other)
{
  if (_comedy.count(movieID) > 0) {  // movie exists, update stock
    auto it = _comedy.find(movieID);
    int newStock = other.getStock() + it->second.getStock();
    it->second.setStock(newStock);
  } else {  // does not exist, so add it
    _comedy.emplace(movieID, other);
  }
}

// Adds a drama movie object to the list of drama movies.
// If the movie already exists in the list, the movie's stock will be updated
// instead and no new object is added.
void Inventory::addDrama(string movieID, Drama other)
{
  if (_drama.count(movieID) > 0) {  // movie exists, update stock
    auto it = _drama.find(movieID);
    int newStock = other.getStock() + it->second.getStock();
    it->second.setStock(newStock);
  } else {  // does not exist, so add it
    _drama.emplace(movieID, other);
  }
}

// Adds a classic movie object to the list of classic movies.
// If the movie already exists in the list, the movie's stock will be updated
// instead and no new object is added.
void Inventory::addClassic(string movieID, Classic other)
{
  if (_classic.count(movieID) > 0) {  // movie exists, update stock
    auto it = _classic.find(movieID);
    int newStock = other.getStock() + it->second.getStock();
    it->second.setStock(newStock);
  } else {  // does not exist, so add it
    _classic.emplace(movieID, other);
  }
}
