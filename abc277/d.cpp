#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct ourMod {
    queue<int> list;
    long long loss_sum;
};

int main() {
    map<int, ourMod> modList;
    int N, M;
    cin >> N >> M;
    long long sum = 0, loss = 0;

    rep(i, N) {
        int a;
        cin >> a;
        sum += a;
        modList[a].list.push(i);
        modList[a].loss_sum += a;
    }
    
    for(auto m : modList) {
        int ind = m.first;
        long long tmp_loss = 0;
        bool flg = true;
        while (flg) {
            tmp_loss += modList[ind].loss_sum;
            ind = (ind + 1) % M;
            flg = modList.count(ind);
        }
        if (tmp_loss > loss) loss = tmp_loss;
    }
    cout << sum - loss << endl;
}