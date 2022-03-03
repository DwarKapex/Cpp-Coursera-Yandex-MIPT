# Desctiption

Write the *FindNearestElement* function, for a set of integers numbers and a given number border, which returns an iterator to the element of the set closest to border. If there are several nearest elements, return the iterator to the smallest of them.

```c++
set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border);
```

# Code Example

```c++
int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
```

## Output

```
1 4 4 6 6
1
```