# Desctiption

You have been given the full definition of the Rectangle class

```c++
class Rectangle {
public:
    Rectangle(int width, int height)
    {
        width_ = width;
        height_ = height;
    }

    int GetArea() const {
        return width_ * height_;
    }

    int GetPerimeter() const {
        return 2 * (width_ + height_);
    }

    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }

private:
    int width_, height_;
};
```

Send the **rectangle.h** header file containing the Rectangle class declaration. It should be a full-fledged header file that can be used in a large project. In particular, it should solve the problem of double inclusion.