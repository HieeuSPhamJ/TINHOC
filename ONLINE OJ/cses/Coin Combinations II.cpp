#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e6 + 10;
const int mod = 1e9 + 7;

int dp[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> lists;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        lists.push_back(inp);
        // dp[inp]++;
    }
    dp[0] = 1;
    for (int i = 0; i < k; i++){
        if (dp[i] == 0){
            continue;
        }
        cout << "#" << i << " " << dp[i] << endl;
        for (auto num: lists){
            cout << i + num << "," << dp[i + num] << " ";
            (dp[i + num] += dp[i]) %= mod;
        }
        cout << endl;
    }
    cout << dp[k];
    return 0;
}