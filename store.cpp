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

using namespace std;

// professor pisan said to set defualt value to double the possibilities
// 10000*2
myHash customerList = myHash(20000);
Inventory inventory;

// Reads a file containing customer information and adds it to the customerList.
// Customers are stored as Customer objects before being added to the list.
// It is assumed that the file has valid and correctly formatted entries.
void initializeCustomers(string fileName) {
  ifstream readFile(fileName);  // for reading the file
  int customerID;
  string firstName,
         lastName;

  // while the file has tokens, create customer and add to list
  while (readFile >> customerID >> lastName >> firstName) {
  	//putting customer pointer into our hash
  	Customer* otherTemp = new Customer(customerID, lastName, firstName);
  	customerList.put(otherTemp);
  }

  readFile.close();
}

// Reads a file containing movie information and adds it to the inventory.
// Movies are stored in objects before being added to the inventory.
// It is assumed the file may have invalid entries, but every line
// must be in the correct format.
void initializeMovies(string fileName) {
  ifstream readFile(fileName);  // for reading the file
  string delimiter = ", ";  // split each line on this string
  string line,
         copy,
         director,
         title,
         releaseDate,
         month,
         year,
         majorActor,
         firstName,
         lastName;
  char movieGenre;
  int stock;
  size_t pos = 0;  // for checking each line for the delimiter

  // do this for every line in the file
  while (getline(readFile, line)) {
    copy = line;
    vector<string> lineData(5);  // for splitting the string

    // split the string by the delimiter ', '
    for (int i = 0; i < 5; i++) {
      pos = line.find(delimiter);
      lineData[i] = line.substr(0, pos);
      line.erase(0, pos + 2);
    }

    movieGenre = (lineData[0])[0];  // get char from string
    stock = stoi(lineData[1]);  // convert to int
    director = lineData[2];
    title = lineData[3];
    releaseDate = lineData[4];

    istringstream scanner(releaseDate);  // to parse the last part of the string
    if (movieGenre == 'F') {  // comedy
      scanner >> releaseDate;
      Comedy temp(movieGenre, stock, director, title, releaseDate);
      inventory.addComedy(temp.getUniqueMovieID(), temp);
    } else if (movieGenre == 'D') {  // drama
      scanner >> releaseDate;
      Drama temp(movieGenre, stock, director, title, releaseDate);
      inventory.addDrama(temp.getUniqueMovieID(), temp);
    } else if (movieGenre == 'C') {  // classic
      // get the major actor info
      scanner >> firstName >> lastName;
      majorActor = firstName + " " + lastName;

      // get release date info
      scanner >> month >> year;
      releaseDate = month + " " + year;

      Classic temp(movieGenre, stock, director, title, majorActor, releaseDate);
      inventory.addClassic(temp.getUniqueMovieID(), temp);
    } else {  // movie genre was incorrect
      cout << "\tInvalid Movie Type: " << copy << endl;
    }
  }

  readFile.close();
}

