#include "movie.h"

/*
//constructor for movie
Movie::Movie(char movieGenre, int stock, string director, string title)
{
	_movieGenre = movieGenre;
	_stock = stock;
	_director = director;
	_title = title;
}
*/

Movie::Movie()
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
