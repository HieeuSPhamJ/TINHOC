#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[1000];
int b[1000];

signed main(){
    freopen("input.inp", "r", stdin);
    // freopen(".out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        int ans = 1e18;

        for (int i = 1; i <= n; i++){
            for (int  j = 1; j <= n; j++){
                if (i != j){
                    ans = min(ans, abs(a[i] - a[j]));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}