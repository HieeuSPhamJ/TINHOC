#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


const int maxN = 1e5 + 10;

int a[maxN];
int dp[maxN];
int rema[maxN];
int remi[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1e18;
    }
    for (int i = n; i >= 1; i--){
        int t = i;
        while(t + 1 <= n and a[t + 1] >= a[i]){
            t = remi[t + 1];
        }
        remi[i] = t;
        t = i;
        while(t + 1 <= n and a[t + 1] <= a[i]){
            t = rema[t + 1];
        }
        rema[i] = t;
    }
    dp[1] = 0;

    for (int i = 1; i < n; i++){
        for (int j = i + 1, mi = a[i], ma = a[i]; j <= max(rema[i], remi[i]); j++){
            mi = min(mi, a[j]);
            ma = max(ma, a[j]);
            if (min(a[i], a[j]) == mi and max(a[i], a[j]) == ma){
                dp[j] = min(dp[j], dp[i] + 1); 
            }
        }
    }

    cout << dp[n];
    return 0;
}