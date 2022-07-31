#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define um unordered_map
#define int long long
using namespace std;

um <int, um<int, int>> dp[95];
int nextSum[95];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int countN = 1; 
    for (int sum = 0; sum <= n; countN++){
        sum += countN;
        nextSum[countN] = sum;
        // cout << countN << " " << sum << endl;
    }
    // cout << countN << endl;

    for (int i = 1; i < n; i++){
        dp[1][i][i]++;
    }
    
    for (int i = 1; i <= countN; i++){
        for (int sum = nextSum[i]; sum < n; sum++){
            for (int lastDig = i; lastDig < n; lastDig++){
                int nowDP = dp[i][sum][lastDig];
                if (nowDP == 0){
                    continue;
                }
                // cout << "------" << endl;
                // cout << i << " " << sum << " " << lastDig << endl;
                // cout << nowDP << endl;
                for (int dig = lastDig + 1; dig + sum <= n; dig++){
                    dp[i + 1][sum + dig][dig] += nowDP;
                    // cout << i + 1 << " " << sum + dig << " " << dig << endl;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= countN; i++){
        for (int lastDig = 0; lastDig < n; lastDig++){
            ans += dp[i][n][lastDig];
        }
    }
    cout << ans;
    return 0;
}