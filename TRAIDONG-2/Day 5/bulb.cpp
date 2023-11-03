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

int const maxN = 1e5 + 10;

char a[maxN];
char b[maxN];
int cur[maxN];
vector <ii> adj[maxN];
int vis[maxN];
vector <int> ls;

int dfs(int nu){
    vis[nu] = 1;
    if (a[nu] != b[nu]){
        a[nu] = b[nu];
        return 1;
    }
    for (auto i: adj[nu]){
        if (vis[i.fi] == 0){
            ls.push_back(i.se);
            int t = dfs(i.fi);
            // cout << nu << " " << i.fi << endl;
            if (t){
                return 1;
            }
            else{
                ls.pop_back();
            }
        }
    }
    return 0;
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n + m; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n + m; i++){
        cin >> b[i];
    }

    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        y += n;
        // cout << x << " " << y << endl;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    for (int i = 1; i <= n + m; i++){
        if (a[i] != b[i]){
            a[i] = b[i]; 
            for (int j = 1; j <= n + m; j++){
                vis[j] = 0;
            }
            ls.clear();
            // cout << "With: " << i << endl;
            int t = dfs(i);
            if (t){
                for (auto i: ls){
                    cur[i]++;
                }
            }
            else{
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector <int> st;
    for (int i = 1; i <= k; i++){
        if (cur[i] % 2){
            st.push_back(i);
        }
    }
    cout << st.size() << endl;
    for (auto i: st){
        cout << i << " ";
    }
    return 0;
}