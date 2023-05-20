#include "Movies.h"
void Movies::add_movie()
{
	cout << "\nEnter the movie's name : "; string name;   cin >> name;
	cout << "Enter the movie's rating( 0 to 10 ) : "; int rating; cin >> rating;
	cout << "Enter the movie's watched times : ";  int w_t;   cin >> w_t;

	Movie one;
	one = one.add(name, rating, w_t);

	movies.push_back(one);
}
void Movies::search_for_the_movie(int n)
{
	string name;
	cout << "\nEnter the movie's name please : "; cin >> name;
	for (int i = 0; i < movies.size(); i++)
	{
		if (name == movies.at(i).get_name())
		{
			if(n==2)
			cout << "\nYou watched "<<name<<" "<< movies.at(i).get_watched() << " times \n";
			else if (n == 3)
			{
				cout << "Enter the new rating of " << name<<" : ";
				int new_quality; cin >> new_quality;
				movies.at(i).set_quality(new_quality);
			}
			else if (n == 4)
			{
				cout <<endl<< name << "'s rating is : " << movies.at(i).get_rating()<<endl;
				cout << "you watched this movie " << movies.at(i).get_watched() << endl<<endl;
			}
			else if (n == 7)
			{
				movies.at(i).add_one_to_num_watched();
				cout << "\nIncremented succesfully\n";
				cout << "Number of times you watched this movie is : " << movies.at(i).get_watched() << " times\n";
			}
		}
			
	}

}
void Movies::print_all_movies()
{
	for (int i = 0; i < movies.size(); i++)
	{
		cout << "\nMovie " << i + 1 << " : " << movies.at(i).get_name() << endl;
		cout << "movie's rating is : " << movies.at(i).get_rating() << endl;
		cout << "you watched this movie " << movies.at(i).get_watched() << endl << endl;
		cout << "**********************************************\n";
	}
}
int Movies::movies_num()
{
	return movies.size();
}