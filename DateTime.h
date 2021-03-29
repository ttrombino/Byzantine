//
// Created by Z on 3/26/2021.
//

#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <ctime>
#include <stdio.h>


class DateTime {

private:

    tm* local;
    std::string padDT(unsigned t) {
        std::string ret = "";
        if (t < 10) {
            ret+= "0" + std::to_string(t);
        }
        else {
            ret = std::to_string(t);
        }
        return ret;
    }


public:
    time_t currentTime;
    unsigned year;
    unsigned month;
    unsigned day;
    unsigned hour;
    unsigned min;
    unsigned sec;


    DateTime() {
        currentTime = time(0);
        local = localtime(&currentTime);

        year = 1900 + local->tm_year;
        month = 1 + local->tm_mon;
        day = local->tm_mday;
        hour = local->tm_hour;
        min = local->tm_min;
        sec = local->tm_sec;
    }

    std::string getDT() {
        std::string fMonth = padDT(month);
        std::string fDay = padDT(day);
        std::string fHour = padDT(hour);
        std::string fMin = padDT(min);
        std::string fSec = padDT(sec);

        return std::to_string(year) + "-" + fMonth + "-" + fDay + " " + fHour + ":" + fMin + ":" + fSec;

    }

    ~DateTime() {}

};


//std::string DateTime::getTransactionDT() {
//    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " + std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);
//
//}



#endif //DATETIME_H
