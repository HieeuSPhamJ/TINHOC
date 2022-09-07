#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 17;

int a[maxN][maxN];
int dp[maxN][(1 << maxN)];

bool getBit(int mask, int i){
    return (mask & (1 << i));
}

int onBit(int mask, int i){
    return mask | (1 << i);
}

int offBit(int mask, int i){
    return (mask xor (1 << i));
}

int print(int n)
{
    int a[10] = {0}, i;
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    for (i = 5; i >= 0; i--)
    {
        cout << a[i];
    }
} 

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            
            if (getBit(mask, i) == 0){
                continue;
            }
            int preMask = offBit(mask, i);
            int temp = 1e18;
            for (int j = 0; j < n; j++){
                if (i == j or getBit(preMask, j) == 0){
                    continue;
                }
                temp = min(temp, dp[j][preMask] + a[j][i]);
            }
            if (temp == 1e18){
                continue;
            }
            dp[i][mask] = temp;

        }
    }

    int ans = 1e18;


    for (int i = 0; i < n; i++){
        ans = min(ans, dp[i][(1 << n) - 1]);
        // cout << dp[i][(1 << n) - 1] << endl;
    }


    
    cout << ans;

    return 0;
}