// Reads a file containing commands for the store and executes them.
// It is assumed that the file may have incorrect input, but
// all lines must be formatted correctly.
void initializeCommands(string fileName) {
  ifstream readFile(fileName);  // for reading the file
  char action,
       mediaType,
       movieGenre;
  int customerID,
      inInventory;  // for checking if borrow was successful
  string line,
         title,
         director,
         firstName,
         lastName,
         month,
         year,
         movieID;

  // do this for every line in the inputted file
  while (getline(readFile, line)) {
    istringstream scanner(line);
    scanner >> action;

    if (action == 'I') {  // command for inventory
      cout << endl;
      inventory.printMovieList();
      cout << endl;
    } else if (action == 'H' || action == 'B' || action == 'R') {  // all others
      scanner >> customerID;
      Customer* temp = customerList.get(customerID);
      if (temp != nullptr) {  // customerID returned a customer object
        if (action == 'H') {  // no customerID means history command
          temp->printCustomerHistory();
          cout << endl;
        } else {  // Borrow or Return
          scanner >> mediaType >> movieGenre;

          // check movie genre to know how to parse the command
          if (mediaType == 'D' && (movieGenre == 'F' ||
                                   movieGenre == 'D' ||
                                   movieGenre == 'C')) {
            // get the movieID
            if (movieGenre == 'F') {  // comedy movie
              scanner >> title;
              string titlePart = title;
              // everything until ',' is the title
              while (titlePart.at(titlePart.length() - 1) != ',') {
                scanner >> titlePart;
                title += " " + titlePart;
              }
              title = title.substr(0, title.length() - 1);  // omit trailing ','
              scanner >> year;

              movieID = title + " " + year;
            } else if (movieGenre == 'D') {  // drama movie
              scanner >> director;
              string namePart = director;
              // everything until ',' is the director name (can be 3 parts)
              while (namePart.at(namePart.length() - 1) != ',') {
                scanner >> namePart;
                director += " " + namePart;
              }
              director = director.substr(0, director.length() - 1);

              scanner >> title;
              string titlePart = title;
              while (titlePart.at(titlePart.length() - 1) != ',') {
                scanner >> titlePart;
                title += " " + titlePart;
              }
              title = title.substr(0, title.length() - 1);  // omit trailing ','

              movieID = director + " " + title;
            } else {  // classic movie
              scanner >> month >> year >> firstName >> lastName;
              movieID = month + " " + year + " " + firstName + " " + lastName;
            }

            // Borrow movie
            if (action == 'B') {
              if (movieGenre == 'F') {  // comedy
                // borrow if possible
                inInventory = inventory.borrowComedyMovie(movieID);
                if (inInventory == 1) {
                  temp->borrowMovie(movieID);
                }
              } else if (movieGenre == 'D') {  // drama
                // borrow if possible
                inInventory = inventory.borrowDramaMovie(movieID);
                if (inInventory == 1) {
                  temp->borrowMovie(movieID);
                }
              } else {  // classic
                // borrow if possible
                inInventory = inventory.borrowClassicMovie(movieID);
                if (inInventory == 1) {
                  temp->borrowMovie(movieID);
                }
              }

              // Borrow movie failed
              if (inInventory == -1) {
                cout << "Movie is not in inventory: "
                     << movieGenre << " " << movieID
                     << endl;
              } else if (inInventory == 0) {
                cout << "Movie out of stock: "
                     << movieGenre << " " << movieID
                     << endl;
              }
            } else {  // Return movie
              if (temp->isInCurrent(movieID)) {  // check if customer has movie
                if (movieGenre == 'F') {  // comedy
                  inventory.returnComedyMovie(movieID);
                } else if (movieGenre == 'D') {  // drama
                  inventory.returnDramaMovie(movieID);
                } else {  // classic
                  inventory.returnClassicMovie(movieID);
                }
                temp->returnMovie(movieID);
              } else {  // movie not in customer checkout
                cout << "Customer does not have movie: "
                     << movieGenre << " " << movieID
                     << endl;
              }
            }
          } else if (mediaType != 'D') {  // if media type is not DVD
            cout << "Invalid Media Type: " << mediaType << endl;
            cout << "\t In command " << line << endl;
          } else {  // if movie genre is not F, D, or C
            cout << "Invalid Movie Genre: " << movieGenre << endl;
            cout << "\t In command " << line << endl;
          }
        }
      } else {  // no customer found
        cout << "Customer does not exist: " << customerID << endl;
      }
    } else {  // not I, H, B, or R
      cout << "Invalid Action: " << action << endl;
      cout << "\t In command " << line  << endl;
    }
  }
}



int main() {
  // read data4customers.txt
  cout << "Reading Customers File..." << endl;
  initializeCustomers("data4customers.txt");

  cout << endl;
  customerList.printList();
  cout << endl;

  // read movie data
  cout << "Reading Movies File..." << endl;
  initializeMovies("data4movies.txt");

  cout << endl;
  inventory.printMovieList();
  cout << endl;

  // read command data
  cout << "Reading Commands File..." << endl;
  initializeCommands("data4commands.txt");
  cout << endl;

  cout << "Performing extra tests..." << endl;
	//comedy tests
	Comedy myComedy('f', 10,"director", "title", "yearreleased" );
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
