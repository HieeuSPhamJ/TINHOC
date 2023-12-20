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
    int n, k;
    cin >> n >> k;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    set <int> s;
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    int res = 0;

    for (auto x: ls){
        auto it = s.lower_bound(x);
        int t = 1e18;
        if (it != s.end()){
            t = min(t, abs(x - *it));
        }
        if (it != s.begin()){
            it--;
            t = min(t, abs(x - *it));
        }
        res += t;
    }

    cout << res << endl;
    return 0;
}