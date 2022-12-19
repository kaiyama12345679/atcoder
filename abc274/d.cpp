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
    vector<vector<bool>> dpX(N + 1, vector<bool>(2 * 10000 + 1, false));
    vector<vector<bool>> dpY(N + 1, vector<bool>(2 * 10000 + 1, false));
    int ang = 1;
    dpX[0][10000] = true;
    dpY[0][10000] = true;
    
    rep(i, N) {
        int a;
        cin >> a;
        switch (ang)
        {
        case 1:
            dpY[i + 1] = dpY[i];
            rep(j, 2 * 10000 + 1) {
                if (dpX[i][j] == true) {
                    dpX[i + 1][j + a] = true;
                    if (i > 0) {
                        dpX[i + 1][j - a] = true;
                    }
                }
            }
            break;

        case -1:
            dpX[i + 1] = dpX[i];
            rep(j, 2 * 10000 + 1) {
                if (dpY[i][j] == true) {
                    dpY[i + 1][j + a] = true;
                    dpY[i + 1][j - a] = true;
                }
            }
            break;
            
        }

        ang *= -1;
        
    }
    

    if (dpX[N][10000 + x] && dpY[N][10000 + y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}