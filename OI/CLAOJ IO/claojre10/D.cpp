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

const int maxN = 3e5 + 10;

int n, m, W, na, nb;

int rt[maxN];
ii va[maxN];

int find(int nu){
    if (rt[nu] == nu){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int cal(){
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (find(i) == i){
            res += va[i].fi * va[i].se;
        }
    }
    return res;
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
    cin >> n >> m >> W >> na >> nb;
    vector <pair<int,ii>> ls;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        ls.push_back({w,{a,b}});
    }

    for (int i = 1; i <= na; i++){
        int x;
        cin >> x;
        va[x].fi++;
    }
    for (int i = 1; i <= nb; i++){
        int x;
        cin >> x;
        va[x].se++;
    }
    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }

    sort(rall(ls));

    while(ls.size() and ls.back().fi < W){
        int u = find(ls.back().se.fi);
        int v = find(ls.back().se.se);
        ls.pop_back();

        if (u == v){
            continue;
        }

        rt[u] = v;
        va[v].fi += va[u].fi;
        va[v].se += va[u].se;
    }

    int res1 = cal();

    while(ls.size() and ls.back().fi <= W){
        int u = find(ls.back().se.fi);
        int v = find(ls.back().se.se);
        ls.pop_back();

        if (u == v){
            continue;
        }

        rt[u] = v;
        va[v].fi += va[u].fi;
        va[v].se += va[u].se;
    }

    int res2 = cal();

    cout << res2 - res1 << endl;
    return 0;
}