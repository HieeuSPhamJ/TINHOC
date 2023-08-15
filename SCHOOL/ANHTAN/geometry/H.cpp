#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int area(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}

void solve(){
    ii a, b, c, d;
    cin >> a.fi >> a.se >> b.fi >> b.se;
    cin >> c.fi >> c.se >> d.fi >> d.se;
    int o = 0;
    set <ii> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    if (s.size() < 4){
        cout << "YES";
        return;
    }
    if (area(a,b,c) == 0){
        o++;
    }
    if (area(a,b,d) == 0){
        o++;
    }
    if (area(c,d,a) == 0){
        o++;
    }
    if (area(c,d,b) == 0){
        o++;
    }
    if (o >= 2){
        cout << "NO";
        return;
    }
    // cout << area(a,b,c) << " " << area(a,b,d) << " " << area(c,d,a) << " " << area(c,d,b) << endl;
    if (area(a,b,c) * area(a,b,d) < 0 and area(c,d,a) * area(c,d,b) < 0){
        cout << "YES";
        return;
    }
    cout << "NO";
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }
    return 0;
}