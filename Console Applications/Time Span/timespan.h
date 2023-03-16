//
// Created by Yun-Ting Chen on 1/26/2020.
//
// This TimeSpan class is used to define the functions of the time system
// which represents a duration in hours, minutes and seconds.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
    // overload the << for output
    friend ostream &operator<<(ostream &Out, const TimeSpan &Ts);
public:
    // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
    explicit TimeSpan(double Hour = 0, double Minute = 0, double Second = 0);
    // add
    TimeSpan operator+(const TimeSpan &Ts) const;
    // subtract
    TimeSpan operator-(const TimeSpan &Ts) const;
    // check equality
    bool operator==(const TimeSpan &Ts) const;
    // check if not equal
    bool operator!=(const TimeSpan &Ts) const;
    // multiply timespan by a number
    TimeSpan operator*(int Number);
    // add
    TimeSpan& operator+=(const TimeSpan &Ts);
    // subtract
    TimeSpan& operator-=(const TimeSpan &Ts);
    // check if greater
    bool operator>(const TimeSpan &Ts)const ;
    // check if less
    bool operator<(const TimeSpan &Ts)const ;
    // check if greater or equal to
    bool operator>=(const TimeSpan &Ts)const ;
    // check if less or equal to
    bool operator<=(const TimeSpan &Ts)const ;
    // return hour
    int getHour() const ;
    // return minute
    int getMinute() const ;
    // return second
    int getSecond() const ;
    // check if total time is negative
    bool getIsNegative() const ;
    // return total time in seconds
    int getTotalTime() const ;
private:
    // private variables
    double hour, minute, second;
    // check if time is negative
    bool isNegative;
    // this function convert time in standard time format for hour, minute, second
    void convertTime();
    // total time in seconds
    double totalTime;
};

#endif //ASS2_TIMESPAN_H
