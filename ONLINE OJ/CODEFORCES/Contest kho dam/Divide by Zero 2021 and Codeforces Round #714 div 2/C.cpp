#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod =  1e9 + 7;

vector <int> listN;
int dp[12][maxN];

void getListN(int n){
    while(n > 0){
        listN.push_back(n % 10);
        n /= 10;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 9; i++){
        dp[i][0] = 1;
    }

    for (int i = 1; i < maxN - 1; i++){
        for (int dig = 0; dig <= 8; dig++){
            (dp[dig][i] += dp[dig + 1][i - 1]) %= mod;
        }
        (dp[9][i] += dp[0][i - 1] + dp[1][i - 1]) %= mod;
    }

    // for (int i = 0; i <= 100; i++){
    //     for (int dig = 0; dig < 10; dig++){
    //         cout << dp[dig][i] << ' ';
    //     }
    //     cout << endl;
    // }


    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        listN.clear();
        getListN(n);
        int ans = 0;
        for (auto i: listN){
            (ans += dp[i][m]) %= mod;
        }
        
        cout << ans;
        cout << endl;
    }
    return 0;
}