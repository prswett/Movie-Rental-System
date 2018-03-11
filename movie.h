#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>
#include <string>

using namespace std;

class Movie {

private:
	//movie genre
	char _movieGenre;
	//director
	string _director;
	//tittle
	string _title;
	//stock
	int _stock;

public:
	//no-args constructor
	Movie();
	//destructor for movie
	virtual ~Movie();
	//movie genre getter
	char getMovieGenre();
	//director getter
	string getDirector();
	//tittle getter
	string getTitle();
	//stock getter 
	int getStock();
	//decrement movie stock
	void borrowMovie();
	//increment movie stock
	void returnMovie();
	//setter for movie genre
	void setMovieGenre(char movieGenre);
	//setter for director
	void setDirector(string director);
	//setter for tittle
	void setTitle(string title);
	//setter for stock
	void setStock(int stock);




};

#endif