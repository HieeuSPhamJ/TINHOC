#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 4e5 + 10;

vector <int> adj[maxN];
int num[maxN];
int low[maxN];
int cnt;
vector <int> ln;
int dp[maxN];

void tarjan(int nu){
    cnt++;
    low[nu] = num[nu] = cnt;
    ln.push_back(nu);
    for (auto i: adj[nu]){
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
            continue;
        }
        tarjan(i);
        low[nu] = min(low[nu], num[i]);
    }

    if (low[nu] == num[nu]){
        int CNT = 1;
        while(ln.back() != nu){
            int t = ln.back();
            ln.pop_back();
            low[t] = num[t] = 1e8;
            dp[t] = -1;
            CNT++;
        }
        int t = ln.back();
        ln.pop_back();
        low[t] = num[t] = 1e8;
        if (CNT == 1){
            dp[nu] = 0;
        }
    }
}

int dfs(int nu){
    if (dp[nu] == -1){
        return dp[nu];
    }
    if (dp[nu] != 0){
        return dp[nu];
    }
    for (auto i: adj[nu]){
        int t = dfs(i);
        if (t == -1){
            dp[nu] = -1;
            return -1;
        }
        dp[nu] = max(dp[nu], t + 1);
    }
    return dp[nu];
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1){
            a += n;
        }
        else{
            b += n;
        }
        adj[a].push_back(b);
        // cout << a << " " << b << endl;
    }   
    int base = n;
    n = n + n;
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i);
        }
    }

    for (int i = 1; i <= base; i++){
        int t1 = dfs(i);
        int t2 = dfs(i + base);
        if (min(t1,t2) == -1){
            cout << -1 << endl;
        }
        else{
            cout << max(t1,t2) << endl;
        }
    }
    return 0;

}