#include <string>

using namespace std;

struct Specialization {
  explicit Specialization(const string new_value)
  : value(new_value) {}
  string value;
};

struct Course {
  explicit Course(const string new_value)
  : value(new_value) {}
  string value;
};

struct Week {
  explicit Week(const string new_value)
  : value(new_value) {}
  string value;
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization s, Course c, Week w)
  : specialization(s.value)
  , course(c.value)
  , week(w.value) {}
};