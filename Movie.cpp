#include "MovieDatabase.h"
#include "Movie.h"
#include "Ratings.h"
#include "TimeCode.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
/**
 * Sample Constructor for Movie
 * @param name              Name of movie
 * @param year              Year of release
 * @param classification    Viewing age
 * @param genre             Type of movie
 * @param runtime           How long the movie runs
 * @param rating            Rating given by viewers
 * @param noOfRatings       Number of ratings implemented by viewers
 */
Movie::Movie(const string& name, int& year,
        const string& classification,
        const string& genre, int& runtime,
        double& rating, int& noOfRatings) {
    this->name = name;
    this->year = year;
    this->classification = classification;
    this->genre = genre;
    this->runtime = runtime;
    this->rating = rating;
    this->noOfRatings = noOfRatings;
}
/**
 * Constructor for 'Other' Movie used for comparables
 * @param other     2nd set of variables for comparing
 */
Movie::Movie(const Movie& other) {
    this->name = other.name;
    this->year = other.year;
    this->classification = other.classification;
    this->genre = other.genre;
    this->runtime = other.runtime;
    this->rating = other.rating;
    this->noOfRatings = other.noOfRatings;

}
/**
 * O(ut)stream operator for Movie object
 * @param os    Output stream
 * @param m     Movie being used
 * @return      Output stream format
 */
ostream& operator << (ostream &os, const Movie &m) {
    os << "\"" << m.name << "\",";
    os << m.year << ",\"";
    os << m.classification << "\",\"";
    os << m.genre << "\",";
    os << m.runtime << ",";
    os << m.rating << ",";
    os << m.noOfRatings << endl;
    
    return os;
}
/**
 * Input stream for Movie object
 * @param input Input stream of data from text file
 * @param m     Movie being used
 * @return      Input stream going in
 */
istream& operator >> (istream &input, Movie &m) {
    input.get();
    getline(input, m.name, '"');
    input.get();
    input >> m.year;
    input.get();
    getline(input, m.classification, ',');
    input.get();
    getline(input, m.genre, '"');
    input.get();
    input >> m.runtime;
    input.get();
    input >> m.rating;
    input.get();
    input >> m.noOfRatings;
    //cout << "test test test test test test test test test test test test";
    //cout << m.getClassification() << endl;
    return input;
}

/**
 * Comparing Movies to get equal variance
 * @param a     Movie 1 being used
 * @param other Movie 2 being used
 * @return      True if equal
 */
bool operator==(Movie& a, Movie& other){
    return a.getmovieName() == other.getmovieName();
}
/**
 * Checks if sorted by Age of release
 * @param a     Movie 1 being used
 * @param other     Movie 2 being used
 * @return      True if sorted
 */
bool ageSort(Movie& a,Movie& other){
    return a.getYear() < other.getYear();
}
/**
 * Checks if Sorted by Title
 * @param a     Movie 1 being used
 * @param other     Movie 2 being used
 * @return      True if sorted
 */
bool titleSort(Movie& a,Movie& other){
    return a.getmovieName().length() > other.getmovieName().length();
}
/**
 * Checks if sorted by rating
 * @param a     Movie 1 being used
 * @param other Movie 2 being used
 * @return      True if sorted
 */
bool ratingSort(Movie& a,Movie& other){
    return a.getRating() > other.getRating();
}
