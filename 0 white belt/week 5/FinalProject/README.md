# Desctiption

It is necessary to write a program in C++ that implements work with a simple database (abbreviated as "DB"). The program will communicate with the user via standard input and output (stdin and stdout streams).

We will store pairs of the following types in our database: date, event. Let's define the date as a string of the form Year-Month-Day, where Year, Month and Day are integers. 

We define the event as a string of arbitrary printed characters without delimiters inside (spaces, tabs, etc.). The event cannot be an empty string. Many different events can happen on the same date, the database should be able to save them all. Identical events that occurred on the same day do not need to be saved: it is enough to save only one of them.

Our database must understand certain commands so that it can be interacted with:

|Description|Command|
|-|-|
|adding an event|Add Date Event|
|deleting an event|Del Date Event|
|Deleting all events for a specific date|Del Date|
|search for events for a specific date|Find Date|
|print all events for all dates|Print|

All commands, dates and events are separated by spaces when entering. Commands are read from standard input. There can be exactly one command in one line, but you can enter multiple commands in multiple lines. Empty lines can also be received at the input — they should be ignored and continue processing new commands in subsequent lines.

## Adding an Event (Add Date Event)
When adding an event, the database must remember it and then show it when searching (with the Find command) or printing (with the Print command). If the specified event already exists for this date, its re-addition should be ignored. In case of correct input (see the section "Input error handling"), the program should not output anything to the screen.

## Deleting an Event (Del Date Event)
The command must delete the previously added event with the specified name on the specified date, if it exists. If an event is found and deleted, the program should output the string "Deleted successfully" (without quotes). If an event is not found on the specified date, the program should output the string "Event not found" (without quotes).

## Deleting Multiple Events (Del Date)
The command deletes all previously added events for the specified date. The program should always output a string like "Deleted N events", where N is the number of all found and deleted events. N can be zero if there were no events on the specified date.

## Event Search (Find Date)
Find and print previously added events on the specified date. The program should print only the events themselves, one per line. Events should be sorted in ascending order in the order of comparing strings with each other (type string).

## Print all events (Print)
With this command, you can show the full contents of our database. The program should print all Date Event pairs, one per line. All pairs should be sorted by date, and events within the same date should be sorted in ascending order in the order of comparing strings with each other (type string). Dates should be formatted in a special way: YYYY-MM-DD, where G, M, D are the digits of the numbers of the year, month and day, respectively. If a number has fewer digits, then it should be supplemented with zeros, for example, 0001-01-01 — the first of January of the first year. You won't need to output a date with a negative year value.

# Handling input errors
The input in this task is not always correct: your program must correctly handle some input errors.

## What input errors need to be handled
If the user has entered an unknown command, the program should report this by displaying the line "Unknown command: COMMAND", where COMMAND is the command that the user entered. The command is considered the first word in the line (before the space).

If the date does not match the Year-Month-Day format, where the Year, Month and Day are arbitrary integers, then the program should print "Wrong date format: DATE", where DATE is what the user entered instead of the date (before the space). Note that the parts of the date are separated by exactly one hyphen, and the date itself should not contain extra characters either before the year or after the day. The date parts cannot be empty, but they can be zero and even negative.

 - If the date format is correct, you need to check the validity of the month and day.

 - If the month number is not a number from 1 to 12, print "Month value is invalid: MONTH", where MONTH is an invalid month number, for example, 13 or -1.

 - If the month is correct, and the day does not lie in the range from 1 to 31, print "Day value is invalid: DAY", where DAY is an incorrect day number in the month, for example, 39 or 0.

### Please note that:

The value of the year does not need to be checked separately.

There is no need to check the calendar correctness of the date: the number of days in each month is considered to be 31, leap years do not need to be taken into account.

If both the month and the day are incorrect, then you need to display one error message per month.

### Examples:


 - 1-1-1 — correct date;

 - -1-1-1 — correct date (year -1, month 1, day 1);

 - 1--1-1 — date in the correct format, but with an incorrect month -1;

 - 1---1-1 — the date is in the wrong format: the month cannot start with two hyphens.

1-+1-+1 — the correct date, since +1 is an integer

After processing any of the described errors of entering and printing a message, the program must complete its execution.

## Which input errors do not need to be handled

We do not aim to break your program in all possible ways, therefore, with the exception of the one described in the previous paragraph, you can rely on the correctness of the input. In particular, we guarantee that:

Each command occupies exactly one line in its entirety, although there may be empty lines in the input (they should be ignored).

Events always contain the specified number of arguments: the Add command is always followed by a date and an event, the Find command is always followed by a date, the Del command is always followed by a date and possibly an event, and the Print command does not contain additional information.

All commands, dates, and events are non-empty strings and do not contain spaces or other whitespace characters. (In particular, our tests do not contain the "Add 2018-02-12" command, because there is no event name after the date in it.) On the other hand, the Del command may not contain events after the date: in this case, you need to delete all events for the specified date (see the section "Deleting multiple events").

Despite the fact that a date with a negative year value is considered correct, the tests are designed so that it does not need to be output in the Print command.

# Examples
## Correct input
```
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2
Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2
```

### Output
```
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found
```

### Incorrect date format

```
Add 0-13-32 event1
```

### Output

```
Month value is invalid: 13
```