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

const int mod = 1e9 + 7;

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int t = 1;
        if (x == 1){
            t = 0;
        }
        for (int j = 2; j * j <= x; j++){
            if (x % j == 0){
                t = 0;
                break;
            }
        }
        ls.push_back({x,t});
    }

    int res = 0;

    for (int mask = 1; mask < (1 << n); mask++){
        if (__builtin_popcount(mask) != k){
            continue;
        }
        map <int,int> cnt;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                if (ls[i].se){
                    cnt[ls[i].fi]++;
                }
            }
        }
        for (auto i: cnt){
            if (i.se > 1){
                goto bru;
            }
        }

        (res += 1) %= mod;

        bru:;
    }

    cout << res << endl;

    return 0;
}