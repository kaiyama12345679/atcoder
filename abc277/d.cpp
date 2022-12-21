#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T>
void chmax(T& a, T b) {
    if (a < b) a = b;
}

struct ourMod {
    queue<long long> list;
    long long loss_sum = 0;
};

int main() {
    map<int, ourMod> modList;
    long long N, M;
    cin >> N >> M;
    long long sum = 0, loss = 0;
    set<long long> indList;

    rep(i, N) {
        long long a;
        cin >> a;
        sum += a;
        modList[a].list.push(i);
        modList[a].loss_sum += a;
        indList.insert(a);
    }
    long long j = 0;
    long long tmp_loss = 0;
    for (const auto i : indList) {
        if (j == i) {
            tmp_loss += modList[i].loss_sum;
        } else {
            tmp_loss = modList[i].loss_sum;
            j = i;
        }

        chmax(loss, tmp_loss);

        j = (j + 1) % M;
    }
    for (const auto i : indList) {
        if (j == i) {
            tmp_loss += modList[i].loss_sum;
        } else {
            tmp_loss = modList[i].loss_sum;
            j = i;
        }

        chmax(loss, tmp_loss);

        j = (j + 1) % M;
    }

    
    long long ans = 0;
    chmax(ans, sum - loss);

    cout << ans << endl;
}