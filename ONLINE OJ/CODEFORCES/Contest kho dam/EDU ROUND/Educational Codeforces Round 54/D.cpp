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

int n, m, k;
map <ii,int> id;
vector <ii> adj[maxN];
int vis[maxN];
int path[maxN];

void dickcha(){
    for (int i = 1; i < maxN; i++){
        vis[i] = 1e18;
    }
    priority_queue <ii,vector <ii>, greater <ii>> q;
    q.push({0,1});
    vis[1] = 0;
    while(!q.empty()){
        ii t = q.top();
        q.pop();
        if (t.fi != vis[t.se]){
            continue;
        }
        for (auto i: adj[t.se]){
            if (vis[i.se] > t.fi + i.fi){
                vis[i.se] = t.fi + i.fi;
                path[i.se] = t.se;
                q.push({vis[i.se], i.se});
            }
        }
    }
}

vector <int> ans;

void dfs(int nu, int fa){
    if (nu != fa){
        ans.push_back(id[{nu,fa}]);
    }
    for (auto i: adj[nu]){
        if (i.se == fa){
            continue;
        }
        dfs(i.se, nu);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        id[{a,b}] = i;
        id[{b,a}] = i;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    dickcha();
    
    for (int i = 1; i <= n; i++){
        adj[i].clear();
    }

    for (int i = 2; i <= n; i++){
        adj[i].push_back({1,path[i]});
        adj[path[i]].push_back({1,i});
        // cout << i << " " << path[i] << endl;
    }
    dfs(1,1);
    k = min(k, (int)ans.size());
    cout << k << endl;
    for (int i = 0; i < k; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}