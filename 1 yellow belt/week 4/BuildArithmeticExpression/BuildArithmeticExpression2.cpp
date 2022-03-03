#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

bool IsHigher(char op1, char op2){
    if ((op1 == '*' || op1 == '/') && (op2 == '-' || op2 == '+'))
        return true;
    return false;
}

int main() {
  deque<string> expression;
  int init_value;
  cin >> init_value;
  expression.push_back(to_string(init_value));
  int n = 0;
  cin >> n;
  char prev_op;
  while (n-- > 0) {
        char op;
        int value;
        cin >> op >> value;
        if (IsHigher(op, prev_op)) {
            expression.push_front("(");
            expression.push_back(")");
        }
        expression.push_back(" " + string{op} + " " + to_string(value));
        prev_op = op;
  }

  for (const auto op: expression) {
      cout << op;
  }
  cout << endl;
  return 0;
}