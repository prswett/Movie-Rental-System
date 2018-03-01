#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "customer.h"
#include "inventory.h"
#include <iostream>
using namespace std;



void initializeCustomers(string fileName) {
	//getline
	//first token is id number
	//second token is last name
	//third token is first name
	//construct customer
	//add to global list
}

void initializeMovies(string fileName) {
	//getline
	//get type of movie
	//depending on type create comedy,drama,classic
	//create object
	//add to inventory
}


void initializeCommands(string fileName) {

}



int main() {
	//comedy tests
	Comedy myComedy('f',10,"director", "title", "yearreleased" );
	cout << myComedy.getMovieGenre() << endl;
	cout << myComedy.getStock() << endl;
	cout << myComedy.getDirector() << endl;
	cout << myComedy.getTitle() << endl;
	cout << myComedy.getYearReleased() << endl;
	myComedy.borrowMovie();
	cout << myComedy.getStock() << endl;
	myComedy.returnMovie();
	cout << myComedy.getStock() << endl;
	cout << myComedy.getFullComedyInfo() << endl;
	cout << myComedy.getUniqueMovieID() << endl;
	cout << endl;

	//drama tests
	Drama myDrama('d', 10, "director", "title", "yearreleased");
	cout << myDrama.getMovieGenre() << endl;
	cout << myDrama.getStock() << endl;
	cout << myDrama.getDirector() << endl;
	cout << myDrama.getTitle() << endl;
	cout << myDrama.getYearReleased() << endl;
	myDrama.borrowMovie();
	cout << myDrama.getStock() << endl;
	myDrama.returnMovie();
	cout << myDrama.getStock() << endl;
	cout << myDrama.getFullDramaInfo() << endl;
	cout << myDrama.getUniqueMovieID() << endl;
	cout << endl;

	//classic tests
	Classic myClassic('c', 10, "director", "title", "majorActor", "release");
	cout << myClassic.getMovieGenre() << endl;
	cout << myClassic.getStock() << endl;
	cout << myClassic.getDirector() << endl;
	cout << myClassic.getTitle() << endl;
	cout << myClassic.getMajorActor() << endl;
	cout << myClassic.getReleaseDate() << endl;
	myClassic.borrowMovie();
	cout << myClassic.getStock() << endl;
	myClassic.returnMovie();
	cout << myClassic.getStock() << endl;
	cout << myClassic.getFullClassicInfo() << endl;
	cout << myClassic.getUniqueMovieID() << endl;
	cout << endl;

	//customer tests
	Customer myCustomer(1573, "west", "kanye");
	cout << myCustomer.getCustomerID() << endl;
	cout << myCustomer.getLastName() << endl;
	cout << myCustomer.getFirstName() << endl;
	myCustomer.borrowMovie("bambi");
	myCustomer.printCurrentCheckOut();
	cout << "////////////////////////////////" << endl;
	myCustomer.printCustomerHistory();
	myCustomer.borrowMovie("bambi 2");
	myCustomer.printCurrentCheckOut();
	cout << "////////////////////////////////////" << endl;
	myCustomer.printCustomerHistory();
	cout << myCustomer.isInCurrent("bambi") << endl;
	cout << myCustomer.isInCurrent("bambi 2") << endl;
	cout << myCustomer.isInCurrent("emoji movie") << endl;
	myCustomer.returnMovie("bambi");
	myCustomer.printCurrentCheckOut();
	cout << "//////////////////////////////////" << endl;
	myCustomer.printCustomerHistory();
	myCustomer.returnMovie("bambi 2");
	myCustomer.printCurrentCheckOut();
	cout << "///////////////////////////////" << endl;
	myCustomer.printCustomerHistory();
	cout << endl;

	//comedy inventory tests
	Inventory myInventory;
	Comedy myComedy2('f', 10, "jill byer", "avengers", "1987");
	Comedy myComedy3('f', 10, "matty p", "straight out of hawaii", "2009");
	Comedy myComedy4('f', 10, "derek star", "bambino", "1950");
	myInventory.addComedy(myComedy2.getUniqueMovieID(), myComedy2);
	myInventory.addComedy(myComedy3.getUniqueMovieID(), myComedy3);
	myInventory.addComedy(myComedy4.getUniqueMovieID(), myComedy4);
	myInventory.printComedy();
	cout << endl;

	//drama inventory tests using the inventory declared above
	Drama myDrama2('d', 10, "karmin veranda", "red rose", "1999");
	Drama myDrama3('d', 10, "drake sternberg", "madea", "2011");
	Drama myDrama4('d', 10, "harris bjorn", "sistine chapel", "2009");
	myInventory.addDrama(myDrama2.getUniqueMovieID(), myDrama2);
	myInventory.addDrama(myDrama3.getUniqueMovieID(), myDrama3);
	myInventory.addDrama(myDrama4.getUniqueMovieID(), myDrama4);
	myInventory.printDrama();
	cout << endl;



	return 0;
}