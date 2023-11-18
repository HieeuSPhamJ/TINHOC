#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int C(int n){
    return n * (n - 1) / 2;
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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        map <int,int> cnt;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        int res = 0;
        for (auto x: cnt){
            // cout << x.fi << ": " << x.se << endl;
            res += C(x.se);
        }
        res += cnt[2] * cnt[1];
        cout << res << endl;
    }
    return 0;
}

/*

*/