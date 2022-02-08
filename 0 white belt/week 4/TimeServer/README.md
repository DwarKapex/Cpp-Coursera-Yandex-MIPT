# Desctiption

You are given the string Ask Time Server() function, about which the following is known:

 - in the course of its work, it accesses a remote server over the network, requesting the current time;

 - if the server was accessed successfully, the function returns the current time as a string;

 - if a network problem occurs while accessing the server, the function throws a system_error exception;

 - the function can throw other exceptions to report other problems.

Using the Ask Time Server function, write a Time Server class with the following interface:

```c++
class TimeServer {
public:
  string GetCurrentTime();
private:
  string last_fetched_time = "00:00:00";
};
```

The getCurrentTime method should behave like this:

- it should call the AskTimeServer function, write its result in the last_fetched_time field and return the value of this field;

 - if AskTimeServer throws a system_error exception, the getCurrentTime method should catch it and return the current value of the last_fetched_time field. Thus, we hide network problems from the user by returning the value that was received during the last successful access to the server.;

 - if AskTimeServer throws another exception, the getCurrentTime method should throw it further, because within the TimeServer class we don't know how to handle problems unrelated to network failures.

# How to complete a task

You are given a file containing a TimeServer class template. In it, you need to implement the getCurrentTime method as described above. The file contains an empty AskTimeServer function. To test your implementation, you can try adding different commands to its body:

 - returning a string;

 - throwing a system_error exception (the system_error class accepts an error_code type parameter in the constructor, so the easiest way to throw this exception is throw system_error(error_code());, for more information, see https://en.cppreference.com/w/cpp/error/system_error );

 - throwing other exceptions.