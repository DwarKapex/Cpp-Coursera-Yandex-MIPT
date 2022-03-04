# Desctiption

You are given the main function, which reads commands for working with a set of geometric shapes from the standard input:

```c++
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
```
As you can see from the code, there are two types of commands: 

 - **ADD** — add a shape to the set;

 - **PRINT** - for each shape in the set, print the name, perimeter and area.

The program supports three types of shapes: rectangle, triangle and circle. Their addition is described as follows:

 - **ADD RECT** *width height* — add a rectangle with the dimensions width and height (for example, ADD RECT 2 3).

 - **ADD TRIANGLE** *a b c* - add a triangle with sides a, b and c (for example, ADD TRIANGLE 3 4 5).

 - **ADD CIRCLE** *r* - add a circle of radius r (for example, ADD CIRCLE 5).

## Example 
### Input
```
ADD RECT 2 3
ADD TRIANGLE 3 4 5
ADD RECT 10 20
ADD CIRCLE 5
PRINT
```

### Output
```
RECT 10.000 6.000
TRIANGLE 12.000 6.000
RECT 60.000 200.000
CIRCLE 31.400 78.500
```
