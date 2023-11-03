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

const int maxN = 1e5 + 10;

int n;
vector <int> adj[maxN];

namespace submax{
    int dp[maxN][3];

    void dfs(int nu, int fa){
        dp[nu][0] = 1;
        dp[nu][1] = 0;
        dp[nu][2] = 0;

        for (auto i: adj[nu]){
            dfs(i,nu);
        }
        if (adj[nu].size()){
            int t1 = adj[nu].front();
            int t2 = adj[nu].back();
            if (adj[nu].size() == 2){
                dp[nu][0] = max(dp[t1][1] + dp[t2][2], dp[t1][2] + dp[t2][1]) + 1;
                dp[nu][1] = max(dp[t1][0] + dp[t2][2], dp[t1][2] + dp[t2][0]);
                dp[nu][2] = max(dp[t1][1] + dp[t2][0], dp[t1][0] + dp[t2][1]);
            }
            else{
                dp[nu][0] = max(dp[t1][1], dp[t1][2]) + 1;
                dp[nu][1] = max(dp[t1][0], dp[t1][2]);
                dp[nu][2] = max(dp[t1][1], dp[t1][0]);
            }
        }
    }
    void solve(){
        dfs(1,1);
        cout << max({dp[1][0], dp[1][1], dp[1][2]}) << " ";
    }
}

namespace submin{
    int dp[maxN][3];

    void dfs(int nu, int fa){
        dp[nu][0] = 1;
        dp[nu][1] = 0;
        dp[nu][2] = 0;

        for (auto i: adj[nu]){
            dfs(i,nu);
        }
        if (adj[nu].size()){
            int t1 = adj[nu].front();
            int t2 = adj[nu].back();
            if (adj[nu].size() == 2){
                dp[nu][0] = min(dp[t1][1] + dp[t2][2], dp[t1][2] + dp[t2][1]) + 1;
                dp[nu][1] = min(dp[t1][0] + dp[t2][2], dp[t1][2] + dp[t2][0]);
                dp[nu][2] = min(dp[t1][1] + dp[t2][0], dp[t1][0] + dp[t2][1]);
            }
            else{
                dp[nu][0] = min(dp[t1][1], dp[t1][2]) + 1;
                dp[nu][1] = min(dp[t1][0], dp[t1][2]);
                dp[nu][2] = min(dp[t1][1], dp[t1][0]);
            }
        }
    }
    void solve(){
        dfs(1,1);
        cout << min({dp[1][0], dp[1][1], dp[1][2]}) << " ";

    }
}

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
    string s;
    cin >> s;
    n = s.length();
    s = " " + s;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        if (i > 1){
            // cout << ls.back() << " " << i << endl;
            adj[ls.back()].push_back(i);
            ls.pop_back();
        }
        if (s[i] == '1'){
            ls.push_back(i);
        }
        else if (s[i] == '2'){
            ls.push_back(i);
            ls.push_back(i);
        }
    }

    submax::solve();
    submin::solve();
    
    return 0;
}

/*
1122002010
1 2
2 3
3 4
4 5
4 6
3 7
7 8
7 9
9 10
*/