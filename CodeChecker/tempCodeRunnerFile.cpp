#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

string s;
int dp[5010][5010];
int pal[5010][5010];

int cal(int l, int r){
    if (r < l){  
        // cout << l << " " << r << " " << 0 << endl;
        return 0;
    }
    if (dp[l][r] != 0){
        // cout << l << " " << r << " " << dp[l][r] << endl;
        return dp[l][r];
    }
    if (l + 1 == r and s[l] == s[r]){
        pal[l][r] = 1;
    }
    else if (l == r){
        pal[l][r] = 1;
    }
    else if (s[l] == s[r]){
        pal[l][r] = pal[l + 1][r - 1];
    }

    dp[l][r] = cal(l + 1, r) + cal(l, r - 1) - cal(l + 1, r - 1) + pal[l][r];
    // cout << l << " " << r << " " << dp[l][r] << endl;
    return dp[l][r];
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int n = s.length() - 1;
    int test;
    cin >> test;
    for (int i = 0; i <= n; i++){
        dp[i][i] = 1;
        pal[i][i] = 1;
    }
    while(test--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << cal(l,r) << endl;    
    }
    return 0;
}

/*
0123456789
aaaaabbbaa

*/