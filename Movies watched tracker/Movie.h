#pragma once
#include<iostream>
using namespace std;
class Movie
{
	string movie_name;
	int quality{ 0 }; //(0>>>>>>>>>10)
	int num_watched{ 0 };
public:
	Movie add(string name, int rating, int w_t);
	
	string get_name();
	
	int get_watched();
	
	int get_rating();

	void set_quality(int);
	void add_one_to_num_watched();
};

