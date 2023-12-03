#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
/*
dp[g][need] => dp[gcd(g,x)][s +-x]
nx:
    g giảm
    need giảm

dp[i] = sum(dp[i - k]) + sum(cost(i - k))
cost(x): số lượng dãy có tổng là x và có g != 1 và gcd(g,k) = 1

1: 1
2: 2
    1 1
    2
3: 4
    1 1 1
    1 2
    2 1
    3
4: 6
    1 1 1 1
    1 1 2
    1 2 1
    2 1 1
    3 1
    1 3
5: 15
    1 1 1 1 1
    1 1 1 2
    1 1 2 1
    1 2 1 1
    2 1 1 1
    1 1 3
    1 3 1
    3 1 1
    1 2 2
    2 1 2
    2 2 1
    2 3
    3 2
    1 4
    4 1

*/