
Implement a template function
```
template <typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if (
  ForwardIterator first, 
  ForwardIterator last,
  UnaryPredicate pred);
```
returning an iterator to the maximum element in the range [first, last) for which the predicate pred returns true. If the range contains several suitable elements with a maximum value, the result will be the first occurrence of such an element. If the range does not contain suitable elements, then the function should return last.
     
It is guaranteed that:
- pred accepts an argument of the type that range elements have ++, ==,! =, * (dereferencing) operators are defined for ForwardIterator
- for the type pointed to by the iterator, the operator <("less") is defined
        
 Procurement of the solution:
        
        max_element_if.cpp
        Problem Author - Olga Marchevskaya
