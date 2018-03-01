#include "drama.h"

//constructor for drama
Drama::Drama(char movieGenre, int stock, string director, string title, string yearReleased)
{
	//sets the variables 
	_movieGenre = movieGenre;
	_stock = stock;
	_director = director;
	_title = title;
	_yearReleased = yearReleased;
}
//getter for year released 
string Drama::getYearReleased()
{
	return _yearReleased;
}

//gets the full movie info formatted the same as the orininal txt file
string Drama::getFullDramaInfo()
{
	string finalResult;

	//use string stream to turn char into a string 
	stringstream ss;
	string type;
	ss << _movieGenre;
	ss >> type;

	//turn int into a string
	string stock = to_string(_stock);

	//full movie string
	finalResult = type + " " + stock + " " + _director + " " + _title + " " + _yearReleased;
	return finalResult;
}

//get movieID which will be used to sort this movie in the inventory map
//director then title
string Drama::getUniqueMovieID()
{
	string finalResult;
	//concatonate the two strings to make the movieID
	finalResult = _director + " " + _title;
	return finalResult;
}
