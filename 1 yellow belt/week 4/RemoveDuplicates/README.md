# Desctiption

Write a template function **RemoveDuplicates**, which takes the elements vector of objects of type T by reference and removes all duplicate elements from it. The order of the remaining elements can be any.

It is guaranteed that objects of type T can be compared using the operators ==, !=, < and >.

```c++
template <typename T>
void RemoveDuplicates(vector<T>& elements);
```

## Code example

```c++
int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
```

## Output

```
6 4 7 0 1
C++ C
```