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
    int test, k;
    cin >> test >> k;
    while (test--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map <string, int> sto;

        for (int mask = 1; mask < (1 << n); mask++){
            string t = "";
            for (int i = 0; i < n; i++){
                if ((1 << i) & mask){
                    t += s[i];
                }
            }
            sto[t]++;
            // cout << t << endl;
        }

        int res = 0;

        for (auto i: sto){
            if (i.se == k){
                // cout << i.fi << endl;
                res++;
                // cout << res << endl;
            }
        }

        cout << res << endl;
    }
    return 0;
}