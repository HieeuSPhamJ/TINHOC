#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

vector <int> adj[maxN];
int dp[maxN];

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[nu] += dp[i];
    }
    if (dp[nu] == 0){
        dp[nu] = 1;
    }
    // cout << nu << ": " << dp[nu] << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1,1);
    vector <int> res;
    for (int i = 1; i <= n; i++){
        res.push_back(dp[i]);
    }
    sort(all(res));
    for (auto i: res){
        cout << i << " ";
    }
    return 0;
}