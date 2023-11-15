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
    map <int,int> cnt;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    multiset <int, greater <int>> s;
    for (auto i: cnt){
        // cout << i.se << endl;;
        s.insert(i.se);
    }
    int res = 0;
    while(s.size() >= 2){
        int t1 = *s.begin();
        s.erase(s.begin());
        int t2 = *s.begin();
        s.erase(s.begin());
        res += 2;
        t1 -= 1;
        t2 -= 1;
        if (t1){
            s.insert(t1);
        }
        if (t2){
            s.insert(t2);
        }
    }
    cout << res << endl;
    return 0;
}