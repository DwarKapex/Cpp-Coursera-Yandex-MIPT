#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    history[year].first_name = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    history[year].last_name = last_name;
  }
  string GetFullName(int year) {
    string first_name, last_name;
    for (const auto& item: history) {
      if (item.first > year) {
        break;
      } else {
        first_name = item.second.first_name != "" ? item.second.first_name : first_name;
        last_name = item.second.last_name != "" ? item.second.last_name : last_name;
      }
    }
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if (!first_name.empty() && last_name.empty()) {
      return first_name + " with unknown last name";
    } else if (first_name.empty() && !last_name.empty()) {
      return last_name + " with unknown first name";
    } else {
      return first_name + " " + last_name;
    }
  }
private:
  struct Details {
    string first_name = "";
    string last_name = "";
  };
  map<int, Details> history;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}