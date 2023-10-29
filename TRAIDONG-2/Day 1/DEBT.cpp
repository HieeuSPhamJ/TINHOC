#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 110;

int a[maxN];
int dp[maxN][10010];
int cur[maxN][10010];
vector <ii> adj[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DEBT.inp", "r")) {
        freopen("DEBT.inp", "r", stdin);
        freopen("DEBT.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> ls;
    ls.push_back(0);
    for (int i = 1; i <= n; i++){
        if (i < l or r < i){
            ls.push_back(i);
        }
    }
    for (int i = l; i <= r; i++){
        for (auto j: ls){
            if (a[i] - a[j] > 0){
                // ls.push_back({{i,j}, a[i] - a[j]});
                // cout << i << " " << j << " " << a[i] - a[j] << endl;
                adj[i].push_back({j,a[i] - a[j]});
            }
            
        }
    }

    // cout << "===" << endl;
    // sort(all(ls));
    int res = 0;
    for (int i = l; i <= r; i++){
        for (auto j: ls){
            for (int g = 0; g < k; g++){
                cur[j][g] = dp[j][g];
                dp[j][g] = 0;
            }
        }
        for (auto j: ls){
            for (int g = 0; g < k; g++){
                // cout << i - 1 << " " << j << " " << g << " " << cur[j][g] << endl; 
                dp[j][g] = max(dp[j][g], cur[j][g]);
                for (auto nj: adj[i]){
                    int ng = abs(i - nj.fi) + g;
                    if (j < nj.fi and ng <= k){
                        dp[nj.fi][ng] = max(dp[nj.fi][ng], cur[j][g] + nj.se);
                        res = max(res, dp[nj.fi][ng]);
                        // cout << " =>" << i << " " << nj.fi << " " << ng << " " << dp[nj.fi][ng] << endl;
                    }
                }
            }
        }
    }
    bru:;
    res = -res;

    for (int i = l; i <= r; i++){
        res += a[i];
    }

    cout << res << endl;
    // for (auto i: ls){
    //     cout << i.fi << " " << i.se.fi << " " << i.se.se << endl;
    // }

    return 0;
}

/*
dp[i][j][k]
-> dp[i + 1][nj][k + abs(i + 1 - nj)];


4 5 3 1 2 6

3

4 0 4
4 1 3
4 2 2
4 3 1
5 0 5
5 1 4
5 2 3
5 3 2
6 0 6
6 1 5
6 2 4
6 3 3



*/