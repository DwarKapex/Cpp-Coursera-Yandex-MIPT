# Desctiption

In this task, you need to calculate various demographic indicators for a group of people. A person is represented by a ***Person** structure:

```c++
struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};
```

The **Gender** type is defined as follows:

```c++
enum class Gender {
  FEMALE,
  MALE
};
```

You need to write a Print Stats function that gets a vector of people, calculates and outputs the median age for each of the following groups of people:  

 - all people;

 - all women;

 - all men;

 - all busy women;

 - all unemployed women;

 - all busy men;

 - all unemployed men.

All 7 numbers must be output in strict accordance with the format (see example).

```c++
void PrintStats(vector<Person> persons);
```


# Example

## Code 
```c++
// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons);

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
```

## Output

```
Median age = 40
Median age for females = 40
Median age for males = 55
Median age for employed females = 40
Median age for unemployed females = 80
Median age for employed males = 55
Median age for unemployed males = 78
```