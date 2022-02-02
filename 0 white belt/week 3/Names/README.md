# Desctiption

Implement a class for a person that maintains a history of the person's changes to their last name and first name.

```c++
class Person {
public:
  void ChangeFirstName(int year, const string& first_name);
  void ChangeLastName(int year, const string& last_name);
  string GetFullName(int year);
private:
};
```

Consider that in each year there can be no more than one change of surname and no more than one change of name. At the same time, over time, more and more facts from the person’s past can be discovered, so the years in successive calls to the ChangeLastName and ChangeFirstName methods do not have to increase.

It is guaranteed that all first and last names are non-empty.

The string returned by the **GetFullName** method must contain the person's first and last name, separated by a single space, as of the end of the given year.

 - If there has been no last name or first name change for the given year, return the string "Incognito".

 - If there has been a last name change for the given year, but no first name change, return "last_name with unknown first name".

 - If there has been a name change for the given year, but no last name change, return "first_name with unknown last name".

# Example

```c++
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
```
# Output
```
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
```
