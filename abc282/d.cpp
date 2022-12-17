#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T>
T myMax(T a, T b) {
    if (a > b) return a;
    else return b;
}

int main() {
    long long N, M;
    cin >> N >> M;
    map<long long, vector<long long> > X;
    rep(i, M) {
        long long u, v;
        cin >> u >> v;
        --u, --v;
        X[u].push_back(v);
        X[v].push_back(u);
    }
    vector<int> color(N, 0);
    queue<long long> q;
    vector< pair<long, long> > pair_list;
    
    rep(v, N) {
        pair<long, long> tmp = make_pair(0, 0);
        if (color[v] != 0) continue;
        color[v] = 1; q.push(v);
        tmp.first++;
        while (!q.empty()) {
           	long long v = q.front(); q.pop();
            for (long long nv : X[v]) {
                if (color[nv] == 0) {
                    color[nv] =  -1 * color[v];
                    q.push(nv);
                    if (color[nv] == 1) tmp.first++;
                    else if (color[nv] == -1) tmp.second++;;
                } else {
                    if (color[v] == color[nv]) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
    
            }
        }
        pair_list.push_back(tmp);
    }
    long long ans = N * (N - 1) / 2;

    for (auto p : pair_list) {
        ans -= p.first * (p.first - 1) / 2;
        ans -= p.second * (p.second - 1) / 2;
    }
    
    cout << ans - M << endl;
}