#pragma once
#include<vector>
#include "Movie.h"
class Movies
{
	vector<Movie> movies;
public:
	void add_movie();
	void search_for_the_movie(int);
	void print_all_movies();
	int movies_num();
};

