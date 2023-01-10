#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int dp[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> listCoin;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        listCoin.push_back(inp);
    }

    dp[0] = 1;
    
    set <int> listSum;

    for (auto coin: listCoin){
        for (int sum = maxN - 1; sum >= 1; sum--){
            if (sum - coin >= 0 and dp[sum - coin] == 1){
                // cout << sum << " " << coin << endl;
                dp[sum] = 1;
                listSum.insert(sum);
            }
        }
    }

    cout << listSum.size() << endl;
    for (auto sum: listSum){
        cout << sum << ' ';
    }
    return 0;
}