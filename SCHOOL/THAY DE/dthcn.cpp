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

bool cmp(ii a, ii b){
    if (a.se != b.se){
        return a.se < b.se;
    }
    return a.fi < b.fi;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("dthcn.inp", "r")) {
        freopen("dthcn.inp", "r", stdin);
        freopen("dthcn.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int res = 0;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }
    sort(all(ls), cmp);
    int mi = 0;
    while(ls.size()){
        ii t = ls.back();
        while(ls.size() and ls.back().se == t.se){
            ls.pop_back();
        }
        res += t.se * (t.fi - mi);
        mi = t.fi;
    }
    cout << res << endl;
    return 0;
}