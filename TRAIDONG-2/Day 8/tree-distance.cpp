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

const int maxN = 3e5 + 10;

int n, k;
vector <int> adj[maxN];
deque <int> dp[maxN];
long long res = 0;

void dfs(int nu, int fa){
    // cout << "nu " << nu << endl;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        if (dp[nu].size() < dp[i].size()){
            swap(dp[nu], dp[i]);
        }
        // cout << "add " << i << " to " << nu << endl;
        // for (auto x: dp[i]){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x: dp[nu]){
        //     cout << x << " ";
        // }
        // cout << endl;
        for (int x = 1; x <= (int)dp[i].size(); x++){
            if (k - x - 1 < 0){
                break;
            }
            // cout << nu << ' ' << i << ": " << dp[i][x - 1] << endl;
            if (k - x - 1 < (int)dp[nu].size()){
                res += (long long)dp[i][x - 1] * (long long)dp[nu][k - x - 1];
            }
        }
        for (int x = 0; x < (int)dp[i].size(); x++){
            dp[nu][x] += dp[i][x];
        }
        dp[i].clear();
    }   

    dp[nu].push_front(1);
    if ((int)dp[nu].size() > k){
        res += dp[nu][k];
        dp[nu].pop_back();
    }
    // cout << "With: " << nu << endl;
    // for (auto i: dp[nu]){
    //     cout << i << " ";
    // }
    // cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("tree-distance.inp", "r")) {
        freopen("tree-distance.inp", "r", stdin);
        freopen("tree-distance.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if (n == 2){
        cin >> n >> k;
        cout << n - k << endl;
        return 0;
    }
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    cout << res << endl;
    return 0;
}