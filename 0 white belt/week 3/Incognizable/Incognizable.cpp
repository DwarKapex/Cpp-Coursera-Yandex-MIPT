struct Incognizable {
  Incognizable(int a=0, int b = 0):
     m_a(a), m_b(b) {}
  int m_a;
  int m_b;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}