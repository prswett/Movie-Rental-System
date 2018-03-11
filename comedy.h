#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"
#include <string>

using namespace std;

class Comedy: public Movie {

private:
	//year released of the comedy
	string _yearReleased;


public:
	//constructor for comedy
	Comedy(char movieGenre, int stock, string director, string title, string yearReleased);
	//destructor for comedy
	virtual ~Comedy();
	//getter for year released 
	string getYearReleased();
	//gets the full movie info formatted the same as the orininal txt file
	string getFullComedyInfo();
	//get movieID which will be used to sort this movie in the inventory map
	//title then year releasesd
	string getUniqueMovieID();



};

#endif
