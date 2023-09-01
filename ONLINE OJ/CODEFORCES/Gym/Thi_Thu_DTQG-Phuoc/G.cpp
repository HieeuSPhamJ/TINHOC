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

int male[maxN];
int upmale[maxN];
int lvl[maxN];
vector <int> adj[maxN];

void getmale(int nu, int fa){
    male[nu] = 1;
    for (auto i: adj[nu]){
        if (fa == i){
            continue;
        }
        lvl[i] = lvl[nu] + 1; 
        getmale(i, nu);
        male[nu] = max(male[nu], male[i] + 1);
    }
}

void getupmale(int nu, int fa){
    upmale[nu] = max(1ll, upmale[fa] + 1);
    // cout << "With: " << nu << endl;
    if (nu != fa){
        for (auto i: adj[fa]){
            if (i == nu or lvl[i] < lvl[fa]){
                continue;
            }
            // cout << i << " " <<  male[i] + 2 << endl;
            upmale[nu] = max(upmale[nu], male[i] + 2);
        }
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        getupmale(i,nu);
    }
}

int res = 1e18;
int dp[maxN];

void dfs(int nu, int fa){
    // cout << "With: " << nu << " " << dp[nu] << endl;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dp[i] = dp[nu] + male[i] * (upmale[i] - 1);
        dfs(i, nu);
    }
    if (adj[nu].size() == 1 and nu != fa){
        res = min(res, dp[nu]);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    getmale(1,1);
    getupmale(1,1);

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << lvl[i] << " " << male[i] << " " << upmale[i] << endl;
    // }

    dfs(1,1);

    cout << res << endl;
    return 0;
}