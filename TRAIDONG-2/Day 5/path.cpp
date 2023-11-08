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

const int maxN = 50000 + 10;

vector <int> adj[maxN];
int dist[maxN];
bitset<maxN> pre[maxN];
int father[maxN][20];
vector <int> in[maxN];
int res[maxN];
int lg[maxN];

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
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist,-1,sizeof(dist));
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    pre[s][s] = 1;
    while (q.size()){
        int t = q.front();
        q.pop();
        in[dist[t]].push_back(t);
        for (auto i: adj[t]){
            if (dist[i] == -1){
                father[i][0] = t;
                pre[i][i] = 1;
                pre[i] = pre[i] | pre[t];
                dist[i] = dist[t] + 1;
                q.push(i);
                // cout << i << " " << t << endl;
            }
            else if (dist[i] == dist[t] + 1){
                pre[i] = pre[i] | pre[t];
                // cout << i << " " << t << endl;
            }
        }
    }

    // for (int i = 0; i <= n; i++){
    //     cout << layer[i] << endl;
    // }
    dist[0] = -1;
    for (int i = 1; i <= n; i++){
        lg[i] = log2(i);
    }
    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
            // cout << i << " " << j << " " << father[i][j] << endl;
        }
    }

    int test;
    cin >> test;
    vector <pair<ii,int>> ls;
    for (int tet = 1; tet <= test; tet++){
        int ta, d;
        cin >> ta >> d;
        ls.push_back({{d,ta},tet});
    }

    sort(all(ls));
    int la = -1;
    bitset<maxN> layer;
    layer[s] = 1;
    for (auto i: ls){
        int ta = i.fi.se;
        int d = i.fi.fi;
        while(la != d){
            la = d;
            layer = bitset<maxN>();
            for (auto i: in[d]){
                layer[i] = 1;
            }
        }
        if (dist[ta] < d){
            res[i.se] = 0;
            continue;
        }
        if (dist[ta] == d){
            res[i.se] = ta;
            continue;
        }
        auto mask = layer & pre[ta];
        if (mask.count() > 1){
            res[i.se] = -1;
            continue;
        }
        for (int i = lg[dist[ta]]; dist[ta] > d; i--){
            if (dist[father[ta][i]] >= d){
                // cout << ta << " " << i << " " << father[ta][i] << endl;
                ta = father[ta][i];
            }
        }
        res[i.se] = ta;
    }

    for (int i = 1; i <= test; i++){
        cout << res[i] << endl;
    }
    return 0;
}