#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e4 + 10;
const int inf = 1e18;

int a[maxN];
int b[maxN];
int p[maxN];
int nxt[maxN][27];
int dp[maxN][1010];

void solve(){
    string A, B;
    cin >> A >> B;
    int n = A.length();
    int m = B.length();
    for (int i = 1; i <= n; i++){
        a[i] = A[i - 1] - 'a';
    }
    for (int i = 1; i <= m; i++){
        b[i] = B[i - 1] - 'a';
    }

    for (int i = 2; i <= m; i++){
        int t = p[i - 1];
        while (t > 0 and b[t + 1] != b[i]){
            t = p[t];
        }
        p[i] = t;
        if (b[i] == b[t + 1]){
            p[i]++;
        }
    }
    b[m + 1] = -1;
    for (int i = 0; i <= m; i++){
        for (int c = 0; c <= 25; c++){
            if (i > 0 and b[i + 1] != c){
                nxt[i][c] = nxt[p[i - 1]][c];
            }
            else{
                nxt[i][c] = i + 1;
            }       
            cout << i << " " << c << ": " << nxt[i][c] << endl;
        }
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int now = dp[i][j];
            if (now == 0){
                continue;
            }
            dp[i + 1][nxt[j][a[i]]] = min(dp[i + 1][nxt[j][a[i]]], now);
            dp[i + 1][j] = min(dp[i + 1][j], now + 1);
        }
    }

    int res = inf;
    for (int i = 0; i < m; i++){
        res = min(res,dp[n][i]);
    }   
    cout << res << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}