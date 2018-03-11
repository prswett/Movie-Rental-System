#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"

using namespace std;

// A Comedy movie contains a release year as well as
// the other variables a Movie has. Users can retrieve Comedy movie
// information, including a unique movie ID and release year.
// Users have access to the same methods the Movie class has.
class Comedy: public Movie {
private:
	// year released of the comedy
	string _yearReleased;

public:
	// constructor for comedy
	Comedy(char movieGenre, int stock, string director, string title,
         string yearReleased);
	// destructor for comedy
	virtual ~Comedy();
	// getter for year released
	string getYearReleased();
	// gets the full movie info formatted the same as the orininal txt file
	string getFullComedyInfo();
	// get movieID which will be used to sort this movie in the inventory map
	// title, then year released
	string getUniqueMovieID();
};

#endif
