#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 998244353;

int a[maxN];
map <int,int> dp[maxN];
map <int,int> dpDup[maxN];
int ans[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    dp[0][1] = 1;
    ans[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = k; j <= k + 500; j++){
            if (i - j >= 0){
                (dp[i][j] += dp[i - j][j - 1] + dpDup[i - j][j - 1]) %= mod;
                (dp[i][j] += dpDup[i - j][j]) %= mod;
                dpDup[i][j] = dpDup[i - j][j];
                dpDup[i][j] += dp[i - j][j - 1];
                
            }

            ans[i] += dp[i][j];
        }
    }


    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }



    return 0;
}