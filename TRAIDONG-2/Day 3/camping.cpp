#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

map <ii,bool> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("camping.inp", "r")) {
        freopen("camping.inp", "r", stdin);
        freopen("camping.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int res = n * (m - 1) + (n - 1) * m;
    while(k--){
        int x, y;
        cin >> x >> y;
        if (cnt[{x,y}]){
            continue;
        }
        cnt[{x,y}] = 1;
        res -= 4;
        // cout << x << " === " << y << endl;
        if (y == 1 or cnt[{x,y - 1}]){
            res++;
            // cout << x << " " << y - 1 << " " << cnt[{x,y - 1}] << endl;
        }
        if (y == m or cnt[{x,y + 1}]){
            res++;
            // cout << x << " " << y + 1 << " " << cnt[{x,y + 1}] << endl;
        }
        if (x == 1 or cnt[{x - 1,y}]){
            res++;
            // cout << x - 1 << " " << y << " " << cnt[{x - 1,y}] << endl;
        }
        if (x == n or cnt[{x + 1,y}]){
            res++;
            // cout << x + 1 << " " << y << " " << cnt[{x + 1,y}] << endl;
        }
    }

    cout << res << endl;
    return 0;
}