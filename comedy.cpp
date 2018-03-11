#include "comedy.h"

// constructor for comedy
Comedy::Comedy(char movieGenre, int stock, string director, string title,
               string yearReleased)
{
	// sets the variables
	setMovieGenre(movieGenre);
	setStock(stock);
	setDirector(director);
	setTitle(title);
	_yearReleased = yearReleased;
}

// destructor for comedy
Comedy::~Comedy()
{
}

// getter for year released
string Comedy::getYearReleased()
{
	return _yearReleased;
}

// gets the full movie info formatted the same as the original txt file
string Comedy::getFullComedyInfo()
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
// title, then year released
string Comedy::getUniqueMovieID()
{
	string finalResult;
	// concatonate the two strings to make the movieID
	finalResult = getTitle() + " " + _yearReleased;
	return finalResult;
}
