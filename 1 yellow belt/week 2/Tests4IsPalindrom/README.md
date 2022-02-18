# Desctiption

In this task, you need to develop a set of unit tests for the function

```c++
bool IsPalindrom(const string& s);
```
This function checks whether the string s is a palindrome. A palindrome is a word or phrase that reads equally from left to right and from right to left. Examples of palindromes: madam, level, wasitacaroracatisaw

Develop a set of unit tests that will accept the correct implementations of the IsPalindrom function and reject the incorrect ones. At the same time, keep in mind that the correct implementation of the function:

considers an empty string a palindrome;

considers a string of one character to be a palindrome;

performs the usual comparison of characters for equality, without ignoring any characters, including whitespace.

When developing tests, think about what mistakes can be made when implementing the IsPalindrom function. Examples of errors:

the first or last character is ignored;

the comparison of the corresponding characters ends not in the middle of the line, but earlier;

spaces are ignored

You can get started with a template that contains our unit test framework and the IsPalindrom function template (**test_palindrom.cpp**)
