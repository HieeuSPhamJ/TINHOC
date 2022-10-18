#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int n, k;
vector <int> adj[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        adj[i].push_back(inp);
        adj[inp].push_back(i);
    }

    DFS(1,1);

    cout << dp[1];
    
    return 0;
}