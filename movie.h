#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>

using namespace std;

// A Movie contains information for the genre, director, and title of a movie.
// It also keeps track of a stock, to be used in an inventory setting. Users can
// get and set this information, or borrow and return Movies. It is assumed that
// only one movie can be borrowed or returned at a time.
class Movie {
private:
	// movie genre
	char _movieGenre;
	// director
	string _director;
	// title
	string _title;
	// stock
	int _stock;

public:
	// no-args constructor
	Movie();
	// destructor for movie
	virtual ~Movie();
	// movie genre getter
	char getMovieGenre();
	// director getter
	string getDirector();
	// title getter
	string getTitle();
	// stock getter
	int getStock();
	// decrement movie stock
	void borrowMovie();
	// increment movie stock
	void returnMovie();
	// setter for movie genre
	void setMovieGenre(char movieGenre);
	// setter for director
	void setDirector(string director);
	// setter for tittle
	void setTitle(string title);
	// setter for stock
	void setStock(int stock);
};

#endif
