#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 100 + 10;
const int inf = 1e18;

int n, m;
int a[maxN];
int b[maxN];
int pre[maxN];
int last[maxN];
int id[maxN];
int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] += b[i - 1] + a[i];
    }
    int nn = 0;
    for (int i = 1; i <= n; i++){
        if (s1[i - 1] != s2[i - 1]){
            nn++;
            pre[nn] = b[i];
            last[nn] = b[i - 1];
            id[nn] = i;
        }
    }
    s1 = " " + s1;
    s2 = " " + s2;
    n = nn;
    if (nn == 0){
        cout << 0;
        return 0;
    }

    int res = inf;

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0; 

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            map <char,int> c;
            for (int k = j; k >= 1; k--){
                c[s1[id[k]]]++;
                c[s2[id[k]]]--;
                int ok = 1;
                for (auto x: c){
                    if (x.se != 0){
                        ok = 0;
                    }
                }
                if (ok){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + pre[j] - last[k]);
                }
            }
        }
        res = min(res, dp[i][n]);
    }

    cout << res << endl;

    return 0;
}
