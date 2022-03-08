# Desctiption

You are given a macro that prints the two values passed to it into the transmitted output stream. There is a drawback in the implementation of the macro that limits its applicability in real programs. You need to find and fix the flaw.

```c++
#define PRINT_VALUES(out, x, y) out << (x) << endl; out << (y) << endl
```