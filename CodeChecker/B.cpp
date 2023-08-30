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
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);
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
    for (int i = 1; i <= n; i++){
    for (int j = 1; j < i; j++){
    for (int k = 1; k < j; k++){
    for (int z = 1; z < k; z++){
        ii v = a[j];
        v.fi -= a[i].fi;
        v.se -= a[i].se;
        ii u = a[z];
        u.fi -= a[k].fi;
        u.se -= a[k].se;
        mini(u);
        mini(v);
        if (u != v){
            res++;
        }
    }        
    }   
    }
    }
    cout << res << endl;
    return 0;
}