#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN  = 2e5 + 10;
const int inf = 100;

int n;
int a[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = 1e18;
        }
        dp[n + 1] = 0;
        for (int i = n; i >= 1; i--){
            if (i + a[i] <= n){
                dp[i] = dp[i + a[i] + 1];
            }
            dp[i] = min(dp[i], dp[i + 1] + 1);
        }

        cout << dp[1] << endl;
    }
    return 0;
}

/*
0 1 2 3 4 5 6 7
0 3 3 4 5 2 6 1
0 0 * * * 0 * *
*/