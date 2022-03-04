#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <memory>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle: public Figure{
public:
    Triangle(const int a, const int b, const int c): name("TRIANGLE"), _a(a), _b(b), _c(c) {}
    virtual string Name() const override { return name; }
    virtual double Perimeter() const override { return _a + _b + _c; }
    virtual double Area() const override{
        double p = Perimeter()/2;
        return sqrt(p*(p-_a)*(p-_b)*(p-_c));
    }
private:
    const string name;
    const int _a, _b, _c;
};

class Rect: public Figure{
public:
    Rect(const int w, const int h): name("RECT"), _width(w), _height(h) {}
    virtual string Name() const override { return name; }
    virtual double Perimeter() const override { return 2*(_width + _height);}
    virtual double Area() const override { return _width*_height; }
private:
    const string name;
    const int _width, _height;

};

class Circle: public Figure{
public:
    Circle(const int r): name("CIRCLE"), _radius(r) {}
    virtual string Name() const override { return name; }
    virtual double Perimeter() const override { return 2*pi*_radius;}
    virtual double Area() const override { return pi*_radius*_radius ;}
private:
    const double pi = 3.14;
    const string name;
    const int _radius;
};

shared_ptr<Figure> CreateFigure(istringstream& in){
    string figure;
    in >> figure;
    if (figure == "RECT"){
        int w, h;
        in >> w >> h;
        return make_shared<Rect>(w,h);
    } else if (figure == "TRIANGLE"){
        int a,b,c;
        in >> a >> b >> c;
        return make_shared<Triangle>(a,b,c);
    } else if (figure == "CIRCLE"){
        int r;
        in >> r;
        return make_shared<Circle>(r);
    } else
        return make_shared<Rect>(1,1);
}