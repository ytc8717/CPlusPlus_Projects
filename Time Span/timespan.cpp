//
// Created by Yun-Ting Chen on 1/26/2020.
//
// Implementation for the TimeSpan class
// with operators overloads
//

#include "timespan.h"

// overload the << for the output
// display the time in hh:mm:ss format
ostream &operator<<(ostream &Out, const TimeSpan &Ts) {
    if(Ts.getIsNegative()) {
        if (Ts.getSecond() * -1 < 10 && Ts.getMinute() * -1 < 10) {
            Out << "-" << Ts.getHour() * -1 << ":0" << Ts.getMinute() * -1 << ":0" << Ts.getSecond() * -1;
        } else if (Ts.getMinute() * -1 < 10) {
            Out << "-" << Ts.getHour() * -1 << ":0" << Ts.getMinute() * -1 << ":" << Ts.getSecond() * -1;
        } else if (Ts.getSecond() * -1 < 10) {
            Out << "-" << Ts.getHour() * -1 << ":" << Ts.getMinute() * -1 << ":0" << Ts.getSecond() * -1;
        }
        else {
            Out << "-" << Ts.getHour() * -1 << ":" << Ts.getMinute() * -1 << ":" << Ts.getSecond() * -1;
        }
    }
    else if(!Ts.isNegative)
    {
        if(Ts.getSecond() < 10 && Ts.getMinute() < 10) {
            Out << Ts.getHour() << ":0" << Ts.getMinute() << ":0" << Ts.getSecond();
        }
        else if(Ts.getMinute() < 10) {
            Out << Ts.getHour() << ":0" << Ts.getMinute() << ":" << Ts.getSecond();
        }
        else if(Ts.getSecond() < 10) {
            Out << Ts.getHour() << ":" << Ts.getMinute() << ":0" << Ts.getSecond();
        }
        else {
            Out << Ts.getHour() << ":" << Ts.getMinute() << ":" << Ts.getSecond();
        }
    }
    return Out;
}

// overload the add + operator
TimeSpan TimeSpan::operator+(const TimeSpan &Ts) const {
    TimeSpan TsSum = TimeSpan(this->getHour() + Ts.getHour(), this->getMinute() + Ts.getMinute()
            , this->getSecond() + Ts.getSecond());
    return TsSum;
}

// overload the subtract - operator
TimeSpan TimeSpan::operator-(const TimeSpan &Ts) const {
    TimeSpan TsSub = TimeSpan(this->getHour() - Ts.getHour(), this->getMinute() - Ts.getMinute()
            , this->getSecond() - Ts.getSecond());
    return TsSub;
}

// overload the multiplication * operator
TimeSpan TimeSpan::operator*(int Number) {
    TimeSpan TsLarge = TimeSpan(this->getHour() * Number, this->getMinute() * Number
            , this->getSecond() * Number);
    return TsLarge;
}

// overload the equal operator
// check if equals
bool TimeSpan::operator==(const TimeSpan &Ts) const {
    bool Result;
    Result = this->getHour() == Ts.getHour() && this->getMinute() == Ts.getMinute() &&
             this->getSecond() == Ts.getSecond();
    return Result;
}

// overload the not equal operator
// check if not equal
bool TimeSpan::operator!=(const TimeSpan &Ts) const {
    bool Result;
    Result = this->getHour() != Ts.getHour() || this->getMinute() != Ts.getMinute() ||
             this->getSecond() != Ts.getSecond();
    return Result;
}

// constructor with default values
TimeSpan::TimeSpan(double Hour, double Minute, double Second) {
    hour = Hour;
    minute = Minute;
    second = Second;
    isNegative = false;
    totalTime = 0;
    convertTime();
}

// this function convert time in standard time format for hour, minute, second
void TimeSpan::convertTime() {
    double TotalSeconds = 0;
    TotalSeconds = (hour * 3600) + (minute * 60) + second;
    totalTime = TotalSeconds;
    isNegative = TotalSeconds < 0;
    if(isNegative) {
        TotalSeconds *= -1;
    }
    TotalSeconds = static_cast<int>(TotalSeconds);
    hour = TotalSeconds / 3600;
    TotalSeconds = static_cast<int>(TotalSeconds) % 3600;
    minute = TotalSeconds / 60;
    second = static_cast<int>(TotalSeconds) % 60;
}

// return hour
int TimeSpan::getHour() const {
    return isNegative ? static_cast<int>(hour * -1)  : static_cast<int>(hour);
}

// return minute
int TimeSpan::getMinute() const {
    return isNegative ? static_cast<int>(minute * -1) : static_cast<int>(minute);
}

// return second
int TimeSpan::getSecond() const {
    return isNegative ? static_cast<int>(second * -1) : static_cast<int>(second) ;
}

// return if time is negative
bool TimeSpan::getIsNegative() const {
    return isNegative;
}

// overload add +=
TimeSpan &TimeSpan::operator+=(const TimeSpan &Ts) {
    hour += Ts.getHour();
    minute += Ts.getMinute();
    second += Ts.getSecond();
    return *this;
}

// overload subtract -=
TimeSpan &TimeSpan::operator-=(const TimeSpan &Ts) {
    hour -= Ts.getHour();
    minute -= Ts.getMinute();
    second -= Ts.getSecond();
    return *this;
}

// overload >
// check if greater
bool TimeSpan::operator>(const TimeSpan &Ts) const {
    bool Result;
    Result = this->getTotalTime() > Ts.getTotalTime();
    return Result;
}

// return total time in second
int TimeSpan::getTotalTime() const {
    return static_cast<int>(totalTime);
}

// overload <
// check if less
bool TimeSpan::operator<(const TimeSpan &Ts) const {
    bool Result;
    Result = this->getTotalTime() < Ts.getTotalTime();
    return Result;
}

// overload <=
// check if less or equal to
bool TimeSpan::operator<=(const TimeSpan &Ts) const {
    bool Result;
    if(this->getTotalTime() < Ts.getTotalTime()) {
        Result = true;
    }
    else {
        Result = this->getTotalTime() == Ts.getTotalTime();
    }
    return Result;
}

// overload >=
// check if greater or equal to
bool TimeSpan::operator>=(const TimeSpan &Ts) const {
    bool Result;
    if(this->getTotalTime() > Ts.getTotalTime()) {
        Result = true;
    }
    else {
        Result = this->getTotalTime() == Ts.getTotalTime();
    }
    return Result;
}

