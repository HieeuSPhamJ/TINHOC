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
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1, mi = 1e18; i <= n; i++){
        int x;
        cin >> x;
        res = max(res, x - mi);
        mi = min(mi, x);
    }

    cout << res << endl;

    return 0;
}

/*
7 1 5 3 6 4
-1 + 5 -3 + 6
*/