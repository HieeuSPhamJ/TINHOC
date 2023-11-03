#include<bits/stdc++.h>
#define int long long
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
bitset<maxN> layer[maxN];
int father[maxN][20];

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
        layer[dist[t]][t] = 1;
        for (auto i: adj[t]){
            if (dist[i] == -1){
                father[i][0] = t;
                pre[i][i] = 1;
                pre[i] = pre[i] | pre[t];
                dist[i] = dist[t] + 1;
                q.push(i);
            }
            else if (dist[i] == dist[t] + 1){
                pre[i] = pre[i] | pre[t];
            }
        }
    }

    // for (int i = 0; i <= n; i++){
    //     cout << layer[i] << endl;
    // }

    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }

    int test;
    cin >> test;
    while(test--){
        int ta, d;
        cin >> ta >> d;
        if (dist[ta] < d){
            cout << 0 << endl;
            continue;
        }
        if (dist[ta] == d){
            cout << ta << endl;
            continue;
        }
        auto mask = layer[d] & pre[ta];
        if (mask.count() > 1){
            cout << -1 << endl;
            continue;
        }
        for (int i = 20; dist[ta] > d; i--){
            if (dist[father[ta][i]] >= d){
                ta = father[ta][i];
            }
        }
        cout << ta << endl;
    }
    return 0;
}