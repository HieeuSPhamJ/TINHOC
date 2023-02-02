#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5 * 1e3 + 10;

int a[maxN];
int val[maxN];
int cost[maxN];
int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    int m = 0;

    for (int i = 1; i <= n; i++){
        // cout << a[i] << " " << a[i - 1] << endl;
        if (a[i] != a[i - 1]){
            m++;
        }
        cost[m]++;
        val[m] = a[i];
    }

    // for (int i = 1; i <= m; i++){
    //     cout << val[i] << " " << cost[i] << endl;
    // }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            // cout << "With " << i << " " << j << endl;
            for (int x = 0, sum = 0; x <= 5 and i - x >= 1 and val[i] - val[i - x] <= 5; x++){
                sum += cost[i - x];
                // cout << i - x << " " << sum << endl;
                dp[i][j] = max(dp[i][j], dp[i - x - 1][j - 1] + sum);
            }
        }
    }

    cout << dp[m][k];


    return 0;
}

/*
4 1
5 1
6 1
7 4
8 1
9 2
*/