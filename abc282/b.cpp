#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) {
        cin >> S.at(i);
    }
    int cnt = 0;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            bool flg = true;
            rep(k, M) {
                if (S[i][k] == 'x' && S[j][k] == 'x') {
                    flg = false;
                    break;
                }
            }
            if (flg) ++cnt;
        }
    }
    cout << cnt / 2 << endl;
}