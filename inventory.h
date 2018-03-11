#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>

#include "comedy.h"
#include "drama.h"
#include "classic.h"

// Inventory holds collections of Comedy, Drama, and Classic movie objects.
// Users can borrow and return movies, add movies, and print the collections.
class Inventory {

  // LessClassic is used to compare movie ID's for two Classic movies.
  // Compares release date year. If the years are the same, it compares months.
  // If the months are the same, it compares major actors, first by first names,
  // then by last names. It returns the true if the first ID is less than the
  // second ID at any point in the above order, or false if the first ID is
  // greater than the second ID at any point.
  class lessClassic {
  public:
    bool operator()(const string& first, const string& second) const
    {
      istringstream scanFirst(first);
      istringstream scanSecond(second);

      int firstMonth,
          firstYear,
          secondMonth,
          secondYear;
      string firstFName,
             firstLName,
             secondFName,
             secondLName;

      scanFirst >> firstMonth >> firstYear >> firstFName >> firstLName;
      scanSecond >> secondMonth >> secondYear >> secondFName >> secondLName;

      // compare variables, returning if not equal at any point
      if (firstYear != secondYear) {
        return firstYear < secondYear;
      } else if (firstMonth != secondMonth) {
        return firstMonth < secondMonth;
      } else if (firstFName != secondFName) {
        return firstFName < secondFName;
      } else {
        return firstLName < secondLName;
      }
    }
  };

private:
	// map to hold all comedy movies
	map<string, Comedy, less<string>> _comedy;
	// map to hold all drama movies
	map<string, Drama, less<string>> _drama;
	// map to hold all classic movies
  map<string, Classic, lessClassic> _classic;

public:
	// constructor
	Inventory();
	// destructor for inventory
	virtual ~Inventory();
	// borrows a comedy movie given an id
	int borrowComedyMovie(string movieID);
	// returns a comedy movie given an id
	void returnComedyMovie(string movieID);
	// borrows a drama movie given an id
	int borrowDramaMovie(string movieID);
	// returns a drama movie given a movie id
	void returnDramaMovie(string movieID);
	// borrows a classic movie given a movie id
	int borrowClassicMovie(string movieID);
	// returns a classic movie given a movie id
	void returnClassicMovie(string movieID);
	// prints all comedy movies
	void printComedy();
	// prints all drama movies
	void printDrama();
	// prints all classic movies
	void printClassic();
	// prints all movies
	void printMovieList();
	// adds a comedy movie to the list
	void addComedy(string movieID, Comedy other);
	// adds a drama movie to the list
	void addDrama(string movieID, Drama other);
	// adds a classic movie to the list
	void addClassic(string movieID, Classic other);
};

#endif
