#include "movie.h"

//no-args constructor
Movie::Movie()
{
}
//destructor for movie
Movie::~Movie()
{
}

//getter for movie genre
char Movie::getMovieGenre()
{
	return _movieGenre;
}

//getter for director
string Movie::getDirector()
{
	return _director;
}

//getter for title
string Movie::getTitle()
{
	return _title;
}

//getter for number of copys of this movie
int Movie::getStock()
{
	return _stock;
}

//-1 to the stock when a user borrows a movie
void Movie::borrowMovie()
{
	_stock = _stock - 1;
}

//+1 to the stock when a user returns a movie
void Movie::returnMovie()
{
	_stock = _stock + 1;
}

//method to set moviegenre private variable from child classes 
void Movie::setMovieGenre(char movieGenre)
{
	_movieGenre = movieGenre;
}

//method to set director private variable from child classes 
void Movie::setDirector(string director)
{
	_director = director;
}

//method to set title private variable from child classes 
void Movie::setTitle(string title)
{
	_title = title;
}

//method to set stock private variable from child classes 
void Movie::setStock(int stock)
{
	_stock = stock;
}
