# Desctiption

Given the **LectureTitle** structure:

```c++
struct LectureTitle {
  string specialization;
  string course;
  string week;
};
```

Add the constructor and structures **Specialization**, **Course**, **Week* so that the LectureTitle object can be created using code

```c++
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
```

but get a compilation error for the code below:

```c++
LectureTitle title("C++", "White belt", "4th");

LectureTitle title(string("C++"), string("White belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);

LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);
```