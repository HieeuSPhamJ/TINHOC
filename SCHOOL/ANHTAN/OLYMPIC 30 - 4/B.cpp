#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int vis[3][maxN];
int cntVis[3][maxN];
vector <ii> adj[maxN];

void Dickcha(int type, int Start){
    // cout << "With: " << type << endl;
    for (int i = 0; i < maxN; i++){
        vis[type][i] = inf;
    }
    priority_queue <ii, vector <ii>, greater <ii>> q;
    q.push({0, Start});
    vis[type][Start] = 0;
    cntVis[type][Start] = 1;
    while(!q.empty()){
        ii t = q.top();
        q.pop(); 
        if (t.fi != vis[type][t.se]){
            continue;
        }
        // cout << t.se << ": " << endl;
        for (auto nu: adj[t.se]){
            if (vis[type][t.se] + nu.fi < vis[type][nu.se]){
                vis[type][nu.se] = vis[type][t.se] + nu.fi;
                cntVis[type][nu.se] = cntVis[type][t.se] % mod;
                q.push({vis[type][nu.se], nu.se});
                // cout << nu.se << " ";
            }
            else if (vis[type][t.se] + nu.fi == vis[type][nu.se]){
                (cntVis[type][nu.se] += cntVis[type][t.se]) %= mod;
                // cout << nu.se << "+ ";
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <pair <int, ii>> lists;
    for (int i = 1; i <= m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t,b});
        adj[b].push_back({t,a});
        lists.push_back({t,{a,b}});
    }
    Dickcha(0,1);
    Dickcha(1,n);
    int ans = 0;
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << cntVis[0][i] << " " << cntVis[1][i] << endl;
    // }
    for (auto i: lists){
        int w = i.fi;
        int a = i.se.fi;
        int b = i.se.se;
        // if (vis[0][a] + vis[1][b] + w == vis[0][n]){
        //     cout << a << " " << b << ": " << cntVis[0][a] * cntVis[1][b] % mod << " " << cntVis[0][n] % mod << endl;
        // }
        if ((vis[0][a] + vis[1][b] + w == vis[0][n]
            and cntVis[0][a] * cntVis[1][b] % mod == cntVis[0][n] % mod)
            or (vis[1][a] + vis[0][b] + w == vis[0][n]
            and cntVis[1][a] * cntVis[0][b] % mod == cntVis[0][n] % mod)){
                // cout << a << " " << b << endl;
                ans++;
            }
    }
    cout << ans << endl;
    
    return 0;
}