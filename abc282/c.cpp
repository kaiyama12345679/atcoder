#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool mode = false;
    string ans;
    rep(i, N) {
        char tmp = S.at(i);
        if (tmp == '"') {
            mode = mode ? false : true;
        }
        if (tmp == ',' && mode == false) tmp = '.';

        ans.push_back(tmp);
    }
    
    cout << ans << endl;
}