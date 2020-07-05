#include "MovieDatabase.h"
#include "Movie.h"
#include "TimeCode.h"
#include "Ratings.h"

#include <cstdlib>

using namespace std;

int printMovies();
int printRatings();

int main() {
//    ifstream file;
//    
//    MovieDatabase m;
//    Ratings ratingsDB;
//    
//    file >> m;
//    file >> ratingsDB;
    printMovies();
    printRatings();
    //delete(*m);
    return 0;
}
//Pretty much last resort stuff
//prints movies
int printMovies() {
    ifstream file("movies.txt");
    string line;
    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            cout << line << endl;
        }
        file.close();
    } else
        cerr << "Error: unable to open file" << endl;
    return 0;
}
//prints ratings
int printRatings() {
    ifstream file("ratings.txt");
    string line;
    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            cout << line << endl;
        }
        file.close();
    } else
        cerr << "Error: unable to open file" << endl;
    return 0;
}