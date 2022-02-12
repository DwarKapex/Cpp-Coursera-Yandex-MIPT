# Desctiption

# Part 1

Implement a bus route storage system. You need to process the following requests:

 - **NEW_BUS bus stop_count stop1 stop2 ...** - add a bus route with the name bus and stop_count stops with the names stop1, stop2, ...

 - **BUSES_FOR_STOP stop** - print the names of all bus routes passing through the stop stop.

 - **STOPS_FOR_BUS bus** - display the names of all stops on the bus route with a list of buses that you can transfer to at each of the stops.

 - **ALL_BUSES** - list all routes with stops.

## Input format

The first line of the input contains the number of requests Q, then the Q lines are followed by descriptions of requests.

It is guaranteed that all names of routes and stops consist only of Latin letters, numbers and underscores.

For each request, **NEW_BUS bus stop_count stop1 stop2 ...** it is guaranteed that there is no bus route, the number of stops is greater than 0, and after the stop_count number, exactly this number of stop names follows, and all the names in each list are different.

## Output format

For each request, except **NEW_BUS**, output the corresponding response to it:

 - In response to the **BUSES_FOR_STOP stop** request, output a space-separated list of buses passing through this stop, in the order in which they were created by the NEW_BUS commands. If stop does not exist, output No stop.

 - For the **STOPS_FOR_BUS bus** request, output descriptions of bus route stops in separate lines in the order in which they were specified in the corresponding NEW_BUS command. The description of each stop stop should look like *Stop stop: bus1 bus2 ...*, where *bus1 bus2 ...* is a list of buses passing through the stop stop, in the order in which they were created by the NEW_BUS commands, with the exception of the original bus route. If no bus passes through the stop stop, except bus, instead of the list of buses for it, output no interchange. If the bus route does not exist, output No bus.

 - For the **ALL_BUSES** query, output the descriptions of all buses in alphabetical order. The description of each bus route should look like *Bus bus: stop1 stop2 ...*, where *stop1 stop2 ...* is a list of bus stops in the order in which they were specified in the corresponding **NEW_BUS** command. If there are no buses, output No buses.

## Warning

The problem condition above contains many important details. If you are not sure that you have not missed any, re-read the condition again.

## Example

### Input
```
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
```

### Output

```
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
```

# Part 2

In this task, you need to assign numbers to bus routes.

Namely, for each route specified by a set of stop names, you either need to issue a new number (the first route is 1, the second is 2, etc.), or return the number of an existing route that corresponds to such a set of stops.

Sets of stops obtained from each other by permutation of stops are considered different (see example).

## Tip
In C++, the dictionary key can be not only a number or a string, but also another container, for example, vector.

## Input format
First, the number of requests Q is entered, then Q descriptions of requests.

Each request represents a positive number of stops N, followed by N different names of stops of the corresponding route separated by a space. The names of stops consist only of Latin letters and underscores.

## Output format
Print the answer to each request in a separate line.

If a route with this set of stops already exists, in response to the corresponding request, output Already exists for i, where i is the number of the route with this set of stops. Otherwise, you need to allocate a new number i to the entered set of stops and output it in the New bus i format.

## Example
### Input

```
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
```

### Output

```
New bus 1
New bus 2
Already exists for 1
New bus 3
```