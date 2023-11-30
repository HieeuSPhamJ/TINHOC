#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int maxR = 2010;
int a[maxN];

int dp[maxR];
int store[maxR];
int pre[maxN];

int sum(int i, int j){
    return pre[j] - pre[i - 1];
}


signed main(){
    freopen("KM2.inp", "r", stdin);
    freopen("KM2.out", "w", stdout);
    // freopen("KM2.INP", "r", stdin);
    // freopen("KM2.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1e18;
    }

    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        store[x] = max(store[x], y);
    }
 
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= k; i++){
        // cout << "With: " << i << endl;
        for (int j = 1; i - j >= 0; j++){
            // cout << j << ": " << i - j << " " << i - j + 1 << " " << i - j + 1 + store[j] << endl;
            // cout << dp[i - j] << " - " << sum(i - j + 1, i) << " - " << sum(i - j + 1, i - j + store[j]) << endl;
            dp[i] = min(dp[i], dp[i - j] + sum(i - j + 1, i) - sum(i - j + 1, i - j + store[j]));
        }
    }

    cout << dp[k];


    return 0;
}

/*
1 2 2 3 4
*/