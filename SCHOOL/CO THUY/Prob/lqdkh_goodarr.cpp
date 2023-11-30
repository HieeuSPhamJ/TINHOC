#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    reverse(a + 1, a + 1 + n);

    // cout << "===Test===" << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int mid = 1;
    for (int i = 1; i <= n; i++){
        mid = i;
        if (a[i] > a[i + 1]){
            break;
        }
    }
    // cout << mid << endl;
    a[n + 1] = 1e18;
    int res = n - mid;
    for (int i = mid + 1; i <= n; i++){
        if (a[i - 1] < a[i]){
            break;
        }
        res = min(res, n - i);
    }

    cout << res << endl;

}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
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