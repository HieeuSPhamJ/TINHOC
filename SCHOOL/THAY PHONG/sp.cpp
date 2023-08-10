#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

set <int> adj[maxN];
vector <ii> oldAdj[maxN];
vector <int> ls;
vector <pair<int,ii>> lse;
bool mk[maxN];
int rt[maxN];
int vis[maxN];
int n, m, k;

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int makegraph(){
    for (auto i: lse){
        int a = i.se.fi;
        int b = i.se.se;
        int w = i.fi;
        int u = find(a);
        int v = find(b);
        if (u == v){
            continue;
        }
        if (mk[u] == mk[v] and mk[u] == 0){
            rt[u] = v;
            // cout << a << " " << b << endl;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << rt[i] << endl; 
    // }
    for (auto i: lse){
        int a = i.se.fi;
        int b = i.se.se;
        int w = i.fi;
        int u = find(a);
        int v = find(b);
        if (u == v){
            continue;
        }
        cout << u << " " << v << endl;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int type = 2;
    for (int i = 1; i <= n; i++){
        if (adj[i].size() > 2){
            return 0;
        }
        if (adj[i].size() == 1){
            type = 1;
            // cout << i << endl;
        }
    }

    queue <int> q;
    q.push(find(1));
    vis[find(1)] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            if (vis[i] == 0){
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    for (auto i: ls){
        if (vis[i] == 0){
            return 0;
        }
    }
    return type;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        mk[x] = 1;
    }

    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }

    for (int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        lse.push_back({w,{x,y}});
        oldAdj[x].push_back({w,y});
        oldAdj[y].push_back({w,x});
    }

    int type = makegraph();

    if (type == 0){
        cout << 0 << endl;
        return 0;
    }

    cout << type << endl;

    if (type == 1){

    }

    return 0;
}