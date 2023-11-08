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

const int maxN = 3e5 + 10;

vector <int> adj[maxN];
long long res = 0;
int mk[maxN];

void dfs(int nu, int fa){
    mk[nu] = mk[fa] + 1; 
    for (auto i: adj[nu]){
        if (!mk[i]){
            dfs(i,nu);
        }
        res -= 3 * (abs(mk[nu] - mk[i]) == 2);
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("two.inp", "r")) {
        freopen("two.inp", "r", stdin);
        freopen("two.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    if (n == 2){
        cin >> n >> m;
        cout << 2 * (n - 2);
        return 0;
    }
    cin >> n >> m;
    // n = 3e5;
    // m = 3e5;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        // a = i;
        // a = (i % n) + 1;
        adj[a].push_back(b);
        adj[b].push_back(a);  
    }
    
    for (int i = 1; i <= n; i++){
        for (auto x: adj[i]){
            res += (int)adj[x].size() - 1;
        }
    }
    dfs(1,0);
    
    cout << res << endl;

    return 0;
}