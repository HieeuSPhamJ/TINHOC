#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
vector <ii> ask;
int res[maxN];
int nxt[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("MAZE.inp", "r")) {
        freopen("MAZE.inp", "r", stdin);
        freopen("MAZE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for (int i = 1; i <= test; i++){
        int x;
        cin >> x;
        ask.push_back({x,i});
    }
    sort(all(ask));
        
    int j = 1;
    int k = 1;

    for (auto i: ask){
        while (j <= i.fi){
            (nxt[k] += 1) %= (int)adj[k].size();
            k = adj[k][nxt[k]];
            j++;
        }
        res[i.se] = k;
    }

    for (int i = 1; i <= test; i++){
        cout << res[i] << endl;
    }
    return 0;
}