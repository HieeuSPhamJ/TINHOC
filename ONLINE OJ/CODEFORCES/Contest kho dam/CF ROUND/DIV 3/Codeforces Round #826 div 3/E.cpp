#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
int a[maxN];
int dp[maxN];
vector <int> preDP[maxN];
 
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            preDP[i].clear();
            dp[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(i + a[i] <= n){
                preDP[i + a[i]].push_back(i - 1);
            }
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            int last = i - a[i];
            if(last >= 1){
                dp[i] = max(dp[i] , dp[last - 1]);
            }
            for (auto u: preDP[i]){
                dp[i] = max(dp[i] , dp[u]);
            }
        }
        if(dp[n]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;   
}
