#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e3 + 10;
const int mod = 1e9 + 7;

int a[maxN];
int dp[maxN][maxN];
int p[maxN];
int nxt[maxN][27];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    for (int i = 2; i <= m; i++){
        int t = p[i - 1];
        while (t > 0 and a[t + 1] != a[i]){
            t = p[t];
        }
        p[i] = t;
        if (a[i] == a[t + 1]){
            p[i]++;
        }
    }
    a[m + 1] = -1;
    nxt[0][a[1]] = 1;
    for (int i = 1; i <= m; i++){
        for (int c = 0; c <= 25; c++){
            if (i > 0 and a[i + 1] != c){
                nxt[i][c] = nxt[p[i - 1]][c];
            }
            else{
                nxt[i][c] = i + 1;
            }
            // cout << i << " " << c << ": " << nxt[i][c] << endl;
        }
    }

    dp[m][m] = 1;
    for (int i = m; i <= n; i++){
        for (int k = 1; k <= m; k++){
            int t = dp[i][k];
            if (t == 0){
                continue;
            }
            int c = a[k + 1];
            if (c != -1){
                (dp[i + 1][k + 1] += t) %= mod;
            }
            (dp[i + 1][nxt[k][a[1]]] += t) %= mod;
        }  

    }

    // for (int j = 1; j <= m; j++){
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i][j] << ' ';
    // }
    // cout << endl;
    // }

    int res = 0;
    for (int i = 1; i <= m; i++){
        (res += dp[n][i]) %= mod;
    }
    cout << res << endl;
    
    return 0;
}
