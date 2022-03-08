#include "airline_ticket.h"
#include "test_runner.h"
#include <tuple>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

#define SORT_BY(field)  \
  [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
    return lhs.field < rhs.field;}


bool operator< (const Date &lhs, const Date &rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day) <
         std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator== (const Date &lhs, const Date &rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day) ==
         std::tie(rhs.year, rhs.month, rhs.day);
}

std::ostream& operator << (std::ostream& out, const Date& date){
    out << std::setw(4) << std::setfill('0') << date.year << '-'
    << std::setw(2) << std::setfill('0') << date.month << '-'
    << std::setw(2) << std::setfill('0') << date.day;
    
    return out;
}



bool operator< (const Time &lhs, const Time &rhs) {
  return lhs.hours*60 + lhs.minutes < rhs.hours*60 + rhs.minutes;
}

bool operator== (const Time &lhs, const Time &rhs) {
  return lhs.hours*60 + lhs.minutes == rhs.hours*60 + rhs.minutes;
}

std::ostream& operator << (std::ostream& out, const Time& time){
    out << std::setw(2) << std::setfill('0') << time.hours << ':'
    << std::setw(2) << std::setfill('0') << time.minutes;
    
    return out;
}


void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}