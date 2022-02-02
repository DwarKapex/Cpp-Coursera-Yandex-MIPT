# Desctiption

Implement a **ReversibleString** class that stores a string and supports the Reverse methods to reverse a string and ToString to get a string.

# Example

```c++
int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
```
# Output
```
evil
live
""
```