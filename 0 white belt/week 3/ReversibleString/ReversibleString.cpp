#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
  public:
    ReversibleString(string s = ""):
      m_str(s) {}

    void Reverse() {
      reverse(m_str.begin(), m_str.end());
    }
    string ToString() const {
      return m_str;
    }
  private:
    string m_str;
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}