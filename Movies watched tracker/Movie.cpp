#include "Movie.h"
Movie Movie::add(string name, int rating, int w_t)
{
	movie_name = name;
	quality = rating;
	num_watched = w_t;

	return *this;
}
string Movie::get_name()
{
	return movie_name;
}
int Movie::get_watched()
{
	return num_watched;
}
void Movie::set_quality(int qualityy)
{
	quality = qualityy;
	cout << "\nrating has been modified succesfully\n";
	cout << "new rating is : " << quality << endl;;
}
int Movie::get_rating()
{
	return quality;
}
void Movie::add_one_to_num_watched()
{
	num_watched++;
}