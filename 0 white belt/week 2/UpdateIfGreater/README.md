# Desctiption

Write an **UpdateIfGreater** function that takes two integer arguments, first and second. If first is greater than second, your function must write the value of the first parameter to second. In this case, the specified function should not return anything, and the change in the second parameter should be visible on the calling side.

# Example

```c++
int a = 4;
int b = 2;
UpdateIfGreater(a, b);
// b must be 4
```

# Comment
In this task, you need to choose the types for the parameters of the UpdateIfGreater function yourself. Think about which one must be a reference, and which one can be just an int. At the same time, take into account the different options for calling the function:

```c++
UpdateIfGreater(x, y);
UpdateIfGreater(5, y);
```