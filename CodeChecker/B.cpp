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


int n, k, x;
int a[maxN];
int ans = 0;

void backtrack(int id, int k){
    if (id > n){
        if (k == 0){
            int res = 0;
            for (int i = 1; i <= n; i++){
                res = max(res + a[i], a[i]);
                // cout << a[i] << ":" << res << " ";
                ans = max(ans,res);
            }
            // cout << endl;
            // cout << res << endl;
        }
        return;
    }
    a[id] -= x;
    backtrack(id + 1, k);
    a[id] += x;
    if (k >= 1){
        a[id] += x;
        backtrack(id + 1, k - 1);
        a[id] -= x;
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> k >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ans = 0;
        backtrack(1,k);
        cout << ans << endl;
    }
    return 0;
}