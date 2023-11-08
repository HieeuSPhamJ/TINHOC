#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ii4 pair <ii,ii>
using namespace std;

const int maxN = 3e5 + 10;

int n, k;
vector <int> adj[maxN];
int a[maxN];
ii dp[2][maxN];

void dfs(int nu, int fa){
    dp[0][nu] = {-1,-1};
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        if (dp[0][nu].se <= dp[0][i].se - 1){
            if (dp[0][nu].se == dp[0][i].se - 1){
                dp[0][nu].fi = i;
            }
            else{
                dp[0][nu] = dp[0][i];
                dp[0][nu].se--;
            }
        }
        if (dp[0][nu].se <= a[i] - 1){
            if (dp[0][nu].se == a[i] - 1){
                dp[0][nu].fi = i;
            }
            else{
                dp[0][nu] = {i, a[i] - 1};
            }
        }
    }
}

ii4 dps[maxN];

void reroot(int nu, int fa){

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
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,1);
    cout << dp[0][1].fi << " " << dp[0][1].se << endl;
    reroot(1,1);
    return 0;
}