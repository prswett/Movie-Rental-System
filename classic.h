#ifndef CLASSIC_H
#define CLASSIC_H

#include <string>
#include "movie.h"

using namespace std;

// A Classic movie contains a major actor and a release date in the M/Y format,
// as well as the other variables a Movie has. Users can retrieve Classic movie
// information, including a unique movie ID and major actor and release date.
// Users have access to the same methods the Movie class has.
class Classic : public Movie {
private:
	// major actor variable
	string _majorActor;
	// release date variable
	string _releaseDate;

public:
	// constructor for classic movie
	Classic(char movieGenre, int stock, string director, string title,
          string majorActor, string releaseDate);
	// destructor for classic
	virtual ~Classic();
	// getter for major actor
	string getMajorActor();
	// getter for release date
	string getReleaseDate();
	// gets the full txt represenation of the movie
	string getFullClassicInfo();
	// gets the unique movie Id we will use to sort them later in iventory
	string getUniqueMovieID();
};

#endif
