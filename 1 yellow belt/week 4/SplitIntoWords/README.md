# Desctiption

Write a **SplitIntoWords** function that splits a string into words by spaces.

```c++
vector<string> SplitIntoWords(const string& s);
```

It is guaranteed that:

 - the string is not empty;

 - the string consists only of Latin letters and spaces;

 - the first and last characters of the string are not spaces;

 - the string does not contain two spaces in a row.

## Hint
The following method of solving the problem is recommended:

 - search for the next gap using the find algorithm;

 - create another word using the string constructor using two iterators.

## Code example

```c++
int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
```

## Output

```
4 С/Cpp/Java/Python
```