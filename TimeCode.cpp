#include "TimeCode.h"
/**
 * Standard constructor for TimeCode
 * @param hours     Hour rating made
 * @param minutes   Minute rating made
 * @param seconds   Second rating made
 * @param day       Day rating made
 * @param month     Month rating made
 * @param year      Year rating made
 */
TimeCode::TimeCode(int& hours,int& minutes,int& seconds, 
                   int& day, int& month, int& year){
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->day = day;
    this->month = month;
    this->year = year;
}
/**
 * Other TimeCode for comparables
 * @param other     Other TimeCode
 */
TimeCode::TimeCode(const TimeCode& other){
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}
/**
 * Input stream operator for time of rating
 * @param input     input stream
 * @param time      Time of rating
 * @return          Stream of input implemented
 */
inline istream& operator >> (istream& input, TimeCode& time) {
    input.get();            //Characters for the center of inputs
    getline(input, time.day, "/");
    input.get();
    getline(input, time.month, "/");
    input.get();
    getline(input, time.year, "T");
    input.get();
    getline(input, time.hours, ":");
    input.get();
    getline(input, time.minutes, ":");
    input.get();
    getline(input, time.seconds, "Z");
    
    return input;
}
/**
 *  Output stream for time setting
 * @param os    Output stream
 * @param time  Parameters of 'Time'
 * @return      Output stream of data
 */
ostream& operator<<(ostream& os, const TimeCode& time) {
    os << setfill('0') << setw(2) << time.day << "/";
    os << setfill('0') << setw(2) << time.month << "/";
    os << time.year << "T";
    os << setfill('0') << setw(2) << time.hours << ":";
    os << setfill('0') << setw(2) << time.minutes << ":";
    os << setfill('0') << setw(2) << time.seconds << "Z";
    
    return os;
}
/**
 * Operator used to check TimeCode is equal
 * @param a     Set of TimeCode values
 * @param b     Set of TimeCode values
 * @return      True if equal
 */
inline bool operator ==(const TimeCode& a, TimeCode& b){
    return  a.getDay() == b.getDay() &&
            a.getMonth() == b.getMonth() &&
            a.getYear() == b.getYear() &&
            a.getHours() == b.getHours() &&
            a.getMinutes() == b.getMinutes() &&
            a.getSeconds() == b.getSeconds();
                        
}
/**
 * Conversion of TimeCode to int, uses (Static_Cast) 
 */
void TimeCode::convertToInt() const{
    time = 0;
    //normal
    time += static_cast<int>(seconds);
    //60 seconds in minute
    time += static_cast<int>(minutes) * 60;
    //60 minutes in an hour
    time += static_cast<int>(hours) * 60 * 60;
    //24 hours in day
    time += static_cast<int>(day) * 60 * 60 * 24;
    //31 days in month
    time += static_cast<int>(month) * 60 * 60 * 24 * 31;
    //365 days in year
    time += static_cast<int>(year) * 60 * 60 * 24 * 365;
}

/**
 * Sample Destructor
 */
TimeCode::~TimeCode(){
    
}
