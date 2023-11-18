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

const int maxN = 2e5 + 10;

int pre[maxN];


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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;   
            pre[i] = pre[i - 1] + x;
        }

        int res = 0;

        for (int k = 1; k <= n; k++){
            if (n % k == 0){
                int mi = 1e18;
                int ma = 0;
                for (int i = 1; i * k <= n; i++){
                    int t = pre[i * k] - pre[i * k - k];
                    ma = max(ma, t);
                    mi = min(mi, t);
                }
                res = max(res, ma - mi);
            }
        }

        cout << res << endl;
    }
    return 0;
}