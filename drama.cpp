#include "drama.h"

// constructor for drama
Drama::Drama(char movieGenre, int stock, string director, string title,
             string yearReleased)
{
	// sets the variables
	setMovieGenre(movieGenre);
	setStock(stock);
	setDirector(director);
	setTitle(title);
	_yearReleased = yearReleased;
}

// destructor for drama
Drama::~Drama()
{
}

// getter for year released
string Drama::getYearReleased()
{
	return _yearReleased;
}

// gets the full movie info formatted the same as the original txt file
string Drama::getFullDramaInfo()
{
	string finalResult;

	// use string stream to turn char into a string
	stringstream ss;
	string type;
	ss << getMovieGenre();
	ss >> type;

	// turn int into a string
	string stock = to_string(getStock());

	// full movie string
	finalResult = type + " "
                + stock + " "
                + getDirector() + " "
                + getTitle() + " "
                + _yearReleased;
	return finalResult;
}

// get movieID which will be used to sort this movie in the inventory map
// director, then title
string Drama::getUniqueMovieID()
{
	string finalResult;
	// concatonate the two strings to make the movieID
	finalResult = getDirector() + " " + getTitle();
	return finalResult;
}
