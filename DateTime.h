//
// Created by Z on 3/26/2021.
//

#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <ctime>


class DateTime {

private:

    tm* local;


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
        return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " + std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    }

    ~DateTime() {}

};


//std::string DateTime::getTransactionDT() {
//    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " + std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);
//
//}



#endif //DATETIME_H
