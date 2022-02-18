# Desctiption

You are given the phone_number.h header file containing the PhoneNumber class declaration. At the same time, the comments describe the behavior that is expected from the implementation of this class.

```
phone_number.h
```

```c++
#pragma once

#include <string>

using namespace std;

class PhoneNumber {
public:
  /* Accepts a string in the format +XXX-YYY-ZZZZZZ
    The part from '+' to the first '-' is the country code.
    The part between the first and second characters '-' is the area code
    Everything that comes after the second character '-' is a local number.
    The country code, city code and local number should not be empty.
    If the string does not match this format, you need to throw an invalid_argument exception. There is no need to check that the number contains only digits.

    Examples:
    * +7-495-111-22-33
    * +7-495-1112233
    * +323-22-460002
    * +1-2-coursera-cpp
    * 1-2-333 - incorrect number - does not start with '+'
    * +7-1233 - incorrect number - there is only the country and city code
  */
  explicit PhoneNumber(const string &international_number);

  string GetCountryCode() const;
  string GetCityCode() const;
  string GetLocalNumber() const;
  string GetInternationalNumber() const;

private:
  string country_code_;
  string city_code_;
  string local_number_;
};
```

You need to send a cpp file containing the definitions of these functions. 

## How will your code be tested
The automated testing system will add your cpp file to the project containing another cpp file with unit tests for all three functions, as well as the sum_reverse_sort.h file. Then it will assemble this project and, if compilation is successful, run the resulting executable file. If it completes successfully (i.e. unit tests will not find errors in your implementation), then your parcel will be counted.