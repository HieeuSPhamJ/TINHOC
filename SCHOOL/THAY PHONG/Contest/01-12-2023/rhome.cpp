#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int n, m;
pair<ii,int> node[maxN];
vector <ii> adj[maxN];
int dist[maxN];
priority_queue<ii,vector <ii>, greater <ii>> q;



void add(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
}

int costmin(int a, int b){
    return min(abs(node[a].fi.fi - node[b].fi.fi), abs(node[a].fi.se - node[b].fi.se));
    return abs(node[a].fi.fi - node[b].fi.fi) + abs(node[a].fi.se - node[b].fi.se);
}
int cost(int a, int b){
    return abs(node[a].fi.fi - node[b].fi.fi) + abs(node[a].fi.se - node[b].fi.se);
}

bool cmp(pair<ii,int> a, pair<ii,int> b){
    return a.fi.se < b.fi.se;
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
    cin >> m >> n;
    int s = 0;
    int t = n + 1;
    cin >> node[s].fi.fi >> node[s].fi.se;
    cin >> node[t].fi.fi >> node[t].fi.se;
    for (int i = 1; i <= n; i++){
        cin >> node[i].fi.fi >> node[i].fi.se;
        node[i].se = i;
    }
    sort(node + 1, node + 1 + n);
    for (int i = 2; i <= n; i++){
        add(node[i].se, node[i - 1].se, costmin(i, i - 1));
    }
    sort(node + 1, node + 1 + n, cmp);
    for (int i = 2; i <= n; i++){
        add(node[i].se, node[i - 1].se, (i, i - 1));
    }
    for (int i = 1; i <= n; i++){
        add(node[i].se, s, costmin(i, s)); 
        add(node[i].se, t, costmin(i, t)); 
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({0,s});
    while(q.size()){
        ii nu = q.top();
        q.pop();
        if (nu.fi != dist[nu.se]){
            continue;
        }
        for (auto i: adj[nu.se]){
            if (dist[i.se] > nu.fi + i.fi){
                dist[i.se] = nu.fi + i.fi;
                q.push({dist[i.se], i.se});
            }
        }
    }
    cout << dist[t];
    return 0;
}

/*
o.ooo
ooooo
oo.oo
.oooo
ooooo

ooooo
ooooo
.ooo.
ooooo
ooooo

s 1
s 2
1 3
2 3
3 1'
3 2'
1' t
2' t

*/