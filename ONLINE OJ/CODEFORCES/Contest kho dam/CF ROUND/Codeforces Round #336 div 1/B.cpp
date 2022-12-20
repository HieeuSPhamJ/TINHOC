#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 510;

int dp[maxN][maxN];
int a[maxN];

int cal(int l, int r){
    if (l > r){
        dp[l][r] = 0;
        return 0;
    }
    if (a[l] == a[r] and r - l + 1){
        dp[l][r] = 1;
        return 1;
    }
    if (dp[l][r] != 1e18){
        return dp[l][r];
    }
    for (int k = 0; l + k <= r - k; k++){
        if (a[l + k] == a[r - k]){
            dp[l][r] = min(dp[l][r], cal(l + k + 1, r - k - 1) + 1);
        }
        else{
            break;
        }
    }

    for (int mid = l; mid <= r; mid++){
        dp[l][r] = min(dp[l][r], cal(l,mid) + cal(mid + 1, r));
    }

    return dp[l][r];
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
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = 1e18;
        }
    }

    

    cout << cal(1,n);
    return 0;
}

/*
1 4 4 2 3 2 1

*/