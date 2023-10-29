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

const int maxN = 1e5 + 10;

int n;
int a[maxN];
vector <ii> ls;
int rt[maxN];
int va[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

bool cmp(ii x, ii y){
    return max(a[x.fi], a[x.se]) < max(a[y.fi], a[y.se]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("PARADIGM.inp", "r")) {
        freopen("PARADIGM.inp", "r", stdin);
        freopen("PARADIGM.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> s;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
        s.push_back(i - 1);
    }

    sort(all(ls), cmp);

    for (int i = 1; i <= n; i++){
        rt[i] = i;
        va[i] = a[i];
    }
    int res = 0;
    for (auto i: s){
        int u = find(ls[i].fi);
        int v = find(ls[i].se);
        // cout << i << " " << ls[i].fi << " " << ls[i].se << endl;
        if (u == v){
            continue;
        }
        res += va[u] + va[v];
        va[u] = max(va[u], va[v]);
        rt[v] = u;
    }
    
    cout << res << endl;
    return 0;
}

/*
aaaa
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
*/