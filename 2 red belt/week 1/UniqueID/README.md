# Desctiption

Develop a UNIQ_ID macro that will generate an identifier unique within a given cpp file. For example, the following code should compile and work:

```c++
int UNIQ_ID = 5;
string UNIQ_ID = "hello!";
```

The code above will not compile:

```c++
int UNIQ_ID = 5; string UNIQ_ID = "hello"; // both in one line
```

Tips:

 - think about how you can apply the __LINE macro__

 - check out the concatenation in macros, as well as macros as parameters of other macros at the links below:

    - [The basics](https://www.iar.com/knowledge/learn/programming/basics-of-using-the-preprocessor)

    - [The most interesting](https://www.iar.com/knowledge/learn/programming/advanced-preprocessor-tips-and-tricks)