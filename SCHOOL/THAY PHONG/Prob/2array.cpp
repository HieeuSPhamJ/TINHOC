#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const ii mod = {1e9 + 7, 1e9 + 9};

ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
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
        int n, m;
        cin >> n >> m;
        ii d1 = {1,1};
        ii d2 = {1,1};
        
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            d1 = mul(d1,{x,x});
        }
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            d2 = mul(d2,{x,x});
        }

        cout << (d1 == d2) << endl;
    }
    return 0;
}