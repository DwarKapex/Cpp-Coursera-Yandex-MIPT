# Desctiption

Given the following code:

```c++
#include <iostream>

using namespace std;

class Animal {
public:
    // your code

    const string Name;
};


class Dog {
public:
    // your code

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
```

Define the class bodies to the end, observing the following requirements:

 - The Dog class must be an inheritor of the Animal class.

 - The constructor of the Dog class must take a string type parameter and initialize the Name field in the Animal class with it.