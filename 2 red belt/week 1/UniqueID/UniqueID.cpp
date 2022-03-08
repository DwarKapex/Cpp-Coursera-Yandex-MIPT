#include <string>
#include <vector>
using namespace std;

#define UNIQ_IQ_2(x) unique_id_##x
#define UNIQ_IQ_HELPER(x) UNIQ_IQ_2(x)
#define UNIQ_ID UNIQ_IQ_HELPER(__LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}