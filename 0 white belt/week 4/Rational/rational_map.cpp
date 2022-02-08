#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Rational{
    public:
        Rational(): p(0), q(1) {}
        Rational(int numerator, int denominator){
            if (numerator*denominator == 0){
                p = 0; q=1;
            }
            else{
                int r = gcd(numerator, denominator);
                p = numerator/r;
                q = denominator/r;
                if (p*q < 0){
                    p = -abs(p);
                    q = abs(q);
                }
            }
        }
        int Numerator() const {return p; }
        int Denominator() const { return q; }
    private:
        int gcd(int n, int m) { return m == 0? n : gcd(m, n%m); }
        void SimplifyFraction(){
                                
        
        }
        int p, //numenator
            q; //denominator

};

bool operator==(const Rational& a, const Rational& b){
    return a.Numerator() == b.Numerator() &&
           a.Denominator() == b.Denominator();
}

bool operator<(const Rational& a, const Rational& b){
    return (a.Numerator()*b.Denominator()-a.Denominator()*b.Numerator())< 0;

}



Rational operator+(const Rational& a, const Rational& b){
    int q = a.Denominator()*b.Denominator();
     return Rational(a.Numerator()*b.Denominator() + a.Denominator()*b.Numerator(),q);
}

Rational operator-(const Rational& a, const Rational& b){
    int q = a.Denominator()*b.Denominator();
     return Rational(a.Numerator()*b.Denominator() - a.Denominator()*b.Numerator(),q);
}
Rational operator*(const Rational& a, const Rational& b){
     return Rational(a.Numerator()*b.Numerator(), a.Denominator()*b.Denominator());
}
Rational operator/(const Rational& a, const Rational& b){
    int q = a.Denominator()*b.Denominator();
     return Rational(a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());
}

istream& operator>>(istream& is, Rational& r){
    int p,q;
    if (!(is >> p))
       return is;
    is.ignore(1);
    if (!(is >> q))
        return is;
    Rational temp(p,q);
    r = temp;
    return is;
}
ostream& operator<<(ostream& os, const Rational& r){
    os << r.Numerator() << '/' << r.Denominator();
    return os;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
