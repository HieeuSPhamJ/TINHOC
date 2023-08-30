#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int n;
int a[maxN];
vector <ii> adj[maxN];
int vis[maxN];
map <ii,bool> isNear;

void dickcha(int s, int t){
    if (isNear[{s,t}]){
        vis[t] = 1;
        return;
    }
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for (int i = 1; i <= 26; i++){
        vis[i + n] = 1e18;
    }
    q.push({1,a[s]});
    vis[s] = 0;
    vis[t] = 1e18;
    while(!q.empty()){
        ii t = q.top();
        q.pop();
        if (vis[t.se] != t.fi){
            continue;
        }
        for (auto i: adj[t.se]){
            if (t.fi + i.fi < vis[i.se]){
                vis[i.se] = t.fi + i.fi;
                q.push({vis[i.se], i.se});
            }
        }
        
    }

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - 'a' + 1 + n;
    }

    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[a[x]].push_back({1,a[y]});
        adj[a[y]].push_back({1,a[x]});
        isNear[{x,y}] = 1;
        isNear[{y,x}] = 1;
        isNear[{x,a[y]}] = 1;
        isNear[{y,a[x]}] = 1;
    }

    for (int i = 1; i <= n + 26; i++){
        adj[i].resize(distance(adj[i].begin(),unique(all(adj[i]))));
    }
    // for (int i = 1; i <= n + 26; i++){
    //     for (auto x: adj[i]){
    //         cout << i << " " << x.se << " " << x.fi << endl;
    //     }
    // }

    int test;
    cin >> test;
    while(test--){
        int u, v;
        cin >> u >> v;
        dickcha(u,v);
        cout << vis[v] << endl;
    }
    
    return 0;
}

/*
acecdbadzbc
abcabcabaac
*/