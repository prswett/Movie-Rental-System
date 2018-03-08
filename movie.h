#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <sstream>
#include <string>

using namespace std;

class Movie {

private:
	char _movieGenre;
	string _director;
	string _title;
	int _stock;

public:
	/*
	char _movieGenre;
	string _director;
	string _title;
	int _stock;
	*/
	Movie();
	//Movie(char movieGenre, int stock, string director, string title);
	char getMovieGenre();
	string getDirector();
	string getTitle();
	int getStock();
	void borrowMovie();
	void returnMovie();
	void setMovieGenre(char movieGenre);
	void setDirector(string director);
	void setTitle(string title);
	void setStock(int stock);




};

#endif