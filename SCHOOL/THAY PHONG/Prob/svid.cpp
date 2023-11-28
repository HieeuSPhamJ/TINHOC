#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int rt[maxN];
int cn[maxN];

int find(int nu){
    if (nu == rt[nu]){
        return nu;
    }
    return rt[nu] = find(rt[nu]);
}

int res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector <pair<int,ii>> ls;
    for (int i = 1; i <= n; i++){
        rt[i] = i;
        cn[i] = 1;
    }
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        ls.push_back({w,{a,b}});
    }
    sort(all(ls));
    vector <pair<int,ii>> query;
    for (int i = 1; i <= test;i++){
        int k, x;
        cin >> k >> x;
        query.push_back({k,{x,i}});
    }
    sort(rall(query));

    for (auto i: query){
        int w = i.fi;
        // cout << w << endl;
        while(ls.size() and ls.back().fi >= w){
            ii e = ls.back().se;
            ls.pop_back();
            // cout << e.fi << " " << e.se << endl;
            int u = find(e.fi);
            int v = find(e.se);
            if (u == v){
                continue;
            }
            rt[u] = v;
            cn[v] += cn[u];
        }
        res[i.se.se] = cn[find(i.se.fi)] - 1;
    }

    for (int i = 1; i <= test; i++){
        cout << res[i] << endl;
    }
    return 0;
}