#include "airline_ticket.h"
#include "test_runner.h"
#include <iomanip>
#include <iostream>

using namespace std;

#define UPDATE_FIELD(ticket, field, values) {\
  auto it = values.find(#field); \
  if (it != values.end()) {  \
    istringstream is(it->second); \
    is >> ticket.field; \
  }}


std::ostream& operator<< (std::ostream& out, const Date& date){
    out << std::setw(4) << std::setfill('0') << date.year << '-'
    << std::setw(2) << std::setfill('0') << date.month << '-'
    << std::setw(2) << std::setfill('0') << date.day;
    
    return out;
}

bool operator== (const Date &lhs, const Date &rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day) ==
         std::tie(rhs.year, rhs.month, rhs.day);
}

std::ostream& operator<< (std::ostream &out, const Time &time){
    out << std::setw(2) << std::setfill('0') << time.hours << ':'
    << std::setw(2) << std::setfill('0') << time.minutes;
    
    return out;
}

bool operator== (const Time &lhs, const Time &rhs) {
  return lhs.hours*60 + lhs.minutes == rhs.hours*60 + rhs.minutes;
}

std::istream& operator>> (std::istream &is, Date &data) {
  is >> data.year; is.ignore(1);
  is >> data.month; is.ignore(1);
  is >> data.day;
  return is;
}

std::istream& operator>> (std::istream &is, Time &data) {
  is >> data.hours; is.ignore(1);
  is  >> data.minutes;
  return is;
}


void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}