#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e3 + 10;

int a[maxN];
int dp[maxN][maxN];
int ans[maxN];
vector <int> adj[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i - a[j] >= 0){
                int res = ans[i - a[j]];
                for (auto x: adj[j]){
                    (res = res - dp[i - a[j]][x] + mod) %= mod;
                }   
                (dp[i][j] = res) %= mod;
                (ans[i] += res + mod) %= mod;
            }
        }
    }

    cout << ans[n];

    return 0;
}