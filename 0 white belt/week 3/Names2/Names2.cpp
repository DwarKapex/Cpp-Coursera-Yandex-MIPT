#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year, bool full_history) {
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
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year, bool full_history=false) {
    const string first_name = FindNameByYear(first_names, year, full_history);
    const string last_name = FindNameByYear(last_names, year, full_history);
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    } else {
      return first_name + " " + last_name;
    }
  }
  string GetFullNameWithHistory(int year) {
      return GetFullName(year, true);
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
    
  return 0;
}