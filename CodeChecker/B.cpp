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

const int maxN = 1e5 + 10;

vector <ii> adj[maxN];
int v[maxN];
int p[maxN];
int dep[maxN];
int isdea[maxN];

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i.se == fa){
            continue;
        }
        p[i.se] = nu;
        v[i.se] = i.fi;
        dep[i.se] = dep[nu] + 1;
        dfs(i.se,nu);
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
        
    }
    dfs(1,1);
    while(test--){
        int t;
        cin >> t;
        // for (int i = 1; i <= n; i++){
        //     cout << v[i] << " ";
        // }
        // cout << endl; 
        if (t == 2){
            int x;
            cin >> x;
            isdea[x] = -1;
        }
        else{
            int a, b;
            cin >> a >> b;
            if (dep[a] < dep[b]){
                swap(a,b);
            }
            int res = 1e18;
            while(dep[a] != dep[b]){
                res = min({res, v[a]});
                // cout << "!" << a << " " << b << " " << v[a] << " " << v[b] << " " << res << endl;
                if (isdea[a] == -1){
                    res = -1;
                }
                a = p[a];
            }
            while(a != b){
                res = min({res, v[a], v[b]});
                // cout << "@" << a << " " << b << " " << v[a] << " " << v[b] << " " << res << endl;
                if (isdea[a] == -1){
                    res = -1;
                }
                if (isdea[b] == -1){
                    res = -1;
                }
                a = p[a];
                b = p[b];
            }
            if (res == 1e18){
                res = 0;
            }
            if (isdea[a] == -1){
                res = -1;
            }
            cout << res << endl;
        }
    }
    return 0;
}