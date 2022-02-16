# Desctiption

Implement the template function GetRefStrict, which takes as input: map and the value of the key k. If there is no element by key k in the collection, then the function should throw a runtime_error exception, otherwise return a reference to the element in the collection.

Example of using the function:

```c++
map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // output is  `newvalue`
```