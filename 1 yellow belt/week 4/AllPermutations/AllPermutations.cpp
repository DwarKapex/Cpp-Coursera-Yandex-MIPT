#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  reverse(a.begin(), a.end());
  do  {
    bool first = true;
    for (const int v: a) {
      if (!first) {
        cout << " ";
      } 
      first = false;
      cout << v;
    }
    cout << endl;
  } while (prev_permutation(a.begin(), a.end()));
}