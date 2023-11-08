#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5e3;

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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    bitset <maxN> g;
    vector<bitset<maxN>> a(n);
    reverse(all(s));
    reverse(all(t));
    
    for (int i = 0; i < n; i++){
        g[i] = (s[i] == '1');
    }
    for (int i = 0; i < n; i++){
        a[0][i] = (t[i] == '1');
    }
    // cout << a[0] << endl;
    for (int i = 1; i < n; i++){
        a[i] = a[i - 1];
        bool t = a[i][n - 1];
        a[i][n - 1] = 0;
        a[i] <<= 1;
        a[i][0] = t;
        // cout << a[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!g[j] && a[i][j]) {    
                goto bru;
            }
        }
        for (int j = 0; j <= i; j++) {
            if ((a[i] | a[j]) == g) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
        bru:;
    }

    cout << -1;


    return 0;
}
