# Desctiption

Implement a class that maintains a set of rows in sorted order. The class must be held by two public methods:

```c++
class SortedStrings {
public:
  void AddString(const string& s) {
      // ...
  }

  vector<string> GetSortedStrings() {
      // ...
  }
private:
    // ...
};
```

# Example

```c++
void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}
```
# Output
```
1. first second third
2. first second second third
```
