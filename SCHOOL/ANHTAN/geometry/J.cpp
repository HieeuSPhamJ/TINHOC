#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair <double,double> a, b, v, p, res;
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    v.fi = a.fi - b.fi;
    v.se = a.se - b.se;
    p.fi = (a.fi + b.fi) / 2;
    p.se = (a.se + b.se) / 2;
    // cout << v.fi << " " << v.se << endl;

    res.fi = - v.fi / v.se;
    res.se = (- v.fi) * p.fi + (- v.se) * p.se;
    res.se =  - res.se / v.se;
    cout << fixed << setprecision(5) << res.fi << " " << res.se << endl;
    return 0;
}