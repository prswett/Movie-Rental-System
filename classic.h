#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
#include <string>

using namespace std;

class Classic : public Movie {

private:
	//major actor variable
	string _majorActor;
	//release date variable
	string _releaseDate;


public:
	//constructor for classic movie
	Classic(char movieGenre, int stock, string director, string title, string majorActor, string releaseDate);
	//getter for major actor
	string getMajorActor();
	//getter for release date
	string getReleaseDate();
	//gets the full txt represenation of the movie
	string getFullClassicInfo();
	//gets the unique movie Id we will use to sort them later in iventory
	string getUniqueMovieID();
	



};

#endif
