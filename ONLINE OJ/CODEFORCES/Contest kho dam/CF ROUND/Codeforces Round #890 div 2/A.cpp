#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5;

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
    dp[0] = 0;
    a[0] = 1;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = max(dp[i - 1], a[i]);
        }
        int cnt = n;
        for(;dp[cnt] == a[cnt];cnt--){
            // cout << "Cac";
        }
        cout << dp[cnt] << endl;
    }
    return 0;
}