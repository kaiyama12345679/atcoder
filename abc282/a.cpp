#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int K;
    cin >> K;
    string S = "";
    rep(i, K) {
        S.push_back((char)(i + 'A'));
    }
    cout << S << endl;
}