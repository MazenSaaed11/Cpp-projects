#include "Movies.h"
void display()
{
    Movies Sce_fi;
    cout << "Hello to Mazen's watched movies\n";

    while (true)
    {
        cout << "\n___________________________________________________\n";
        cout << "\n1).Add a movie\n";
        cout << "2).Display how many times I watched a certain movie\n";
        cout << "3).Edit the quality of a certain movie\n";
        cout << "4).See information about a certain movie\n";
        cout << "5).Display all movies\n";
        cout << "6).Number of movies watched\n";
        cout << "7).Increment the number of times I watched a certain movie\n";
        cout << "8).Exit\n\n";
        cout << "Enter your choise : ";
        int n;
        cin >> n;
        cout << "\n_________________________________________________________\n";
        if (n == 1)
            Sce_fi.add_movie();
        else if (n == 2)
            Sce_fi.search_for_the_movie(n);
        else if (n == 3)
            Sce_fi.search_for_the_movie(n);
        else if (n == 4)
            Sce_fi.search_for_the_movie(n);
        else if (n == 5)
            Sce_fi.print_all_movies();
        else if (n == 6)
            cout << endl << "You watched " << Sce_fi.movies_num() << "movies";
        else if (n == 7)
            Sce_fi.search_for_the_movie(n);
        else if (n == 8)
            exit(0);
        else
        {
            cout << "\nInvalid input please try again\n";
            continue;
        }
    }
}

int main()
{
    display();
    	return 0;
}