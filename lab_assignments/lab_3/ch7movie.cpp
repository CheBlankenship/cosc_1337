//Che Blankenship
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "movieData.h"

// prototype
void displayMovieInfo_v4(MovieData);
void displayMovieInfo_v6(MovieData);

int main()
{
    // Movie 1
    MovieData movie1("Good Will Hunting", "Lawrence Bender", 1997, 126);
    // Movie 2
    MovieData movie2("God Father", "Francis Ford Coppola", 1972, 113, 120000, 2300000);
    // Movie 3
    MovieData movie3("Taxi Driver", "Martin Scorsese", 1976, 120, 1000000, 1900000);

    // Print the movie informaton.
    // Display movie 1
    displayMovieInfo_v4(movie1);
    // Display movie 2
    displayMovieInfo_v6(movie2);
    // Display movie 3
    displayMovieInfo_v6(movie3);

	return 0;
}

// Display 4 information of the movie.
void displayMovieInfo_v4(MovieData movie)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "------------------------------------------" << '\n';
    cout << "------------ Movie Informaton ------------" << '\n';
    cout << "------------------------------------------" << '\n';
    cout << "Title      : " << movie.getTitle() << '\n';
    cout << "Director   : " << movie.getDirector() << '\n';
    cout << "Year       : " << movie.getYear() << '\n';
    cout << "Time       : " << movie.getTime() << "\n\n";
}

// Display 6 information of the movie.
void displayMovieInfo_v6(MovieData movie)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "------------------------------------------" << '\n';
    cout << "------------ Movie Informaton ------------" << '\n';
    cout << "------------------------------------------" << '\n';
    cout << "Title      : " << movie.getTitle() << '\n';
    cout << "Director   : " << movie.getDirector() << '\n';
    cout << "Year       : " << movie.getYear() << '\n';
    cout << "Time       : " << movie.getTime() << '\n';
    cout << "Cost       : $ " << movie.getProdCost() << '\n';
    cout << "Revenues   : $ " << movie.getRevenues() << "\n\n";
}
