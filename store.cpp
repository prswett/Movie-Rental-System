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

vector<Customer> customerList;
myHash otherCustomerList = myHash(20);
Inventory inventory;

void initializeCustomers(string fileName) {
  ifstream readFile(fileName);  // for reading data4customers.txt
  int customerID;
  string firstName,
         lastName;

  // while the file has tokens, create customer and add to list
  while (readFile >> customerID >> lastName >> firstName) {
    Customer temp = Customer(customerID, lastName, firstName);
    // add to global list
    auto iterator = customerList.begin();
    customerList.insert(iterator, temp);

  	//putting customer pointer into our hash
  	Customer* otherTemp = new Customer(customerID, lastName, firstName);
  	otherCustomerList.put(otherTemp);

    // cout << temp.getCustomerID() << temp.getFirstName() << temp.getLastName() << endl;
  }

  readFile.close();
}

void initializeMovies(string fileName) {
  ifstream readFile(fileName);
  string delimiter = ", ";
  string line,
         copy,
         director,
         title,
         releaseDate,
         majorActor,
         firstName,
         lastName;
  char movieGenre;
  int stock;
  size_t pos = 0;

  while (getline(readFile, line)) {
    copy = line;
    vector<string> lineData(5);

    for (int i = 0; i < 5; i++) {
      pos = line.find(delimiter);
      lineData[i] = line.substr(0, pos);
      line.erase(0, pos + 2);
    }

    movieGenre = (lineData[0])[0];  // get char
    stock = stoi(lineData[1]);  // convert to int
    director = lineData[2];
    title = lineData[3];
    releaseDate = lineData[4];

    istringstream scanner(releaseDate);
    if (movieGenre == 'C') {
      // get the major actor info
      scanner >> firstName >> lastName;
      majorActor = firstName + " " + lastName;
      string month, year;
      scanner >> month >> year;
      releaseDate = month + " " + year;

      Classic temp(movieGenre, stock, director, title, majorActor, releaseDate);
      inventory.addClassic(temp.getUniqueMovieID(), temp);
    } else if (movieGenre == 'F') {
      scanner >> releaseDate;
      Comedy temp(movieGenre, stock, director, title, releaseDate);
      inventory.addComedy(temp.getUniqueMovieID(), temp);
    } else if (movieGenre == 'D') {
      scanner >> releaseDate;
      Drama temp(movieGenre, stock, director, title, releaseDate);
      inventory.addDrama(temp.getUniqueMovieID(), temp);
    } else {
      cout << "Invalid Movie Type: " << copy << endl;
    }
  }

  readFile.close();
}


void initializeCommands(string fileName) {
  ifstream readFile(fileName);
  char action,
       mediaType,
       movieGenre;
  int customerID;
  string line,
         title,
         director,
         firstName,
         lastName,
         month,
         year,
         movieID;

  while (getline(readFile, line)) {
    istringstream scanner(line);
    scanner >> action;
    if (action == 'I') {
      inventory.printMovieList();
      cout << endl;
    } else if (action == 'H' || action == 'B' || action == 'R') {
      scanner >> customerID;
      Customer* temp = otherCustomerList.get(customerID);
      if (temp != nullptr) {
        if (action == 'H') {
          temp->printCustomerHistory();
          cout << endl;
        } else {
          scanner >> mediaType >> movieGenre;
          // cout << "mediaType: " << mediaType << ", movieGenre: " << movieGenre << endl;
          if (mediaType == 'D' && (movieGenre == 'F' ||
                                   movieGenre == 'D' ||
                                   movieGenre == 'C')) {
            // get the movieID
            if (movieGenre == 'F') {
              scanner >> title;
              string titlePart = title;
              while (titlePart.at(titlePart.length() - 1) != ',') {
                scanner >> titlePart;
                title += " " + titlePart;
              }
              title = title.substr(0, title.length() - 1);  // remove ','
              scanner >> year;

              movieID = title + " " + year;
            } else if (movieGenre == 'D') {
              scanner >> director;
              string namePart = director;
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
              title = title.substr(0, title.length() - 1);  // remove ','

              movieID = director + " " + title;
            } else {
              scanner >> month >> year >> firstName >> lastName;
              movieID = month + " " + year + " " + firstName + " " + lastName;
            }
            // cout << "|" << movieID << "|" << endl;

            // Borrow movie
            if (action == 'B') {
              if (movieGenre == 'F') {
                if (inventory.borrowComedyMovie(movieID)) {
                  temp->borrowMovie(movieID);
                } else {
                  cout << "Movie is not in inventory." << endl;
                }
              } else if (movieGenre == 'D') {
                if (inventory.borrowDramaMovie(movieID)) {
                  temp->borrowMovie(movieID);
                } else {
                  cout << "Movie is not in inventory." << endl;
                }
              } else {
                if (inventory.borrowClassicMovie(movieID)) {
                  temp->borrowMovie(movieID);
                } else {
                 cout << "Movie is not in inventory." << endl;
                }
              }
            } else {  // Return movie
              if (temp->isInCurrent(movieID)) {
                if (movieGenre == 'F') {
                  inventory.returnComedyMovie(movieID);
                } else if (movieGenre == 'D') {
                  inventory.returnDramaMovie(movieID);
                } else {
                  inventory.returnClassicMovie(movieID);
                }
                temp->returnMovie(movieID);
              } else {
                cout << "Customer does not have movie." << endl;
              }
            }
          } else if (mediaType != 'D') {
            cout << "Invalid Media Type: " << mediaType << endl;
          } else {
            cout << "Invalid Movie Genre: " << movieGenre << endl;
          }
        }
      } else {
        cout << "Customer does not exist: " << customerID << endl;
      }

    } else {
      cout << "Invalid Action: " << action << endl;
    }
  }
}



int main() {
  // read data4customers.txt
  initializeCustomers("data4customers.txt");
  // for (int i = 0; i < customerList.size(); i++) {
  //   Customer temp = customerList[i];
  //   cout << temp.getCustomerID() << " " << temp.getFirstName() << " " << temp.getLastName() << endl;
  // }
  // cout << endl;

  cout << "////// TIME FOR OUR HASH///////" << endl;
  //data4 customers with our hash
  otherCustomerList.printList();
  cout << endl;

  // read movie data
  initializeMovies("data4movies.txt");
  inventory.printMovieList();
  cout << endl;

  // read command data
  cout << "Reading Commands File" << endl;
  initializeCommands("data4commands.txt");
  cout << endl;

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
