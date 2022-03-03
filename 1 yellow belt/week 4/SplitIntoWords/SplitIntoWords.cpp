#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> res;
  auto start = s.begin();
  auto end = find(start, s.end(), ' ');
  res.emplace_back(start, end);
  start = end;
  while (s.end() != start) {
    ++start;
    auto end = find(start, s.end(), ' ');
    res.emplace_back(start, end);
    start = end;
  }
  return res;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}