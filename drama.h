#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "movie.h"

using namespace std;

// A Drama movie contains a release year as well as
// the other variables a Movie has. Users can retrieve Drama movie
// information, including a unique movie ID and release year.
// Users have access to the same methods the Movie class has.
class Drama : public Movie {
private:
	// year released of the drama
	string _yearReleased;

public:
	// constructor for drama
	Drama(char movieGenre, int stock, string director, string title,
        string yearReleased);
	// destructor for drama
	virtual ~Drama();
	// getter for year released
	string getYearReleased();
	// gets the full movie info formatted the same as the original txt file
	string getFullDramaInfo();
	// get movieID which will be used to sort this movie in the inventory map
	// director, then title
	string getUniqueMovieID();
};

#endif
