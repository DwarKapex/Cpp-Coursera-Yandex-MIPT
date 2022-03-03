#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  auto n = distance(range_begin, range_end);
  if (n < 2) {
    return;
  }
  vector<typename RandomIt::value_type> copy(range_begin, range_end);
  auto middle = next(copy.begin(), n/2);
  MergeSort(copy.begin(), middle);
  MergeSort(middle, copy.end());
  merge(copy.begin(), middle,
        middle, copy.end(),
        range_begin);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}