# Desctiption

Extend the Person class from the First and Last Names 2 task with a constructor that allows you to specify the person's first and last name at birth, as well as the year of birth itself. The class must not have a default constructor.

When receiving at the input a year that is less than the year of birth:

the GetFullName and GetFullNameWithHistory methods must return "No person";

the ChangeFirstName and ChangeLastName methods must ignore the request.

In addition, it is necessary to declare all methods that are const as a matter of fact.

# Example

```c++
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
```
# Output
```
No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)
```