#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream in("input.txt");
  if (in.is_open()) {
    string line;
    while (getline(in, line)) {
      cout << line << endl;
    }
  }
  return 0;
}