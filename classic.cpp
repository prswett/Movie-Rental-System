#include "classic.h"

//constructor for classic movie
Classic::Classic(char movieGenre, int stock, string director, string title, string majorActor, string releaseDate)
{
	//setting variables
	setMovieGenre(movieGenre);
	setStock(stock);
	setDirector(director);
	setTitle(title);
	_majorActor = majorActor;
	_releaseDate = releaseDate;
}
//destructor for classic
Classic::~Classic()
{
}

//getter for major actor
string Classic::getMajorActor()
{
	return _majorActor;
}

//getter for release date
string Classic::getReleaseDate()
{
	return _releaseDate;
}

//gets the full txt represenation of the movie
string Classic::getFullClassicInfo()
{
	string finalResult;

	//use string stream to turn char into a string 
	stringstream ss;
	string type;
	ss << getMovieGenre();
	ss >> type;

	//turn int into a string
	string stock = to_string(getStock());

	//full movie string
	finalResult = type + " " + stock + " " + getDirector() + " " + getTitle() + " " + _majorActor + " " + _releaseDate;
	return finalResult;
}

// gets the unique movie Id we will use to sort them later in iventory
//release date then major actor
string Classic::getUniqueMovieID()
{
	string finalResult;
	finalResult = _releaseDate + " " + _majorActor;
	return finalResult;
}
