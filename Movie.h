/* 
 * File:   Movie.h
 * Author: Alex
 *
 * Created on March 20, 2017, 3:30 PM
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;

class Movie final 
{
private:
    //Private variables
    string name, classification, genre;
    int year, runtime, noOfRatings;
    double rating;

public:
    // Default constructor
    inline Movie() {
    }
    //Default destructor
    inline ~Movie() {
    }
    /**
     * Constructor with params for movie
     * @param name              Movie name
     * @param year              Release year
     * @param classification    Allowable viewing audience
     * @param genre             Genre of movie
     * @param runtime           Duration of movie
     * @param rating            Movie rating
     * @param noOfRatings       No of ratings recieved
     */
    Movie(const string& name,
            int& year,
            const string& classification,
            const string& genre,
            int& runtime,
            double& rating,
            int& noOfRatings);
    
    Movie(const Movie& other);
    
    // Get Methods
    inline string& getmovieName(){
        return name;
    }

    inline int& getYear(){
        return year;
    }

    inline string& getClassification(){
        return classification;
    }

    inline string& getGenre() {
        return genre;
    }

    inline int& getRuntime(){
        return runtime;
    }

    inline double& getRating(){
        return rating;
    }

    inline int& getNoOfRatings(){
        return noOfRatings;
    }
    // Set Methods
    inline void setmovieName(const string& name) {
        this->name = name;
    }
    inline void setYear(int& year) {
        this->year = year;
    }
    inline void setClassification(const string& classification) {
        this->classification = classification;
    }
    void setGenre(string& genre){
        this->genre = genre;
    }
    void setRuntime(int& runtime){
        this->runtime = runtime;
    }
    void setRating(double& rating){
        this->rating = rating;
    }
    void setNoOfRatings(int& noOfRatings) {
        this->noOfRatings = noOfRatings;
    }
    /**
     * Input stream operator, Friend so can be used in multiple classes
     * @param m     Movie input     
     * @return      Input stream
     */
    friend istream& operator >> (istream &input, Movie &m);
    /**
     * Output stream operator
     * @param m     Movie output
     * @return      Output stream
     */
    friend ostream& operator << (ostream &os, const Movie &m);
    
    /**
     * Used to check if equal
     * @param a     Movie being used
     * @return 
     */
    bool operator==(const Movie& a);
    
    //Bool sorts - Description in Movie.cpp
    bool ageSort(const Movie& a, const Movie& b);
    bool titleSort(const Movie& a, const Movie& b);
    bool ratingSort(const Movie& a, const Movie& b);
    
};
//    ostream& operator << (ostream& os, const Movie& m);
    
#endif /* MOVIE_H */

