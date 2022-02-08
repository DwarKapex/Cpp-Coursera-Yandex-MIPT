#include <exception>
class TimeServer {
public:
  string GetCurrentTime(){
    try{
        LastFetchedTime = AskTimeServer();
    } catch (system_error&){}

    return LastFetchedTime;

  }
private:
  string LastFetchedTime = "00:00:00";
};