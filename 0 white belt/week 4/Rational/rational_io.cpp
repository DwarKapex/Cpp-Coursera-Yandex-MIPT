#include <iostream>
#include <sstream>

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
    char delimiter;
    is >> delimiter;
    if (delimiter != '/') {
        return is;
    }
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
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}


