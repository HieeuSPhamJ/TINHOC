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
const int mod = 1e9 + 7;

int n, k;
vector <int> adj[maxN];
int vis[maxN];
int res = 1;

void tarjan(int nu){
    vis[nu] = 1;
    set <int> s;
    for (auto i: adj[nu]){
        if (vis[i]){
            s.insert(i);
        }
    }
    // cout << nu << ": " << s.size() << endl;
    int color = (k - s.size());
    if (color < 0){
        color = 0;
    }
    (res = res * color) %= mod;

    for (auto i: adj[nu]){
        if (vis[i] == 0){
            tarjan(i);
        }
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    // freopen("PALLET.INP", "r", stdin);
    // freopen("PALLET.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (i == x){
            continue;
        }
        adj[i].push_back(x);
        adj[x].push_back(i);   
    }

    for (int i = 1; i <= n; i++){
        if (vis[i] == 0){
            tarjan(i);
        }
    }

    cout << res << endl;

    return 0;
}