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
  MergeSort(copy.begin(), next(copy.begin(), n/3));
  MergeSort(next(copy.begin(), n/3), next(copy.begin(), 2*n/3));
  MergeSort(next(copy.begin(), 2*n/3), copy.end());
  vector<typename RandomIt::value_type> tmp;
  merge(copy.begin(), next(copy.begin(), n/3),
        next(copy.begin(), n/3), next(copy.begin(), 2*n/3),
        back_inserter(tmp));
  merge(tmp.begin(), tmp.end(),
        next(copy.begin(), 2*n/3), copy.end(),
        range_begin);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}