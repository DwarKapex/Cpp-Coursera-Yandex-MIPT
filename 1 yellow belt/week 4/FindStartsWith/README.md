# Desctiption

## Part 1. Grouping by symbol

Write the *FindStartsWith* function:

 - accepting a sorted set of strings in the form of iterators range_begin, range_end and one prefix character;

 - returns a range of strings starting with the prefix character as a pair of iterators.

```c++
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix);
```

If the resulting range is empty, its boundaries should point to the place in the container where you can insert any string starting with the prefix character without violating the sorting order (similar to the equal_range algorithm). It is guaranteed that the strings consist only of lowercase Latin letters and the prefix symbol is also a lowercase Latin letter.

The search should be carried out for logarithmic complexity - for example, using binary search.

# Code Example

```c++
int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  
  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}
```

## Output

```
moscow murmansk
2 2
3 3
```

## Part 2. Grouping by prefix

Write a more universal version of the FindStartsWith function, which takes as a prefix an arbitrary string consisting of lowercase Latin letters.

```c++
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix);
```

# Code Example

```c++
int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}
```

## Output

```
moscow motovilikha
2 2
3 3
```