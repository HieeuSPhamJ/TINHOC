#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;
const int inf = 1e18;

int n, m;
vector <ii> adj[maxN];
int vis[maxN];
int dist[maxN][maxN];
vector <ii> ls;

void dickcha(int s){
    for (int i = 1; i <= n; i++){
        vis[i] = inf;
    }
    priority_queue <ii,vector <ii>, greater <ii>> q;
    vis[s] = 0;
    q.push({0,s});
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (t.fi != vis[t.se]){
            continue;
        }
        for (auto i: adj[t.se]){
            if (vis[i.se] > t.fi + i.fi){
                vis[i.se] = t.fi + i.fi;
                q.push({vis[i.se], i.se});
            }
        }
    }
}

void sub12(){
    for (int i = 1; i <= n; i++){
        dickcha(i);
        for (int j = 1; j <= n; j++){
            dist[i][j] = min(dist[i][j], vis[j]);
            dist[j][i] = min(dist[j][i], vis[j]);
        }
    }
    ii res = {1e18,-1};
    for (int id = 0; id < ls.size(); id++){
        ii e = ls[id];
        int tres = 0;
        for (int i = 1; i <= n; i++){
            tres = max(tres, min(dist[i][e.fi], dist[i][e.se]));
        }
        if (tres < res.fi){    
            res.fi = tres;
            res.se = id + 1;
        }
    }
    cout << res.se << " " << res.fi << endl;
}

int mk[maxN];

void subfi(){
    dickcha(1);
    int ma = 0;
    for (int i = 1; i <= n; i++){
        if (vis[ma] < vis[i]){
            ma = i;
        }
    }
    dickcha(ma);
    // cout << ma << endl;
    ma = 0;
    for (int i = 1; i <= n; i++){
        if (vis[ma] < vis[i]){
            ma = i;
        }
    }
    // cout << ma << endl;
    vector <int> st;
    queue <int> q;
    q.push(ma);
    while(q.size()){
        int t = q.front();
        q.pop();
        st.push_back(t);
        for (auto i: adj[t]){
            if (mk[i.se] == 0 and vis[i.se] + i.fi == vis[t]){
                q.push(i.se);
                mk[i.se] = 1;
            }
        }
    }

    for (auto i: st){
        dickcha(i);
        for (int j = 1; j <= n; j++){
            dist[i][j] = min(dist[i][j], vis[j]);
            dist[j][i] = min(dist[j][i], vis[j]);
        }
    }

    // for (auto i: st){
    //     cout << i << " ";
    // }
    // cout << endl;

    ii res = {1e18,-1};
    for (int id = 0; id < ls.size(); id++){
        ii e = ls[id];
        // cout << id << ": " << endl; 
        int tres = 0;
        for (auto i: st){
            // cout << i << " " << min(dist[i][e.fi], dist[i][e.se]) << endl;
            // if (e.fi != i and e.se != i){
                tres = max(tres, min(dist[i][e.fi], dist[i][e.se]));
            // }
        }
        if (tres < res.fi){    
            res.fi = tres;
            res.se = id + 1;
        }
    }
    cout << res.se << " " << res.fi << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        ls.push_back({a,b});
    }
    if (n == 2){
        cout << 1 << " " << 0 << endl;
    }
    for (int i = 1; i <= n; i++){   
        for (int j = 1; j <= n; j++){
            dist[i][j] = inf;
        }
    }
    if (n * m * log2(n + m) <= 4e7){
        sub12();
    }
    else{
        subfi();
    }
    return 0;
}