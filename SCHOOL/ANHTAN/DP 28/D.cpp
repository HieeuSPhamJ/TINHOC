#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define x first
#define cost second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e4;

ii a[maxN];
ii b[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> b[i].x >> b[i].cost;
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++){
        a[i] = b[n - i + 1];
    }
    a[0] = a[1];

    for (int i = 1; i <= n; i++){
        int tempAns = 1e18;
        for (int j = i - 1, totalDis = 0; j >= 0; j--){
            totalDis += abs(a[i].x - a[j + 1].x);
            tempAns = min(tempAns, dp[j] + totalDis + a[i].cost);
        }
        dp[i] = tempAns;
    }

    cout << dp[n];
    return 0;
}