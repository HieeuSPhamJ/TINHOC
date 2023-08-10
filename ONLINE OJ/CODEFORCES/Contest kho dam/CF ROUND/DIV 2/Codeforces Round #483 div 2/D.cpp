#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5e3 + 10;

int a[maxN];
int dp[maxN][maxN];

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
        dp[i][0] = a[i];
        for (int k = 1; i - k >= 1; k++){
            dp[i]
        }
    }


    int test;
    cin >> test;
    while(test--){
        int l, r;
        cin >> l >> r;
        cout << dp[r][(r - l)] << endl;
    }

    return 0;
}