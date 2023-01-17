#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
map <int,int> dp[maxN];
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (i - 2 >= 0){
            dp[i - 2].clear();
        }
        for (auto d: dp[i - 1]){
            if (d.se == 1){
                dp[i][d.fi] = 1;
                dp[i][d.fi xor x] = 1;
            }
        }
    }

    cout << dp[n].size() << endl;

    for (auto d: dp[n]){
        cout << d.fi << " ";
    }


    return 0;
}