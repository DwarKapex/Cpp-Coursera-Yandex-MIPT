#include <iostream>
#include "phone_number.h"

using namespace std;
int main(int argc, const char * argv[]) {
    {
    PhoneNumber ph("+7-495-111-22-33");
    cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
    cout << ph.GetInternationalNumber() << endl;
    }
//    * 1-2-333 - некорректный номер - не начинается на '+'
    
    // +7-1233 - некорректный номер - есть только код страны и города"
    
    {
        PhoneNumber ph("+7-495-1112233");
        cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
        cout << ph.GetInternationalNumber() << endl;
    }
    {
        PhoneNumber ph("+323-22-460002");
        cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
        cout << ph.GetInternationalNumber() << endl;
    }
    {
        PhoneNumber ph("+1-2-coursera-cpp");
        cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
        cout << ph.GetInternationalNumber() << endl;
    }
    
    {
        PhoneNumber ph("+7-1234");
        cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << endl;
        cout << ph.GetInternationalNumber() << endl;
    }
}