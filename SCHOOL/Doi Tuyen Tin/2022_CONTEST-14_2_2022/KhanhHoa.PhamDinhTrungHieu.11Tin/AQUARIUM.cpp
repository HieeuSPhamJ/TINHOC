#include <bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define iii pair <int,ii>
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;

const int maxN = 2010;
const int inf = 1e18;

int a[maxN];
int dp[maxN][maxN];
int prefix[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("AQUARIUM.INP","r", stdin);
    freopen("AQUARIUM.OUT","w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);


    for (int i = 0; i <= n; i++){
        for (int k = 0; k <= m; k++){
            dp[i][k] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
        for (int k = 1; k <= m; k++){
            for (int j = i - 1; j >= 0; j--){
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + (prefix[i] - prefix[j]) * (i - j));
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}

