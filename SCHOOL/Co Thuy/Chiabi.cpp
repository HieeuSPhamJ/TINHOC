#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    // freopen("Chiabi.INP", "r", stdin);
    // freopen("Chiabi.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int left = 1;
    int right = 1e18;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        right = min(right, a[i]);
    }

    int ans = 1e18;

    for (int x = 1; x <= right; x++){
        int res = 0;    
        int ok = 1;
        for (int i = 1; i <= n; i++){
            if (a[i] % x > a[i] / x){
                ok = 0;
            }
            res += 
        }

        if (ok == 1){
            ans = min(ans, res);
        }
    }

    cout << ans;


    return 0;
}