#ifndef INVENTORY_H
#define INVENTORY_H
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Inventory {

  class lessYear {
  public:
    bool operator()(const string& first, const string& second) {
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
	//map to hold all comedy movies
	map<string, Comedy, less<string>> _comedy;
	//map to hold all drama movies
	map<string, Drama, less<string>> _drama;
	//map to hold all classic movies
	// map<string, Classic, less<string>> _classic;
  map<string, Classic, lessYear> _classic;


public:
	//constructor
	Inventory();
	bool borrowComedyMovie(string movieID);
	void returnComedyMovie(string movieID);
	bool borrowDramaMovie(string movieID);
	void returnDramaMovie(string movieID);
	bool borrowClassicMovie(string movieID);
	void returnClassicMovie(string movieID);

	//prints all comedy movies
	void printComedy();
	//prints all drama movies
	void printDrama();
	//prints all classic movies
	void printClassic();
	//prints all movies
	void printMovieList();
	//adds a comedy movie to the list
	void addComedy(string movieID, Comedy other);
	//adds a drama movie to the list
	void addDrama(string movieID, Drama other);
	//adds a classic movie to the list
	void addClassic(string movieID, Classic other);



};

#endif
