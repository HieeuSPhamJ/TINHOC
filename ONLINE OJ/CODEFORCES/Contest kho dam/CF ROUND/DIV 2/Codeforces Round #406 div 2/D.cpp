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

int n, m, s;

vector <ii> adj[maxN * 10];
int vis[maxN * 10];
int i_id[maxN * 10];

struct da{
    vector <int> ls;
    void get(int i, int l, int r, int L, int R){
        if (r < L or R < l){
            return;
        }
        if (L <= l and r <= R){
            // cout << i << " " << l << ' ' << r << endl;
            ls.push_back(i);
            return;
        }
        int mid = (l + r) / 2;
        get(2 * i, l, mid, L, R);
        get(2 * i + 1, mid + 1, r, L, R);
    }
    void get(int l, int r){
        ls.clear();
        get(1, 1, n, l, r);
    }
} A,B;

int anti(int i){
    return i + 5e5;
}

void build(int i, int l, int r){
    // id_to_range[i] = {l,r};
    if (l == r){
        adj[i].push_back({0, anti(i)});
        adj[anti(i)].push_back({0, i});
        i_id[l] = i;
        return;
    }

    adj[i].push_back({0, 2 * i});
    adj[i].push_back({0, 2 * i + 1});
    adj[anti(2 * i)].push_back({0, anti(i)});
    adj[anti(2 * i + 1)].push_back({0, anti(i)});

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
}

void Dickcha(){
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for (int i = 1; i < maxN * 8; i++){
        vis[i] = 1e18;
    }
    vis[s] = 0;
    q.push({0,s});
    // int lim = 0;
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (vis[t.se] != t.fi){
            continue;
        }
        for (auto i: adj[t.se]){
            if (vis[i.se] > t.fi + i.fi){
                vis[i.se] = t.fi + i.fi;
                q.push({vis[i.se],i.se});
            }
        }
    }

    // while(!q.empty()){
    //     int u = q.top().second;
    //     int du = q.top().first;
    //     q.pop();
    //     if (du > vis[u]) continue;
    //     // cout << u << ": ";
    //     for(auto pt: adj[u]){
    //         int v = pt.se;
    //         int w = pt.fi;
    //         if (vis[v] > vis[u] + w){
    //             vis[v] = vis[u] + w;
    //             q.push({vis[v],v});
    //             // cout << v << " ";
    //         }
    //     }
    //     // cout << endl;
    // }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s;
    build(1,1,n);
    while(m--){
        int t, w;
        cin >> t;
        if (t == 1){
            int a, b;
            cin >> a >> b >> w;
            A.get(a,a);
            B.get(b,b);
            
        }
        else if (t == 2){
            int v, l, r;
            cin >> v >> l >> r >> w;
            A.get(v,v);
            B.get(l,r);
        }
        else{
            
            int v, l, r;
            cin >> v >> l >> r >> w;
            A.get(l,r);
            B.get(v,v);
        }
        // cout << "ADD" << endl;
        for (auto i: A.ls){
            for (int j: B.ls){
                if (i == j){
                    continue;
                }
                if (t == 3){
                    adj[anti(i)].push_back({w,anti(j)});
                    // cout << anti(i) << " " << anti(j) << " " << w << endl;
                }
                else{
                    adj[i].push_back({w,j});
                    // cout << i << " " << j << " " << w << endl;
                }
            }
        }
    }

    // A.get(2,3);
    // for (auto i: A.ls){
    //     cout << i << " ";
    // }
    // cout << endl;

    // int cnt = 0;C
    
    // for (int i = 1; i < 8 * maxN; i++){
    //     if (adj[i].size()){
    //         // cout << i << ": ";
    //         // for (auto j: adj[i]){
    //         //     cout << j.se << " ";
    //         // }
    //         // cout << endl;
    //         for (auto j: adj[i]){
    //             // if (max(i,j.se) % 100 > 10){
    //             //     continue;
    //             // }
    //             // cnt++;
    //             // cout << i << ' ' << j.se << " " << j.fi << endl;
    //         }
    //     }
    // }

    s = i_id[s];
    // if (n == 100000){
    //     // cout << cnt;
    //     return 0;
    // }
    Dickcha();

    
    for (int i = 1; i <= n; i++){
        int t = min(vis[i_id[i]], vis[anti(i_id[i])]);
        if (t == 1e18){
            t = -1;
        }
        cout << t << " ";
    }
    return 0;
}