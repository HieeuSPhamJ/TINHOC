#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN];
int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    if (n > m){
        cout << "YES";
        return 0;
    }

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= m;
        dp[i][a[i] % m] = 1;
    }


    for (int i = 2; i <= n; i++){
        for (int j = m - 1; j >= 0; j--){
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][(j - a[i] + m) % m]});
        }
    }

    for (int i = 1; i <= n; i++){
        if (dp[i][0] == 1){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}