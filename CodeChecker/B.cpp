#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

vector <int> adj[10000];
int vis;
int dp[1000];

void bfs(int nu, int fa){
    vis++;
    dp[nu] = 1;
    vector <int> ls;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        bfs(i,nu);
        dp[nu] = max(dp[nu], dp[i] + 1);
        ls.push_back(dp[i]);
    }
    if (ls.size() == 1){
        if (ls.front() != 1){
            vis = 1e18;
        }
    }
    if (ls.size() == 2){
        if (abs(ls.back() - ls.front()) > 1){
            vis = 1e18;
        }
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
    }
    int ans = 1e18;
    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 1; i <= n; i++){
            adj[i].clear();
        }
        for (auto i: ls){
            int a = i.fi - 1;
            int b = i.se - 1;
            if ((mask & (1 << a)) == 0 and (mask & (1 << b)) == 0){
                adj[a + 1].push_back(b + 1);
                adj[b + 1].push_back(a + 1);
                // cout << a + 1 << ' ' << b + 1 << endl;
            }
        }
        // for (int i = 0; i < n; i++){
        //     cout << ((mask & (1 << i)) != 0);
        // }
        // cout << endl;
        vis = 0;
        int tres = (int)__builtin_popcount(mask);
        bfs(1,1);
        // cout << vis << " " << tres << endl;
        if (vis == n - tres){
            ans = min(ans, tres);
        }
    }

    cout << ans << endl;
    return 0;
}

/*
123456789012
000110000100
*/