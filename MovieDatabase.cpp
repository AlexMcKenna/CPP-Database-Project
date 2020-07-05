#include "MovieDatabase.h"
#include "Movie.h"
#include "Ratings.h"
#include "TimeCode.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
/**
 * Default constructor
 */
MovieDatabase::MovieDatabase(){
    
}

/**
 *  Output operator for movie database
 * @param os        Output stream
 * @param movieDB   Vector of movies
 * @return          Output stream
 */
ostream& operator << (ostream& os, MovieDatabase& movieDB) {
    cout << "Movies = ";
    for(size_t i = 0; i < movieDB.size(); ++i)
        cout << movieDB << endl;
    cout << endl;
    
    return os;
}
/**
 * Method to get the size of a vector
 * @return  size of vector
 */
size_t MovieDatabase::size () const {
    return movieDB.size();
}

MovieDatabase::~MovieDatabase(){

}

/**
 * finding specific elements
 * use find_if to find specific element 
 * @return result   found result  
 */
/*
void findNoire(){
//use find_if to find specific element 
Movie result = find_if(begin(movieDB), end(movieDB), [](Movie n) {
    //gets line of file with "noire" present
    
    return getline("Noire");
})
//gets pointer of result to print
cout << *result;
}
*/

