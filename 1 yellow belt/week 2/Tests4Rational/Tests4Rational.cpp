#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }
    
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }
    
private:
    int fail_count = 0;
};

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}
/*
 class Rational {
public:
    Rational() {  // дробь по умолчанию — 0/1
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
    
    int Numerator() const {
        return numerator;
    }
    
    int Denominator() const {
        return denominator;
    }
    
private:
    int numerator;
    int denominator;
};
*/

bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
    lhs.Denominator() == rhs.Denominator();
}

bool operator != (const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}


Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }
    return is;
}

ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}


void TestConstructor(){
    stringstream ss;
    ss  << Rational() << " "   // (0/1)
        << Rational(0,-1) << " " // (0/1)
        << Rational(1,-1) << " " // (-1/1)
        << Rational(-1,-1) << " " // (1/1)
        << Rational(3,6) << " " // (1/2)
        << Rational(4,-2) << " " // (-2/1)
        << Rational(-3,-6) << " " // (1/2)
        << Rational(0,8) << " " // (0/1)
        << Rational(0,-8) << " " // (0/1)
        << Rational(8,13); //8/13
    
    AssertEqual(ss.str(), "0/1 0/1 -1/1 1/1 1/2 -2/1 1/2 0/1 0/1 8/13", "Test constructor");
}

void TestNumerator(){
    Rational a{1,-1}, b{-1,-1}, c{3,6}, d{4,-2}, e{0,8}, f{0,-8};
    AssertEqual(a.Numerator(), -1, "a numberator");
    AssertEqual(b.Numerator(), 1, "b numberator");
    AssertEqual(c.Numerator(), 1, "c numberator");
    AssertEqual(d.Numerator(), -2, "d numberator");
    AssertEqual(e.Numerator(), 0, "e numberator");
    AssertEqual(f.Numerator(), 0, "f numberator");
}

void TestDenumerator(){
    Rational a{1,-1}, b{-1,-1}, c{3,6}, d{4,-2}, e{0,8},f{0,-8};
    AssertEqual(a.Denominator(), 1, "a numberator");
    AssertEqual(b.Denominator(), 1, "b numberator");
    AssertEqual(c.Denominator(), 2, "c numberator");
    AssertEqual(d.Denominator(), 1, "d numberator");
    AssertEqual(e.Denominator(), 1, "e numberator");
    AssertEqual(f.Denominator(), 1, "e numberator");
}


int main() {
    TestRunner runner;
    runner.RunTest(TestConstructor, "Test constractor");
    runner.RunTest(TestNumerator, "Test numerator");
    runner.RunTest(TestDenumerator, "Test denumerator");
    return 0;
}