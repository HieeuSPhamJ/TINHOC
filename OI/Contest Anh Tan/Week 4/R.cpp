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

const int maxN = 1e5 + 10;
const int inf = 1e9 + 7;

int n, m, k;
int gap;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN];
int num[maxN];
int low[maxN];
int cnt;
stack <int> ln;

void tarjan(int nu){
    ln.push(nu);
    num[nu] = low[nu] = ++cnt;
    for (auto i: adj[nu]){
        if (a[i] > gap){
            continue;
        }
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
        }
        else{
            tarjan(i);
            low[nu] = min(low[nu], low[i]);
        }
    }
    if (num[nu] == low[nu]){
        int Count = 1;
        while(ln.top() != nu){
            low[ln.top()] = num[ln.top()] = 1e18;
            Count++;
            dp[ln.top()] = inf;
            ln.pop();
        }
        low[ln.top()] = num[ln.top()] = 1e18;
        if (Count > 1){
            dp[ln.top()] = inf;
        }
        ln.pop();
    }
}

int dfs(int nu){
    if (a[nu] > gap){
        return 0;
    }
    if (dp[nu] != 0){
        return dp[nu];
    }
    dp[nu] = 1;
    for (auto i: adj[nu]){
        if (a[nu] > gap){
            continue;
        }
        if (i == nu){
            dp[nu] = inf;
            return dp[nu];
        }
        dp[nu] = max(dp[nu], dfs(i) + 1);
    }
    // cout << nu << ": " << dp[nu] << endl;
    return dp[nu];
}

bool check(){
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        low[i] = 0;
        num[i] = 0;
    }
    cnt = 0;
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (num[i] == 0 and a[i] <= gap){
            tarjan(i);
        }
    }
    // cout << gap << ": " << endl;
    for (int i = 1; i <= n; i++){
        if (a[i] > gap){
            continue;
        }
        // cout << "With " << i << ": " << endl;
        res = max(res, dfs(i)); 
    }
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return res >= k;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int res = 0;
    int l = 0;
    int r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        gap = mid;
            // cout << mid << endl;
        if (check()){
            r = mid - 1;
            res = mid;
        }
        else{
            l = mid + 1;
        }
    }
    // gap = 2;
    // cout << check() << endl;
    cout << res << endl;
    return 0;
}