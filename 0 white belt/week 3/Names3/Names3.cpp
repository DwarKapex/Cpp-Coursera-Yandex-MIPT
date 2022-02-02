#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year, bool full_history) {
  if (year < names.begin()->first) return "";
  string name, prev_name;
  vector<string> history;
  
  for (const auto& item : names) {
    if (item.first <= year) {
        if (!item.second.empty() && item.second != prev_name)
            history.push_back(item.second);
            prev_name = item.second;
    } else {
      break;
    }
  }
  int n = history.size();
  if (!history.empty()){
      name = history[n-1];
      if (full_history && n >1){
          name += " (";
          for (int idx = n-2; idx >0; --idx)
                name += history[idx] +", ";
          name += (history[0] + ")");
       }
  }
  return name;
}

class Person {
public:
  Person(const string first_name, const string last_name, int year) {
    first_names[year] = first_name;
    last_names[year] = last_name;
  }
  void ChangeFirstName(int year, const string& first_name) {
    if (year >= first_names.begin()->first) {
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= last_names.begin()->first) {
      last_names[year] = last_name;
    }
  }
  string GetFullName(int year, bool full_history=false) const {
    const string first_name = FindNameByYear(first_names, year, full_history);
    const string last_name = FindNameByYear(last_names, year, full_history);
    if (first_name.empty() && last_name.empty()) {
      return "No person";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    } else {
      return first_name + " " + last_name;
    }
  }
  string GetFullNameWithHistory(int year) const {
      return GetFullName(year, true);
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
  const Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  // person.ChangeFirstName(1965, "Appolinaria");
  // person.ChangeLastName(1967, "Ivanova");
  // for (int year : {1965, 1967}) {
  //   cout << person.GetFullNameWithHistory(year) << endl;
  // }

  return 0;
}