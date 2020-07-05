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
 * Standard constructor for ratings object
 * @param r_timeCode    TimeCode from TimeCode class
 * @param r_authorName  Name of sender
 * @param r_title       Title of movie
 * @param r_rating      Rating given by user
 */
Rating::Rating(TimeCode& r_timeCode, 
                string& r_authorName,
                string& r_title,
                string& r_rating) {
    this->r_timeCode = r_timeCode;
    this->r_authorName = r_authorName;
    this->r_title = r_title;
    this->r_rating = r_rating;
}

/**
 * Returns the size of the ratings database
 * @return  Size of database
 */
size_t Ratings::size () const {
    return ratingsDB.size();
}

/**
 * Destructor
 */
Ratings::~Ratings(){

}