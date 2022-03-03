# Desctiption

Write a template function *FindGreaterElements* that accepts a set of elements objects of type T and another *border* object of type T and returns a vector from all elements of the set larger than border in ascending order.

```c++
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);
```

## Code example

```c++
int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
```

## Output

```
7 8
0
```