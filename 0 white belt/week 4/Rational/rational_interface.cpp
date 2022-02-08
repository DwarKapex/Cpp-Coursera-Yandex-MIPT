#include <iostream>

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
int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
