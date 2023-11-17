#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool dp[2110][2110];

signed main(){
    freopen("share.INP", "r", stdin);
    freopen("share.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int n;
    cin >> n;
    dp[0][0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        sum += x;
        for (int s1 = 2000; s1 >= 0; s1--){
            for (int s2 = 2000; s2 >= 0; s2--){
                dp[s1 + x][s2] |= dp[s1][s2];
                dp[s1][s2 + x] |= dp[s1][s2];   
            }
        }
    }
    int res = 1e18;
    for (int s1 = 2000; s1 >= 0; s1--){
        for (int s2 = 2000; s2 >= 0; s2--){
            if (dp[s1][s2]){
                vector <int> ls;
                ls.push_back(s1);
                ls.push_back(s2);
                ls.push_back(sum - s1 -s2);
                sort(all(ls));
                res = min(res, ls.back());
            }
        }
    }

    cout << res << endl;

    return 0;
}