#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 13;

int a[100][100];

int cal(int x, int q, int w, int e, int r){
    return abs(q - x) % mod + abs(w - x) % mod + abs(e - x) % mod + abs(r - x) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char t;
            cin >> t;
            a[i][j] = t - 'A';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int q = a[i][j];
            int w = a[n - i + 1][m - j + 1];
            int e = a[n - i + 1][j];
            int r = a[i][m - j + 1];
            int x = q;
            int tans = cal(x,q,w,e,r);
            x = w;
            tans = min(tans, cal(x,q,w,e,r));
            x = e;
            tans = min(tans, cal(x,q,w,e,r));
            x = r;
            tans = min(tans, cal(x,q,w,e,r));
            ans += tans;
            if (tans != 0){
                // cout << i << " " << j << endl;
                // // cout << n - i + 1 << 
                // cout << q << " " << w << " " << e << " " << r << endl;
                // cout << tans << endl;
            }

        }
    }
    cout << ans / 4;
    return 0;
}