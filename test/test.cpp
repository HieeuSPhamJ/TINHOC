#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e8 + 10;

int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 100;
    int res = 0;
    int ma = 0;
    int la = 0;
    set <int> s;
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j <= i; j++){
            if (i % j == 0){
                res++;
            }
            else{
                dp[i] = dp[j] + 1;
                break;
            }
        }
        ma = max(ma,dp[i]);
        if (dp[i] == 3){
            cout << i << " ";
            if (la == 0){
                la = i;
                continue;
            }
            // if (i - la == 6){
            //     cout << la << " " << i << endl;
            //     break;
            // }
            // s.insert(i - la);
            la = i;
        }
        // cout << i << ": " << dp[i] << endl;
    }
    for (auto i: s){
        cout << i << " ";
    }
    return 0;
}