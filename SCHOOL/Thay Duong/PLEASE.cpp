#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;

struct node{
    int had = 0;
    int cap = 0;
    int to = 0;
    int rev = 0;
};

int n, m, s, t;
vector <node> adj[maxN];
int vis[maxN];

void add(int a, int b, int val){
    node u,v;
    u.cap = val;
    u.had = 0;
    u.to = b;
    u.rev = adj[b].size();
    v.cap = 0;
    v.had = 0;
    v.to = a;
    v.rev = adj[a].size();
    adj[a].push_back(u);
    adj[b].push_back(v);
}

bool check(){
    for (int i = 1; i <= n; i++){
        vis[i] = -1;
    }
    queue <int> q;
    q.push(s);
    vis[s] = 0;
    // int lim = 0;
    while(!q.empty()){
        int te = q.front();
        q.pop();
        for (auto nu: adj[te]){
            if (vis[nu.to] == -1 and nu.cap - nu.had > 0){
                vis[nu.to] = vis[te] + 1;
                q.push(nu.to);
            }
        }
        cout << endl;
        // lim++;
    }
    return vis[t] != -1;
}

int Try(int node, int Min){
    if (node == t){
        return Min;
    }
    for (auto &nu: adj[node]){
        if (vis[nu.to] - 1 == vis[node] and nu.cap - nu.had > 0){
            int tMin = min(Min, nu.cap - nu.had);
            tMin = min(tMin, Try(nu.to,tMin));
            if (tMin != 0){
                // cout << node << " -> " << nu.to << endl;
                nu.had += tMin;
                adj[nu.to][nu.rev].had -= tMin;
                return tMin;
            }
        }
    }
    return 0;
}

int dinic(){
    int res = 0;
    while(check()){
        res += Try(s,1e18);
    }
    // check();
    // for (int i = 1; i <= n; i++){
    //     cout << i << " " << vis[i] << endl;
    // }
    // cout << "===" << endl;
    // cout << Try(s,1e18) << endl;
    return res;
}

map <int,int> edges[2];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> ls;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        if (x < 0){
            for (int i = 100)
        }
    }



    
    return 0;
}