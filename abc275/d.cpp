#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<long long, long long> dp;

long long f(long long n) {
    if (dp.count(n)) return dp[n];
    else return dp[n] = f(n / 2) + f(n / 3);
}

int main() {
    long long N;
    cin >> N;
    dp[0] = 1;
    
    cout << f(N) << endl;
}