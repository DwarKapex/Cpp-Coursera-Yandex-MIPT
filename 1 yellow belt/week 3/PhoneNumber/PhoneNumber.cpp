#include "phone_number.h"
#include <exception>
#include <sstream>
#include <string>
using namespace std;


  PhoneNumber::PhoneNumber(const string &international_number) {
    size_t n = international_number.size();
    if (0 == n) {
        throw invalid_argument("");
    }
    bool ok = (international_number.front() == '+');
    stringstream s(international_number);
    s.ignore(1);
    getline(s, country_code_, '-');
    getline(s, city_code_, '-');
    getline(s, local_number_);
    ok &= (!country_code_.empty() && !city_code_.empty() && !local_number_.empty());

    if (!ok) {
        throw invalid_argument("");
    }
  }

  string PhoneNumber::GetCountryCode() const {
      return country_code_;
  }
  string PhoneNumber::GetCityCode() const {
      return city_code_;
  }
  string PhoneNumber::GetLocalNumber() const {
      return local_number_;
  }
  string PhoneNumber::GetInternationalNumber() const {
       return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
  }