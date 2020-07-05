/* 
 * File:   TimeCode.h
 * Author: Alex
 *
 * Created on March 20, 2017, 3:30 PM
 */

#ifndef TIMECODE_H
#define TIMECODE_H

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class TimeCode {
private:
    int hours, minutes, seconds;
    int day, month, year;

public:
    /**
     * Default constructor
     */
    TimeCode();
    
    /**
     * Full constructor for TimeCode
     * Standard constructor for TimeCode
     * @param hours     Hour rating made
     * @param minutes   Minute rating made
     * @param seconds   Second rating made
     * @param day       Day rating made
     * @param month     Month rating made
     * @param year      Year rating made
     */
    TimeCode(int& hours,int& minutes,int& seconds, 
             int& day, int& month, int& year);
    
    /**
     * Default destructor
     */
    ~TimeCode();

    friend istream& operator>>(istream& input, TimeCode& time);
    friend ostream& operator<<(ostream& os, const TimeCode& time);

    void convertToInt() const;

    bool operator==(const TimeCode& a);

    //getters
    inline int getDay() const {
        return day;
    }

    inline int getMonth() const {
        return month;
    }

    inline int getYear() const {
        return year;
    }

    inline int getHours() const {
        return hours;
    }

    inline int getMinutes() const {
        return minutes;
    }

    inline int getSeconds() const {
        return seconds;
    }
};

//inline istream& operator>>(istream& input, TimeCode& time);
//
//inline ostream& operator<<(ostream& os, const TimeCode& time);

inline bool operator==(const TimeCode& a, TimeCode& b);


#endif /* TIMECODE_H */

