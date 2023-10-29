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

const int maxN = 1e6 + 10;

int dp[maxN];
vector <int> adj[maxN];
int cnt[maxN];
int uoc[maxN];
int boi[maxN];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cnt[i] = dp[i] = boi[i] = uoc[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i){
            boi[i] += cnt[j];
            uoc[j] += cnt[i];
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        dp[i] = boi[i] * (boi[i] - 1) / 2;
        for (int j = 2 * i; j <= n; j += i){
            dp[i] -= dp[j];
        }
        if (!uoc[i]){
            ans += dp[i];
        }
            
    }
    cout << ans << endl;
}

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
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}

/*
good = tong - bad
th1
=> cach nhu loz

tinh thang good
good = each ai => find aj

ai and aj bad
=> gcd(ai,aj) % k == 0

ai => tim aj
ak <= ai




*/