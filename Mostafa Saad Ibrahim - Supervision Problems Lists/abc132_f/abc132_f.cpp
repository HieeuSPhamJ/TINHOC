#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int big[110];
int small[110];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    int sq = 0;
    for (int j = 1; j * j <= k; j++){
        sq++;
    }
    small[1] = sq;
    big[1] = k - sq;
    for (int i = 2; i <= n; i++){
        (small[i] = (small[i - 1] + big[i - 1]) * sq) %= mod;
        (big[i] = small[i - 1] * (k - sq)) %= mod;
    }
    cout << (small[n] + big[n]) % mod << endl;
    return 0;
}