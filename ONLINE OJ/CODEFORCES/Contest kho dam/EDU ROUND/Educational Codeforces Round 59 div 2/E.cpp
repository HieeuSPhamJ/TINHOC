#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[110];
int p[110];
int cost[110];
int dp[110][110][110];

int cal(int l, int r, int k){
    if (l > r or r - l + 1 < k){
        return 0;
    }
    if (p[r] - p[l - 1] == r - l + 1 or p[r] == p[l - 1]){
        return dp[l][r][k] = cost[k];
    }
    if (dp[l][r][k] != 0){
        return dp[l][r][k];
    }

    int &res = dp[l][r][k];

    for (int i = l; i <= r; i++){
        if (a[i] == a[l]){
            res = max(res, cal(l,i,k))
        }
    }

    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - '0';
        p[i] = p[i - 1] + a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }

    cout << cal(1,n,0);

    return 0;
}

/*
1 2 3 4 5 6 7
1 1 0 1 0 0 1

3 6 9 100 103 106 109 

*/