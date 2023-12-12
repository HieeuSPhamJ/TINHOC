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

const int maxN = 1e3 + 10;

vector <ii> adj[maxN];
bitset <2048> vis[maxN];

void dickcha(int s){
    queue <ii> q;
    q.push({0,s});
    vis[s][0] = 1;
    while(q.size()){
        ii t = q.front();
        q.pop();
        // cout << t.se << " " << t.fi << endl;
        for (auto i: adj[t.se]){
            if (vis[i.se][i.fi | t.fi] == 0){
                vis[i.se][i.fi | t.fi] = 1;
                q.push({i.fi | t.fi, i.se});
            }
        }
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    int s, t;
    cin >> s >> t;
    dickcha(s);
    for (int i = 0; i < (1 << 11); i++){
        if (vis[t][i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}