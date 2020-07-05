/* 
 * File:   MovieDatabase.h
 * Author: Alex
 *
 * Created on March 20, 2017, 3:30 PM
 */

#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H

#include <vector>
#include "Movie.h"

using namespace std;
class MovieDatabase 
{
private:
    vector<Movie> movieDB;
public:
    inline MovieDatabase();
    inline ~MovieDatabase();
    
    ostream& operator << (MovieDatabase& movieDB);

    size_t size() const;

    //MovieDatabase::movieDB();
};
#endif /* MOVIEDATABASE_H */

