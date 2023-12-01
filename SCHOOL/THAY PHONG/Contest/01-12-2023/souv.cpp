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

const int maxN = 1e4 + 10;

vector <ii> adj[maxN];
int dist[110][maxN];
priority_queue<ii,vector <ii>, greater <ii>> q;
int c[maxN];

void dickcha(int t, ii st){
    dist[t][st.se] = st.fi;
    q.push(st);
    while(q.size()){
        ii nu = q.top();
        q.pop();
        if (nu.fi != dist[t][nu.se]){
            continue;
        }
        for (auto i: adj[nu.se]){
            if (dist[t][i.se] > nu.fi + i.fi){
                dist[t][i.se] = nu.fi + i.fi;
                q.push({dist[t][i.se], i.se});
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
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= k; i++){
        int nu;
        cin >> nu >> c[i];
        dickcha(i,{0,nu});
    }
    while(p--){
        int a, b;
        cin >> a >> b;
        int res = 1e18;
        for (int i = 1; i <= k; i++){
            res = min(res, dist[i][a] + dist[i][b] + c[i]);
        }
        if (res == 1e18){
            cout << -1 << endl;
            continue;
        }
        cout << res << endl;
    }
    return 0;
}