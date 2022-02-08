# Desctiption

Write a function

```c++
void EnsureEqual(const string& left, const string& right);
```

If the left string is not equal to the right string, the function should throw a runtime_error exception with the content "<l> != <r>", where <l> and <r> are strings that are stored in the left and right variables, respectively. Note that there should be exactly one space around the inequality sign in the line that is placed in the exception.

If left == right, the function must terminate correctly.

For example, the code:

```c++
int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
```

should print:

```
C++ White != C++ Yellow
```