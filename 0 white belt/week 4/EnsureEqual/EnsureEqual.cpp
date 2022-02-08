#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void EnsureEqual(const string& left, const string& right){
    if (left != right){
        throw runtime_error(s + " != " + t);
    }
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}