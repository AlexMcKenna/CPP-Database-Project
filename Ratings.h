#include "TimeCode.h"

#ifndef RATINGS_H
#define RATINGS_H

using namespace std;

class Rating {
private:
    TimeCode r_timeCode;
    string r_authorName, r_title, r_rating;

public:
    
    Rating(TimeCode& r_timeCode, 
            string& r_authorName,
            string& r_title,
            string& r_rating);
    //inline ~Ratings();
//Get methods
    inline TimeCode r_getTimeCode() const {
        return r_timeCode;
    }
    inline string r_getAuthorName() const {
        return r_authorName;
    }

    inline string r_getTitle() const {
        return r_title;
    }

    inline string r_getRating() const {
        return r_rating;
    }
    
    
    friend istream& operator>>(istream& input, Rating& r);
    friend ostream& operator<<(ostream& os, const Rating& r);
};
/**
 * Overloading input stream operator
 * @param input     Input Stream
 * @param r         Rating being used
 * @return          Input Stream
 */
inline istream& operator>>(istream& input, Rating& r) {
    //input the TimeCode function
    input >> r.r_timeCode;
    input.get();
    getline(input, r.r_authorName, '/');
    input.get();
    getline(input, r.r_title, ',');
    input.get();
    getline(input, r.r_rating, ',');

    return input;
}
/**
 * Overloading Output Stream
 * @param os        Output stream
 * @param r         Rating being used
 * @return          output stream
 */
inline ostream& operator<<(ostream& os, Rating r) {
    os << r.r_getTimeCode() << ",\"";
    os << r.r_getAuthorName() << "\",\"";
    os << r.r_getTitle() << "\",";
    os << r.r_getRating() << "\n";

    return os;
}
//Seperate class from rating, could've put in new class
class Ratings {
private:
    vector<Rating> ratingsDB;
public:
    inline Ratings();
    inline ~Ratings();
    //Dont exactly know why i put this here
    friend ostream& operator<<(ostream& os, const Rating& ratingsDB);

    size_t size() const;
};
#endif /* RATINGS_H */

