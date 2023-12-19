#include <cmath>
#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iomanip>
#include <type_traits>
#include <string>
#include <queue>
#include <map>
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
int main() {
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string vec[n];
    for (int i = 0; i < n; i++) cin >> vec[i];
    int cnt[n][26];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += vec[i].size();
        for (int j = 0; j < 26; j++) cnt[i][j] = 0;
        for (int j = 0; j < vec[i].size(); j++) cnt[i][vec[i][j] - 'a']++;
    }
    int dp[(1 << n)];
    int mn[(1 << n)][26];
    int myMin[(1 << n)];
    for (int i = 0; i < (1 << n); i++) {
        myMin[i] = 0;
        for (int j = 0; j < 26; j++) {
            mn[i][j] = INT_MAX;
            for (int k = 0; k < n; k++) if ((i & (1 << k))) mn[i][j] = min(mn[i ^ (1 << k)][j], cnt[k][j]);
            myMin[i] += mn[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) dp[i] = 0;
    for (int msk = 1; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == 1) continue;
        for (int sub_msk = msk; sub_msk; sub_msk = (sub_msk - 1) & msk) {
            dp[msk] = max(dp[msk], dp[sub_msk] + dp[msk ^ sub_msk] + myMin[msk]);
        }
    }
    cout << ans - dp[(1 << n) - 1] + 1;
}