#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <string>

using namespace std;

class Drama : public Movie {

private:
	//year released of the drama
	string _yearReleased;


public:
	//constructor for drama
	Drama(char movieGenre, int stock, string director, string title, string yearReleased);
	//getter for year released 
	string getYearReleased();
	//gets the full movie info formatted the same as the orininal txt file
	string getFullDramaInfo();
	//get movieID which will be used to sort this movie in the inventory map
	//director then title
	string getUniqueMovieID();



};

#endif
