#include<bits/stdc++.h>
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
const int mod = 1e9 + 7;

int n;
int a[maxN];
int dp[maxN];
int rmq[maxN][20];
int lg[maxN];

int get(int l, int r){
    int len = r - l + 1;
    int t1 = rmq[l][lg[len]];
    int t2 = rmq[r - (1 << lg[len]) + 1][lg[len]];
    if (l == 1){
        t1 = __gcd(t1, a[1]);
    }
    return __gcd(t1,t2);
}

int p[maxN];
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
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmq[i][0] = a[i];
        lg[i] = log2(i);
    }
    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            if (i + (1 << j) - 1 > n){
                break;
            }
            rmq[i][j] = __gcd(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            // cout << i << " " << j << " " << rmq[i][j] << endl;
            // cout << i + (1 << (j - 1)) << endl;
        }
    }

    

    // for (int i = 1; i <= n; i++){
    //     cout << p[i] << " ";
    // }
    int res = 0;
    for (int t = 0; t < n - 1;){
        if (a[1] == 1){
            break;
        }
        // cout << "With: " << n - t << endl;
        for (int i = 1; i <= n - t; i++){
            p[i] = i;
            int l = 1;
            int r = i;
            while(l <= r){
                int mid = (l + r) / 2;
                if (get(mid,i) > 1){
                    r = mid - 1;
                    p[i] = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        dp[0] = 1;
        pre[0] = 1;
        for (int i = 1; i <= n - t; i++){
            (dp[i] = pre[i - 1] - pre[p[i] - 2] + mod) %= mod;
            (pre[i] = pre[i - 1] + dp[i]) %= mod;
            // cout << i << " " << i - 1 << " " << p[i] - 1 << " " << dp[i] << endl;
        }
        // cout << dp[n - t] << endl;
        (res += dp[n - t]) %= mod;
        while(int te = __gcd(a[1], a[n - t])){
            t++;
            if (n - t <= 1){
                break;
            }
            if (te != a[1]){
                a[1] = te;
                break;
            }
            // cout << dp[n - t] << endl;
            (res += dp[n - t]) %= mod;
            a[1] = te;
        }
    }

    cout << res << endl;

    return 0;
}
/*
3 2 6 9 3 2 6 9

dp[i][fi]
dp[i][fi] = dp[j][fi]
dp[]

f(4,4)
*/