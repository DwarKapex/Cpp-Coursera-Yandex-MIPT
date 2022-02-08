# Desctiption

Define the "Student" structure with the following fields: first name, last name, day, month and year of birth. Create a vector from such structures, fill it in from the input data and then output the required fields according to the queries. Reading and writing data in this task is performed using standard streams.

Input format

The first line contains a single integer N from 0 to 10000 — the number of students.

Then there are N lines, each of which contains two lines from 1 to 15 characters long — the name and surname of the next student, and three integers from 0 to 1000000000 — the day, month and year of birth.

The next line contains a single integer M from 0 to 10000 — the number of requests.

The next M lines contain a string from 1 to 15 characters long - a request, and an integer from 1 to 1000000000 — the student's number (numbering starts with 1).


# Example

# Input

```
3
Ivan Ivanov 1 1 1901
Petr Petrox 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5
```

# Output

```
Ivan Ivanov
3.3.1903
bad request
```