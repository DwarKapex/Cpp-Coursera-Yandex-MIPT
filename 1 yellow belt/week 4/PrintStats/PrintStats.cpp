#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void PrintStats(vector<Person> persons) {
  cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
  
  auto female_start = persons.begin();
  auto female_end = partition(persons.begin(), persons.end(), [](const auto &d) -> bool { return d.gender == Gender::FEMALE;});
  auto male_start = female_end;
  auto male_end = persons.end();
  cout << "Median age for females = " << ComputeMedianAge(female_start, female_end) << endl;
  cout << "Median age for males = " << ComputeMedianAge(male_start, male_end) << endl;

  auto female_employed_end = partition(female_start, female_end, [](const auto &d) -> bool { return d.is_employed;});
  cout << "Median age for employed females = " << ComputeMedianAge(female_start, female_employed_end) << endl;
  cout << "Median age for unemployed females = " << ComputeMedianAge(female_employed_end, female_end) << endl;

  auto male_employed_end = partition(male_start, male_end, [](const auto &d) -> bool { return d.is_employed;});
  cout << "Median age for employed males = " << ComputeMedianAge(male_start, male_employed_end) << endl;
  cout << "Median age for unemployed males = " << ComputeMedianAge(male_employed_end, male_end) << endl;
}
