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

bool cmp(ii a, ii b){
    if (a.fi * b.se == b.fi * a.se){
        return a.fi > b.fi;
    }
    return a.fi * b.se < b.fi * a.se;
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
    vector <ii> ls;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }

    sort(all(ls), cmp);
    ii res = {0,0};
    while(k--){
        res.fi += ls.back().fi;
        res.se += ls.back().se;
        ls.pop_back();
    }

    int g = __gcd(res.fi, res.se);

    res.fi /= g;
    res.se /= g;

    cout << res.fi << " " << res.se << endl;
    return 0;
}

/*
(a1 + a2) / (b1 + b2) > (a1 + a3) / (b1 + b3)
(a1 + a2) * (b1 + b3) > (a1 + a3) * (b1 + b2)
a1b3 + a2b1 + a2b3 > a1b2 + a3b1 + a3b2
b3*(a1 + a2) + b1*(a2 + a3) > b2*(a1 + a3) 


*/