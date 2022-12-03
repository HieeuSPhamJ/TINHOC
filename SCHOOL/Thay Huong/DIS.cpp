#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e3 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int dp[maxN][maxN];
int a[maxN];
int ans[maxN];

signed main(){
    // freopen("DIS.INP", "r", stdin);
    // freopen("DIS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 1; j <= n; j++){
            dp[i][j] = 1;
        }
    }


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                continue;
            }
            // cout << "With: " << i << " " << j << endl;
            for (int k = 1; k < min(i,j); k++){
                if (k < i and a[i] > a[k]){
                    dp[i][j] += dp[k][j];
                }
                if (k < j and a[j] > a[k]){
                    dp[i][j] += dp[i][k];
                }
                
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // cout << dp[i][j] << " ";
            ans += dp[i][j];
        }
        // cout << endl;
    }

    cout << (ans - n) / 2;


    return 0;
}