#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 9;

const int maxN = 1010;

int a[maxN];
int b[maxN];
int dp[maxN][maxN][20];

bool cmp(int x, int y){
    return x > y;
}

signed main(){
    //freopen("team.in", "r", stdin);
    //freopen("team.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + m, cmp);

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= m; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;


    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j][0] = 1;
        }
    }

    for (int f = 1; f <= k; f++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j][f] = dp[i][j - 1][f] + dp[i - 1][j][f] - dp[i - 1][j - 1][f] + mod;
                if (a[i] > b[j]){
                    dp[i][j][f] += dp[i - 1][j - 1][f - 1]; 
                }
                dp[i][j][f] %= mod;
            }
        }
    }

    cout << dp[n][m][k];

    return 0;
}

/*
1000 * 10 * 1000 / 2

*/