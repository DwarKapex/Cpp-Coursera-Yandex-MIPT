# Desctiption

IIn the "Program Decomposition" task, we broke the monolithic code into a set of functions and classes. Now we will take another step and divide our program into several files. In this task, you need to create a project consisting around the following file: 


1. query.h, there is a well in it:

    - enum class QueryType

     - struct Query

    - declaration of istream& operator >> (istream& is, Query& q) 


2. query.cpp, there is a well in it

    - definition of istream& operator >> (istream& is, Query& q);

3. responses.h: 

    - struct BusesForStopResponse

    - ostream& operator << (ostream& os, const BusesForStopResponse& r)

    - struct StopsForBusResponse

    - ostream& operator << (ostream& os, const StopsForBusResponse& r)

    - struct AllBusesResponse

    - ostream& operator << (ostream& os, const AllBusesResponse& r)

4. responses.cpp: definitions of everything declared in responses.h

5. bus_manager.h: BusManager class declaration

6. bus_manager.cpp: definitions of methods of the BusManager class

7. main.cpp: main functions
