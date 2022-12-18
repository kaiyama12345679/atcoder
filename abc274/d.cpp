#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++) 

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    vector<vector<int>> X(N + 1);
    vector<vector<int>> Y(N + 1);
    int ang = 1;
    X.at(0).push_back(0);
    Y.at(0).push_back(0);
    
    rep(i, N) {
        int a;
        cin >> a;
        switch (ang)
        {
        case 1:
            Y.at(i + 1) = Y.at(i);
            for (auto m : X.at(i))  {
                X.at(i + 1).push_back(m + a);
                
                if (i > 0) {
                    X.at(i + 1).push_back(m - a);
                }
            }
            break;

        case -1:
            X.at(i + 1) = X.at(i);
            for (auto n : Y.at(i)) {
                Y.at(i + 1).push_back(n + a);
                Y.at(i + 1).push_back(n - a);
            }
        }

        ang *= -1;
        
    }
    bool flg1 = false, flg2 = false;
    for (auto u : X.at(N)) {
        if (u == x) {
            flg1 = true;
            break;
        }
    }

    for (auto v : Y.at(N)) {
        if (v == y) {
            flg2 = true;
            break;
        }
    }

    if (flg1 && flg2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}