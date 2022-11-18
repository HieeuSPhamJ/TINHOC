#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        if (n > m){
            swap(n,m);
        }
        int d;
        cin >> d;
        int ans = 1e18;
        
        if (abs(m - n) == d){
            ans = min(ans, 2ll);
        }
        if (d == n or d == m){
            ans = min(ans, 1ll);
        }
        if (d % n == 0){
            ans = min(ans, d / n * 2);
        }
        if (d % m == 0){
            ans = min(ans, d / m * 2);
        }
        if (d > n and d < m){
            if (d == m - (n - abs(n - m))){
                ans = min(ans, (int)(4 + 3));
            }
            if ((m - d) % n == 0){
                ans = min(ans, (m - d) / n * 2);
            }
        }
        if (d > n and d > m){
            ans = 1e18;
        }
        if (ans == 1e18){
            ans = -1;
        }
        cout << ans << endl;
        
    }
    return 0;
}