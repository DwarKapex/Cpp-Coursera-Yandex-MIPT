#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    Student(string n, string s, int d, int m, int y)
    : name(n), surname(s), day(d), month(m), year(y) {}
    string name, surname;
    int day, month, year;
};

int main(){
    int n=0;
    cin >> n;
    vector<Student> students;
    string sn,ss;
    int d, m, y;
    for (int i = 0; i < n; ++i) {
        cin >> sn >> ss >> d >> m >> y;
        students.emplace_back(sn, ss, d, m, y);
    }
    cin >> m;
    while (m-- > 0) {
        cin >> ss >> d;
        if (ss == "name" && d > 0 && d <= n) {
            cout << students[d-1].name << " " << students[d-1].surname;
        } else if (ss == "date" && d > 0 && d <= n) {
            cout << students[d-1].day << "." << students[d-1].month << "." << students[d-1].year; 
        } else {
            cout << "bad request";
        }
        cout << endl;
    }
    return 0;
}