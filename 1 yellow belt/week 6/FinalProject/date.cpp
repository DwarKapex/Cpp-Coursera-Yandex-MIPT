//
//  date.cpp
//  final_project
//
//  Created by Vladislav Kozlov on 6/27/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//


    // конструктор выбрасывает исключение, если его аргументы некорректны
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "date.h"

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const { return year; }

int Date::GetMonth() const { return month; }

int Date::GetDay() const { return day; }

std::ostream& operator << (std::ostream& stream, const Date& d) {
    stream << std::setw(4) << std::setfill('0') << d.GetYear() <<
    "-" << std::setw(2) << std::setfill('0') << d.GetMonth() <<
    "-" << std::setw(2) << std::setfill('0') << d.GetDay();
    return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
            std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return !( lhs > rhs );
}

bool operator > (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
    std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator >= (const Date& lhs, const Date& rhs) {
    return ! ( lhs < rhs );
}

bool operator == (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
    std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator != (const Date& lhs, const Date& rhs) {
    return !( lhs == rhs );
}

Date ParseDate(const std::string& date) {
    std::istringstream date_stream(date);
    bool ok = true;
    
    int year=0;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int month=0;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int day=0;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();
    
    if (!ok) {
        throw std::logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

Date ParseDate(std::istringstream& is){
    std::string date;
    is >> date;
    return ParseDate(date);
}

Date ParseDate(std::istream& is){
    std::string date;
    is >> date;
    return ParseDate(date);
}

