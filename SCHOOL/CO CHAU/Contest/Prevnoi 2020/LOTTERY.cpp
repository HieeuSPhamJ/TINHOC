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

const int maxN = 1e5 + 10;

int n;


namespace sub1{
    
    int m;
    vector <int> adj[maxN];
    int vis[maxN];

    int dfs(int nu, int t){
        vis[nu] = 1;

        if (t == 1){
            vis[nu] = 0;
            // cout << nu << " " << t << " " << 1 << endl;
            return 1;
        }
        int res = 0;
        for (auto i: adj[nu]){
            if (vis[i] == 0){
                res += dfs(i, t - 1);
            }
        }
        vis[nu] = 0;
            // cout << nu << " " << t << " " << res << endl;
        return res;
    }

    void solve(){
        cin >> m;
        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int t = 1; t <= n; t++){
            int res = 0;
            for (int i = 1; i <= n; i++){
                // cout << "With: " << i << " " << t << endl;
                res += dfs(i,t);
            }
            cout << res << " ";
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("lottery.inp", "r")) {
        freopen("lottery.inp", "r", stdin);
        freopen("lottery.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    sub1::solve();
    return 0;
}