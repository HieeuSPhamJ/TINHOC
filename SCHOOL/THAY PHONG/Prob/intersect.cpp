#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


int cals(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}

int check(ii a, ii b, ii c){
    if (cals(a,b,c) == 0){
        return 0;
    }
    if (cals(a,b,c) < 0){
        return -1;
    }
    return 1;
}

ii minimize(ii a){
    int g = gcd(a.fi,a.se);
    a.fi /= g;
    a.se /= g;
    return a;
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
        ii a, b, c, d;
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se >> d.fi >> d.se;

        if (check(a,b,c) * check(a,b,d) == -1 and check(b,a,c) * check(b,a,d) == -1){
            if (check(c,d,a) * check(c,d,b) == -1 and check(d,c,a) * check(d,c,b) == -1){
                cout << "YES" << endl;
                continue;
            }
        }
        ii aa = minimize(a);
        ii bb = minimize(b);
        ii cc = minimize(c);
        ii dd = minimize(d);

        if (aa == bb and bb == cc and cc == dd){

        }
        
        cout << "NO" << endl;
    }
    return 0;
}