#include "inventory.h"

//no args constructor
Inventory::Inventory()
{
}

//destructor of inventory
Inventory::~Inventory()
{
}

//checks to see if we can actually borrow a movie from the inventory
bool Inventory::borrowComedyMovie(string movieID)
{
	//sets iterator to the movie we are looking for
	auto iterator = _comedy.find(movieID);
	//if the movie is not in the inventory
	if (iterator == _comedy.end()) {
		//then we cannot rent it
		return false;
	}
	//if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		//decrement the stock of movies
		iterator->second.borrowMovie();
		//and tell the driver we rented it
		return true;
	}
	//else if movie is found and stock is 0
	//then we cannot rent the movie
	return false;
}

//finds the comedy movie we want by passing in the key
//increments the stock of the movie by 1
void Inventory::returnComedyMovie(string movieID)
{
	//sets iterator to where the movie is 
	auto iterator = _comedy.find(movieID);
	//increments the stock of the movie
	iterator->second.returnMovie();
}

//checks to see if we can actually borrow a movie from the inventory
bool Inventory::borrowDramaMovie(string movieID)
{
	//sets iterator to the movie we are looking for
	auto iterator = _drama.find(movieID);
	//if the movie is not in the inventory
	if (iterator == _drama.end()) {
		//then we cannot rent it
		return false;
	}
	//if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		//decrement the stock of movies
		iterator->second.borrowMovie();
		//tell driver we rented movie
		return true;
	}
	//else if movie is found and stock is 0
	//then we cannot rent the movie
	return false;
}

//finds the drama movie we want by passing in the key
//increments the stock of the movie by 1
void Inventory::returnDramaMovie(string movieID)
{
	//sets iterator to where the movie is 
	auto iterator = _drama.find(movieID);
	//increments the stock of the movie
	iterator->second.returnMovie();
}

//checks to see if we can actually borrow a movie from the inventory
bool Inventory::borrowClassicMovie(string movieID)
{
	//sets iterator to the movie we are looking for
	auto iterator = _classic.find(movieID);
	//checks to see if movie is not in inventory
	if (iterator == _classic.end()) {
		//if it isn't we can't rent it
		return false;
	}
	//if the movie is found and the stock is greater then 0
	if (iterator->second.getStock() > 0) {
		//decrement the stock of movies
		iterator->second.borrowMovie();
		//tell driver we rented movie
		return true;
	}
	//else if movie is found and stock is 0
	//then we cannot rent the movie
	return false;
}

//finds the classic movie we want by passing in the key
//increments the stock of the movie by 1
void Inventory::returnClassicMovie(string movieID)
{
	//sets iterator to where the movie is 
	auto iterator = _classic.find(movieID);
	//increments the stock of the movie by 1
	iterator->second.returnMovie();
}


//prints out a list of comedy movies in order
void Inventory::printComedy()
{
	//sets iterator to start of the map
	auto iterator = _comedy.begin();
	//while there are still things in the map
	while (iterator != _comedy.end()) {
		//print out the movie
		cout << iterator->second.getFullComedyInfo() << endl;
		//increment iterator
		++iterator;
	}
}

//prints out a list of drama movies in order
void Inventory::printDrama()
{
	//sets iterator to start of the map
	auto iterator = _drama.begin();
	//while there are still things in the map
	while (iterator != _drama.end()) {
		//print out the movie
		cout << iterator->second.getFullDramaInfo() << endl;
		//increment iterator
		++iterator;
	}
}

//prints out a list of classic movies in order
void Inventory::printClassic()
{
	//sets iterator to start of the map
	auto iterator = _classic.begin();
	//while there are still things in the map
	while (iterator != _classic.end()) {
		//print out the movie
		cout << iterator->second.getFullClassicInfo() << endl;
		//increment iterator
		++iterator;
	}
}

//prints all the movies availible in correct order
void Inventory::printMovieList()
{
	printComedy();
	printDrama();
	printClassic();
}

//will add comedy movie object to the list of comedy movies
//(BUG TO FIX LATER- This will not work if you need to add more copies)
//for instance if bambi is already in the list with 10 copies
//if you try to add another 10 copies of bambi from the file we will need to manually
//edit the stock variable of the object becuase emplace will not add anything if the same
//key already exists in the list(can solve by making a stock setter method in comedy class)
void Inventory::addComedy(string movieID, Comedy other)
{
	_comedy.emplace(movieID, other);
}

//will add comedy movie object to the list of drama movies
//(BUG TO FIX LATER- This will not work if you need to add more copies)
//for instance if bambi is already in the list with 10 copies
//if you try to add another 10 copies of bambi from the file we will need to manually
//edit the stock variable of the object becuase emplace will not add anything if the same
//key already exists in the list(can solve by making a stock setter method in drama class)
void Inventory::addDrama(string movieID, Drama other)
{
	_drama.emplace(movieID, other);
}

//will add comedy movie object to the list of classic movies
//(BUG TO FIX LATER- This will not work if you need to add more copies)
//for instance if bambi is already in the list with 10 copies
//if you try to add another 10 copies of bambi from the file we will need to manually
//edit the stock variable of the object becuase emplace will not add anything if the same
//key already exists in the list(can solve by making a stock setter method in classic class)
void Inventory::addClassic(string movieID, Classic other)
{
	_classic.emplace(movieID, other);
}
