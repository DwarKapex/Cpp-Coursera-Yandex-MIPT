#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <exception>

using namespace std;

class Rational{
    public:
        Rational(): p(0), q(1) {}
        Rational(int numerator, int denominator){
            if (denominator == 0)
                throw invalid_argument("");
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
    if (b.Numerator() == 0) throw domain_error("");
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
int main(){
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}