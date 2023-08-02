#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1 << 11;

int dp[maxN];
int a[(int)1e6 + 10];

signed main(){
    freopen("PALS.INP", "r", stdin);
    freopen("PALS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int mask = 0;
        while(x){
            mask = mask | (1 << (x % 10));
            x /= 10;
        }
        a[i] = mask;
        dp[mask]++;
    }
    for (int i = 0; i < 10; i++){
        for (int mask = 0; mask < (1 << 10); mask++){
            if (mask & (1 << i)){
                dp[mask] += dp[mask xor (1 << i)];
            }
        }
    }

    // for (int mask = 0; mask < (1 << 10); mask++){
    //     if (dp[mask]){
    //         cout << bitset<10>(mask) << " " << dp[mask] << endl;
    //     }
    // }

    int res = n * (n - 1);

    for (int i = 1; i <= n; i++){
        int mask = (1 << 10) - 1;
        mask = mask xor a[i];
        // cout << bitset<10>(a[i]) << ": " << bitset<10>(mask) << " " << dp[mask] << endl;
        res -= dp[mask];
    }

    cout << res / 2 << endl;

    return 0;
}

/*
4 20
4 44

*/