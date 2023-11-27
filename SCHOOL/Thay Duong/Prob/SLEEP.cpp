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

const int maxN = 1e5 + 10;

int a[maxN];
int pre[maxN];

void solve(){
    int n;
    cin >> n;
    int allok = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i > 1 and a[i] != a[i - 1]){
            allok = 0;
        }
        pre[i] = pre[i - 1] + a[i];
    }
    if (allok){
        cout << 0 << endl;
        return;
    }
    int res = -1;
    for (int i = 1; i <= n; i++){
        int v = pre[i];
        int ok = 1;
        int step = 1;
        int la = i;
        // cout << "With: " << i << " " << v << endl;
        while(ok){
            if (la == n){
                break;
            }
            int l = la + 1;
            int r = n;
            while(l <= r){
                int mid = (l + r) / 2;
                // cout << mid << " " << pre[mid] - pre[la] << endl;
                if (pre[mid] - pre[la] == v){
                    // cout << la + 1 << " - " << mid << endl;
                    la = mid;
                    goto bru;
                }
                else if (pre[mid] - pre[la] < v){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            ok = 0;
            break;
            bru:;
            step++;
        }
        if (ok){
            res = step;
            break;
        }
    }
    cout << n - res << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SLEEP.inp", "r")) {
        freopen("SLEEP.inp", "r", stdin);
        freopen("SLEEP.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        solve();
    }


    return 0;
}
