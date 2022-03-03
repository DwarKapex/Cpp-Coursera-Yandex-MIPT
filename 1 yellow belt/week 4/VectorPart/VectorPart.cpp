#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto first_negative_it = std::find_if(
        numbers.begin(),
        numbers.end(),
        [](const int n) { return n < 0;}
    );
    while (first_negative_it != numbers.begin()) {
        --first_negative_it;
        cout << *first_negative_it << " ";
    }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}