# Desctiption

Let's imagine that you are developing an innovative flight search service AviaScanner. In your service, the ticket is presented in the form of a structure

```c++
struct Date {
  int year, month, day;
};

struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  uint64_t price;
};
```

You are currently working on a search results sorting function. The user enters his request and receives a list of suitable tickets. Then he can set the sorting parameters of this list. For example, first by price, then by departure time, and finally by arrival airport.

To implement the sorting as in the example, you can use the digital sorting algorithm:

```c++
void SortTickets(vector<AirlineTicket>& tixs) {
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.to < rhs.to;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.departure_time < rhs.departure_time;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.price < rhs.price;
  });
}
```

As you can see, there is code duplication in the example above — we had to write three lambda functions that differ only in the field by which the sorting is performed. You can get rid of this duplication by writing the SORT_BY macro and applying it as follows:

```c++
void SortTickets(vector<AirlineTicket>& tixs) {
  stable_sort(begin(tixs), end(tixs), SORT_BY(to));
  stable_sort(begin(tixs), end(tixs), SORT_BY(departure_time));
  stable_sort(begin(tixs), end(tixs), SORT_BY(price));
}
```

Write the SORT_BY macro, which takes as a parameter the name of the field of the Airline Ticket structure. Calling sort(begin(text), end(text), SORT_BY(some_field)) should sort the tixs vector by the some_field field.