#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T>
void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    int N;
    cin >> N;
    vector<int> T(N), X(N), A(N);
    rep(i, N) {
        cin >> T.at(i) >> X.at(i) >> A.at(i);
    }
    vector< vector<long long> > dp(N + 1, vector<long long>(5, -1));
    dp[0][0] = 0;
    int prev_time = 0;

    rep(i, N) {
        int t = T.at(i) - prev_time;
        rep(j, 5) {
            if (dp.at(i).at(j) < 0) continue;
            int l = 0;
            int r = 4;
            if (j + t < 4) r = j + t;
            if (j - t > 0) l = j - t;
            for (int x = l; x <= r; ++x) {
                int imp = 0;
                if (x == X.at(i)) imp = A.at(i);
                chmax(dp.at(i + 1).at(x), dp.at(i).at(j) + imp);
            }
        }
        prev_time = T.at(i);
    }
    long long ans = 0;
    rep(i, 5) {
        chmax(ans, dp[N].at(i)); 
    }
    cout << ans << endl;
}