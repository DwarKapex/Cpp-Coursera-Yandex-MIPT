#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int worry_count = 0;
    vector<bool> que;
    while (n-- > 0) {
        string cmd;
        int k;
        cin >> cmd;
        if (cmd == "WORRY_COUNT") {
            cout << worry_count << endl;
        } else {
            cin >> k;
            if (cmd == "WORRY") {
                worry_count += !que[k];
                que[k] = true;
            } else if (cmd == "QUIET") {
                worry_count -= que[k];
                que[k] = false;
            } else {
                if (k < 0) {
                    for (int i = que.size()+k; i < que.size(); ++i) {
                        worry_count -= que[i];
                    }
                }
                que.resize(que.size() + k);
            }
        }
    }
}