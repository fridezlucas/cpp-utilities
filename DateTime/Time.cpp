/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 17.06.2019.
 */

#include "Time.h"

/**
 * Copy constructor
 * @param time {Time} to recopy
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time::Time(const Time &time) {
    hour = time.hour;
    minute = time.minute;
    second = time.second;
}

/**
 * Constructor
 * @param hour {int} hour
 * @param minute {int} minute
 * @param second {int} second
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

/**
 * Write Time on console
 * @param s {ostream}
 * @param time {Time}
 * @return {ostream}
 */
std::ostream &operator<<(std::ostream &s, const Time &time) {
    return s << std::setfill('0')
             << std::setw(2) << time.hour << ":"
             << std::setw(2) << time.minute << ":"
             << std::setw(2) << time.second;
}

/**
 * Add Time to current
 * @param time {Time} to add
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time Time::operator+(const Time &time) const {
    Time t(hour + time.hour, minute + time.minute, second + time.second);
    t.reorganizeTimeAddition();

    return t;
}

/**
 * Substract Time to current
 * @param time {Time} Time to substract
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time Time::operator-(const Time &time) const {
    Time t(hour - time.hour, minute - time.minute, second - time.second);
    t.reorganizeTimeSubstraction();

    return t;
}

/**
 * Reorganize Time (addition)
 * 0 <= H <= 24
 * 0 <= M <= 60
 * 0 <= S <= 60
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Time::reorganizeTimeAddition() {
    minute += second / 60;
    hour += minute / 60;

    hour %= 24;
    minute %= 60;
    second %= 60;
}

/**
 * Reorganize Time (substraction)
 * * 0 <= H <= 24
 * 0 <= M <= 60
 * 0 <= S <= 60
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Time::reorganizeTimeSubstraction() {
    if (second < 0) {
        minute -= static_cast<int>(ceil(abs(second) / 60.));
        second = second + 60;
    }

    if (minute < 0) {
        hour -= ceil(abs(minute) / 60.);
        minute = minute + 60;
    }

    hour = hour < 0 ? 24 + hour : hour;

}

/**
 * Multiply Time
 * @param multiple {int} coefficient
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time Time::operator*(const int &multiple) const {
    Time t(hour * multiple, minute * multiple, second * multiple);
    t.reorganizeTimeAddition();

    return t;
}

/**
 * Addition Time
 * @param time {Time} to add
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time &Time::operator+=(const Time &time) {
    hour += time.hour;
    minute += time.minute;
    second += time.second;

    reorganizeTimeAddition();

    return *this;
}

/**
 * Addition second
 * @param second {int} second to add
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time &Time::operator+=(const int &second) {
    this->second += second;
    reorganizeTimeAddition();

    return *this;
}

/**
 * Substract Time
 * @param time {Time} to substract
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time &Time::operator-=(const Time &time) {
    hour -= time.hour;
    minute -= time.minute;
    second -= time.second;

    reorganizeTimeSubstraction();

    return *this;
}

/**
 * Substract second
 * @param second {int} second to substract
 * @return {Time} new Time
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Time &Time::operator-=(const int &second) {
    this->second -= second;
    reorganizeTimeSubstraction();

    return *this;
}
