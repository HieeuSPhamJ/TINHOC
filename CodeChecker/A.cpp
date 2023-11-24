#include"bits/stdc++.h"
#define int int
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n;

namespace sub1{
    
    int a[maxN];
    
    void solve(){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i, ma = a[i], mi = a[i]; j <= n; j++){
                ma = max(ma, a[j]);
                mi = min(mi, a[j]);
                if ((ma - mi) % 2 == 0){
                    res++;
                }
            }
        }
        cout << res << endl;
    }
}


namespace sub2{
    int a[maxN];
    int mal[maxN];
    int mar[maxN];
    int mil[maxN];
    int mir[maxN];
    int ans = 0;

    void solve(int l, int r) {
        if (l == r) {
            ans++;
            return;
        }  
        int mid = (l + r) / 2;
        solve(l, mid);
        solve(mid + 1, r);

        mal[mid] = a[mid];
        mil[mid] = a[mid];
        for (int i = mid - 1; i >= l; i--) {
            mal[i] = max(mal[i + 1], a[i]);
            mil[i] = min(mil[i + 1], a[i]);
        }
        mar[mid + 1] = mir[mid + 1] = a[mid + 1];
        for (int i = mid + 2; i <= r; i++) {
            mar[i] = max(mar[i - 1], a[i]);
            mir[i] = min(mir[i - 1], a[i]);
        }

        int cnt[2] = {0, 0};
        for (int i = mid, j1 = mid + 1, j2 = mid + 1; i >= l; i--) {
            while (j2 <= r and mal[i] >= mar[j2]) {
                cnt[mir[j2] % 2]++;
                j2++;
            }
            while (j1 <= r and mal[i] >= mar[j1] and mil[i] <= mir[j1]) {
                cnt[mir[j1] % 2]--;
                j1++;
            }
            ans += (((mal[i] ^ mil[i]) % 2) == 0) * (j1 - mid - 1);
            ans += cnt[mal[i] % 2];
        }

        cnt[0] = cnt[1] = 0;
        for (int i1 = mid, i2 = mid, j = mid + 1; j <= r; j++) {
            while (i2 >= l and mal[i2] < mar[j]) {
                cnt[mil[i2] % 2]++;
                i2--;
            }
            while (i1 >= l and mal[i1] < mar[j] and mil[i1] >= mir[j]) {
                cnt[mil[i1] % 2]--;
                i1--;
            }
            ans += (((mar[j] ^ mir[j]) % 2) == 0) * (mid - i1);
            ans += cnt[mar[j] % 2];
        }
    }
    void solve(){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        solve(1, n);
        cout << ans << endl;
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("EVENSUB.inp", "r")) {
        freopen("EVENSUB.inp", "r", stdin);
        freopen("EVENSUB.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
        sub2::solve();
    



    return 0;
}

/*

4 5 2 6 3
1 1 2 1 1 
1 1 1 1 1

1 1!
1 4
1 5
2 2!
2 4
2 5
3 3!
3 4!
3 5
4 4!
5 5!
*/