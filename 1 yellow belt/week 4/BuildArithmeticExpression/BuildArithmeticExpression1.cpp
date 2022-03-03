#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
  deque<string> expression;
  int init_value;
  cin >> init_value;
  expression.push_back(to_string(init_value));
  int n = 0;
  cin >> n;
  while (n-- > 0) {
        char op;
        int value;
        cin >> op >> value;
        expression.push_front("(");
        expression.push_back(")");
        expression.push_back(" " + string{op} + " " + to_string(value));
  }

  for (const auto op: expression) {
      cout << op;
  }
  cout << endl;
  return 0;
}