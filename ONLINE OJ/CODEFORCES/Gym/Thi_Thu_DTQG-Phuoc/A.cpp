#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

ii a[maxN];

map <ii,int> sto;

void mini(ii &v){
    int g = __gcd(v.fi, v.se);
    v.fi /= g;
    v.se /= g;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    int res = 0;

    for (int i = 2; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            ii v = a[j];
            v.fi -= a[i].fi;
            v.se -= a[i].se;
            mini(v);
            res += sto[v];
        }
        for (int j = i - 1; j >= 1; j--){
            ii v = a[i];
            v.fi -= a[j].fi;
            v.se -= a[j].se;
            mini(v);
            sto[v]++;
        }
    }
    res = n * (n - 1) * (n - 2) * (n - 3) /  24 - res;
    cout << res << endl;
    return 0;
}