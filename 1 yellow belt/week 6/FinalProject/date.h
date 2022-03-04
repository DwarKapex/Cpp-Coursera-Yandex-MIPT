//
//  date.h
//  final_project
//
//  Created by Vladislav Kozlov on 6/27/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//

#ifndef _DATE_H
#define _DATE_H
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class Date {
public:
    Date(int , int , int );
    
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    
    friend std::ostream& operator<<(std::ostream& , const Date& );
    friend std::ostream& operator>>(std::istream& , const Date& );
    
    
private:
    int year, month, day;
};

Date ParseDate(const std::string& );
Date ParseDate(std::istringstream& );
Date ParseDate(std::istream& );


bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);



#endif
