/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 17.06.2019.
 */

#ifndef CPP_UTILITIES_TIME_H
#define CPP_UTILITIES_TIME_H

#include <ostream>
#include <iomanip>
#include <cmath>

/**
 * Time class
 * Composed composed of the hour, minute and second
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Time {
private:
    int hour;
    int minute;
    int second;

    void reorganizeTimeAddition();

    void reorganizeTimeSubstraction();

public:

    Time(const Time &time);

    Time(int hour = 0, int minute = 0, int second = 0);

    Time operator+(const Time &time) const;

    Time operator-(const Time &time) const;

    Time operator*(const int &multiple) const;

    Time &operator+=(const Time &time);

    Time &operator+=(const int &second);

    Time &operator-=(const Time &time);

    Time &operator-=(const int &second);

    friend std::ostream &operator<<(std::ostream &s, const Time &time);
};


#endif //CPP_UTILITIES_TIME_H
