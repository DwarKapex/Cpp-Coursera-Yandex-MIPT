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
        Rational(long numerator, long denominator){
            if (denominator == 0)
                throw invalid_argument("");
            if (numerator*denominator == 0){
                p = 0; q=1;
            }
            else{
                long r = gcd(numerator, denominator);
                p = numerator/r;
                q = denominator/r;
                if (p*q < 0){
                    p = -abs(p);
                    q = abs(q);
                }
            }
        }
        long Numerator() const {return p; }
        long Denominator() const { return q; }
    private:
        int gcd(long n, long m) { return m == 0? n : gcd(m, n%m); }
        void SimplifyFraction(){
                                
        
        }
        long p, //numenator
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
    Rational r1, r2;
    try {
        cin >> r1;
    } catch (invalid_argument&){
        cout << "Invalid argument";
        return -1;
    }
    cin.ignore(1);
    char op;
    cin >> op;
    try{
        cin >> r2;
    } catch (invalid_argument&){
        cout << "Invalid argument";
        return -2;
    }
    if (op == '+')
        cout << (r1+r2);
    else if (op == '*')
        cout << r1*r2;
    else if (op == '-')
        cout << r1-r2;
    else{
        try {
            cout << r1/r2;
        } catch (domain_error&){
            cout << "Division by zero";
            return -3;
        }
    }
}