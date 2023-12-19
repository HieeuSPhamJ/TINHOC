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

struct dt{
    int a[26];
    int len = 0;
} a[20];

int co[20][20];
int dp[1 << 20];

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (auto x: s){
            a[i].a[x - 'a']++;
        }
        a[i].len = s.length();
    }

    // for (int i = 0; i <=n; i++){
    //     for (int j = 0; j <= 25; j++){
    //         cout << a[i].a[j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int cnt = 0;
            for (int x = 0; x <= 25; x++){
                cnt += min(a[i].a[x], a[j].a[x]);
            }
            co[i][j] = cnt;
        }
    }

    memset(dp, 0x3f, sizeof(dp));

    dp[0] = 1;

    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                int laMask = mask ^ (1 << i);
                int res = a[i].len;
                for (int j = 0; j < n; j++){
                    if (laMask & (1 << j)){
                        res = min(res, a[i].len - co[i][j]);
                    }
                }   
                if (minimize(dp[mask], dp[laMask] + res)){
                    cout << bitset<3>(mask) << ": " << dp[mask] << endl;
                    cout << " " << bitset<3>(laMask) << " " << dp[laMask] << endl;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1];
    return 0;
}