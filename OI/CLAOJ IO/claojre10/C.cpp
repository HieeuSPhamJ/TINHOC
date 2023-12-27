#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;


int n, k;
int a[maxN];
int dp[maxN][2];

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

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
    cin >> n >> k;
    vector <int> ts;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ts.push_back(a[i]);
    }
    sort(all(ts));
    ts.erase(unique(all(ts)), ts.end());
    for (int i = 1; i <= n; i++){
        a[i] = lower_bound(all(ts), a[i]) - ts.begin() + 1;
        // cerr << a[i] << ' ';
    }

    for (int i = 1; i <= n; i++){
        dp[i][0] = 1;
        if (a[i] > a[i - 1]){
            dp[i][0] = dp[i - 1][0] + 1;
        }
    }
    for (int i = n; i >= 1; i--){
        dp[i][1] = 1;
        if (a[i] < a[i + 1]){
            dp[i][1] = dp[i + 1][1] + 1;
        }
    }

    int res = 0;
    k++;
    for (int i = 1; i <= n; i++){
        res = max({res, dp[i][0], dp[i][1]});
        if (i - k >= 1 and a[i - k] < a[i]){
            res = max(res, dp[i - k][0] + dp[i][1]);
        }
    }
    

    cout << res << endl;
    return 0;
}