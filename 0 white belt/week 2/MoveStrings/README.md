# Desctiption

Implements a **MoveStrings** function that takes two vectors of strings, source and destination, and appends all strings from the first vector to the end of the second. After the function is executed, the source vector must be empty.

_To clear the contents of a vector, call its clear method_:

```c++
vector<string> words = {"hey", "hi"};
words.clear();
// now vecotr words is empty
```

# Example

```c++
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source must be empty
// destination must contain strings "z", "a", "b", "c" exactly in that order
```