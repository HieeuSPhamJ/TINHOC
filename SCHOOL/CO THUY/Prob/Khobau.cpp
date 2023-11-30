#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1010;
const int mod = 1e9 + 7;

int dp[maxN];

signed main(){
    // freopen("Khobau.INP", "r", stdin);
    // freopen("Khobau.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    
    while(test--){
        int n;
        cin >> n;
        memset(dp,0,sizeof(dp));
        vector <ii> a;
        set <int> val;
        for (int i = 0; i < n; i++){
            int inp;
            cin >> inp;
            a.push_back({inp,0});
            val.insert(inp);
        }
        for (int i = 0; i < n; i++){
            cin >> a[i].se;
        }

        dp[0] = 1;

        sort(a.rbegin(), a.rend());

        for (auto v: val){
            vector <int> lists;
            while(a.back().fi <= v){
                lists.push_back(a.back().se);
                a.pop_back();
            }
            // cout << "DP: ";
            // for (int i = 0; i <= 10; i++){
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
            for (auto i: lists){
                // cout << "Index: " << i << endl;
                for (int s = 1000; s >= 0; s--){
                    if (s + i > v){
                        continue;
                    }
                    // cout << s << " ";
                    (dp[s + i] += dp[s]) %= mod;
                }
                // cout << endl;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 1000; i++){
            (ans += dp[i]) %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}