#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#define pq priority_queue <ii>

const int maxN = 1e5 + 10;

int a[15][15];
int dp[maxN];

pq q[11];

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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        a[y][x]++;
    }
    int res = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int c = 1; c <= 10; c++){
        for (int e = 1; e <= 10; e++){
            int turn = a[c][e];
            if (turn == 0){
                continue;
            }
            // cout << c << " " << e << ": " << turn << endl;
            for (int i = 0; i <= c; i++){
                while(q[i].size()){
                    q[i].pop();
                }
            }
            for (int i = 0, cur = 0; i <= k; i++){
                pq &tq = q[i % c];
                while(tq.size() and tq.top().se < i){
                    tq.pop();
                }
                int old_dp = dp[i];
                if (tq.size()){
                    dp[i] = max(dp[i], tq.top().fi + cur);
                }
                if (old_dp != -1){
                    // cout << "add: " << i % c << " " << old_dp - cur << " " << i + turn * c << endl;
                    tq.push({old_dp - cur, i + turn * c});
                }
                res = max(res, dp[i]);
                if (i % c == 0){
                    cur += e;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}

/*
f[i]: max val with cost i
f[i]

g[i] -> f[i + k*c] = g[i] + k*e

f[i] = g[i - k*c] + k*e

i % k == (i - k*c) % k
*/