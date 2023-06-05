#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

unordered_map <int,int> a[maxN];
int ok[maxN];
int re[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    for (int i = 1; i <= n; i++){
        int x = i + l - 1;
        re[i] = x;
        for (int j = 2; j * j <= x; j++){
            while(x % j == 0){
                a[i][j]++;
                x /= j;
            }
        }
        if (x > 1){
            a[i][x]++;
        }
        // cout << "Index: " << i << endl;
        for (auto t: a[i]){
            if (t.se >= 2){
                ok[i] = 1;
                break;
            }
            // cout << t.fi << " " << t.se << endl;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (ok[i]){
            // cout << i << ": full " << re[i] << endl;
            res += (i - 1);
            continue;
        }
        for (int j = i - 1; j >= 1; j--){
            if (ok[j]){
                res++;
                continue;
            }
            for (auto x: a[i]){
                if (re[j] % x.fi == 0){
                    res++;
                    // cout << j << " " << i << endl;
                    goto bru;
                }
            }
            for (auto x: a[j]){
                if (re[i] % x.fi == 0){
                    res++;
                    // cout << j << " " << i << endl;
                    goto bru;
                }
            }
            bru:;
        }
    }
    cout << res << endl;
    return 0;
}