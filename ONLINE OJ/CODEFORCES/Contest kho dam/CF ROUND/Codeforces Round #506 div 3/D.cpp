#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];
unordered_map <int,int> cnt[12];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[(int)log10(a[i]) + 1][a[i] % k]++;
        // cout << (int)log10(a[i]) + 1 << ' ' << a[i] % k << endl;
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        // cout << "*" << i << endl;
        for (int l = 1, t = 10; l <= 10; l++){
            int rem = (k - (a[i] * t) % k + k) % k;
            int te = cnt[l][rem];
            if (l == (int)log10(a[i]) + 1 and a[i] % k == rem){
                te -= 1;
            }
            // cout << a[i] * t << ' ' << (a[i] * t) % k  << ' ' << rem << endl;
            // cout << l << ' ' << te << endl;
            res += te;
            t *= 10;
            t %= k;
        }
        // cout << endl;
    }

    cout << res << endl;
    return 0;
}
/*
1000000000
10000000000
*/