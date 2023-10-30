#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int n, k, m;

int dp[1 << 15];
int cur[1 << 15];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("DECRYPTE.inp", "r")) {
        freopen("DECRYPTE.inp", "r", stdin);
        freopen("DECRYPTE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> m;
    cur[0] = 1;
    int mod = 1 << m;
    for (int i = 0; i < n; i++){
        for (int rem = 0; rem < mod; rem++){
            if (cur[rem] == 0){
                continue;
            }
            // cout << i << " " << rem << " " << cur[rem] << endl; 
            for (int c = 1; c <= 26; c++){
                int nrem = ((rem * 33) xor c) % mod;
                // cout << " =>" << c << " " << nrem << endl;
                dp[nrem] += cur[rem];
            }
        }
        for (int rem = 0; rem < mod; rem++){
            cur[rem] = dp[rem];
            dp[rem] = 0;
        }
    }

    cout << cur[k] << endl;
    return 0;
}