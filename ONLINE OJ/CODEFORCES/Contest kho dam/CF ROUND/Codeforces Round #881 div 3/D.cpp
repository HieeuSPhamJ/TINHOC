#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int sz[maxN];
vector <int> adj[maxN];

void dfs(int n, int f){
    // cout << n << endl;
    int ok = 1;
    for (auto i: adj[n]){
        if (i == f){
            continue;
        }
        dfs(i,n);
        ok = 0;
        sz[n] += sz[i];
    }
    sz[n] += ok;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            sz[i] = 0;
            adj[i].clear();
        }
        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,1);
        // cout << "TEST" << endl;
        int t;
        cin >> t;
        while(t--){
            int a, b;
            cin >> a >> b;
            // cout << sz[a] << " " << sz[b] << endl;
            cout << sz[a] * sz[b] << endl;
        }
    }
    return 0;
}