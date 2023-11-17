#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

vector <int> adj[maxN];
int vis[maxN];

signed main(){
    freopen("route.INP", "r", stdin);
    freopen("route.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    queue <int> q;
    for (int i = 1; i <= s; i++){
        int x;
        cin >> x;
        q.push(x);
        vis[x] = 1;
    }
    vector <int> res;
    for (int i = 1; i <= t; i++){
        int x;
        cin >> x;
        res.push_back(x);
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            if (vis[i] == 0){
                vis[i] = vis[t] + 1;
                q.push(i);
            }
        }
    }

    for (auto i: res){
        cout << vis[i] - 1 << " ";
    }

    return 0;
}