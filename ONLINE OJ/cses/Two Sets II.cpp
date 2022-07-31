#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 1e9 + 7;

int dp[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> listCoin;
    int totalSum = 0;
    for (int i = 1; i <= n; i++){
        listCoin.push_back(i);
        totalSum += i;
    }

    dp[0] = 1;

    // cout << totalSum << endl;

    for (auto coin: listCoin){
        // cout << coin << endl;
        for (int sum = totalSum; sum >= 1; sum--){
            if (sum - coin >= 0 and dp[sum - coin] != 0){
                // cout << sum << " " << coin << endl;
                (dp[sum] += dp[sum - coin]) %= mod;
            }
            // cout << sum << ":" << dp[sum] << " ";
        }
        // cout << endl;
    }

    

    // for (int i = 1; i <= 100; i++){
    //     cout << i << ": " << dp[i] << endl;
    // }

    if (totalSum % 2 != 0){
        cout << 0;
    }
    else{
        cout << dp[totalSum / 2] / 2;
    }

    return 0;
}