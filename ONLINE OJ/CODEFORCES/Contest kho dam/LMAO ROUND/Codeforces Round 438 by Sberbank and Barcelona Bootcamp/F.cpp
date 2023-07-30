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
int dp[22][maxN];

int cost(int l, int r){
    return 0;
}

void cal(int k, int l, int r, int optl, int optr){
    if (l > r){
        return;
    }
    int i = (l + r) / 2;
    int opt = -1;
    int &cur = dp[k][i];
    for (int j = optl; j < min(i,optr); j++){
        if (cur < dp[k - 1][j - 1] + cost(j - 1,i)){
            cur = dp[k - 1][j - 1] + cost(j,i);
            opt = j;
        }
    }
    cal(k, 1, i - 1, optl, opt);
    cal(k, i + 1, r, opt, optr);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int j = 1; j <= k; j++){
        cal(j,1,n,1,n);
    }

    cout << dp[k][n];

    return 0;
}