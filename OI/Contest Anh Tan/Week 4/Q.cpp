#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int dp[1 << 18][101];
int a[19];
int fact[20];
int lg[1 << 18];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int n, m;
    cin >> m;
    n = s.length();
    map <int,int> cnt;
    fact[0] = 1;
    for (int i = 0; i < n; i++){
        a[i] = s[i] - '0';
        cnt[a[i]]++;
        fact[i + 1] = fact[i] * (i + 1);
        if (a[i] == 0){
            continue;
        }
        dp[1 << i][a[i] % m]++;
    }

    
    for (int mask = 1; mask < (1 << n); mask++){
        lg[mask] = log2(mask);
    }

    for (int mask = 1; mask < (1 << n); mask++){
        for (int k = 0; k < m; k++){
            if (dp[mask][k] == 0){
                continue;
            }
            int anti = (1 << n) - 1;
            anti = anti xor mask;
            // cout << bitset<7>(mask) << " " << k << ": " << bitset<7>(anti) << endl;
            while(anti){
                int i = lg[anti];
                // cout << i << endl;
                anti = anti xor (1 << i);
                dp[mask | (1 << i)][(k * 10 + a[i]) % m] += dp[mask][k];
            }           
        }
    }
    int res = dp[(1 << n) - 1][0];
    // cout << res << endl;
    for (auto i: cnt){
        // cout << fact[i.se] << endl;
        res /= fact[i.se];
    }
    cout << res << endl;
    
    return 0;
}

/*
4 7185 9200
*/