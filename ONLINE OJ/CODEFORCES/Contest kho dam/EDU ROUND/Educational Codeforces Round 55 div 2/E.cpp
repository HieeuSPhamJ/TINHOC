#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 10;

int a[maxN];

int dp[3][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, val;
    cin >> n >> val;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int iii = 1; iii <= n; iii++){
        int i = iii % 2;
        dp[i][]
    }

    return 0;
}