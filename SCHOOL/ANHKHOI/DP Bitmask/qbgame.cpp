#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e4 + 10;
const int maxMask = (1 << 8) - 1;

int n;
int a[maxN][10];
int sum[maxN][maxMask + 10];
int dp[maxN][maxMask + 10];
int minAns = -1e18;

vector <int> pre[maxN];


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < n; j++){
            cin >> a[j][i];
            minAns = max(a[j][i], minAns);
        }
    }

    // cout << maxMask << endl;

    int temp = 0;

    for (int mask = 0; mask <= maxMask; mask++){
        if ((mask & (mask >> 1)) == 0){
            for (int preMask = 0; preMask <= maxMask; preMask++){
                if ((preMask & (preMask >> 1)) == 0 and (mask & preMask) == 0){
                    pre[mask].push_back(preMask);
                }
            }
            // temp += pre[mask].size();
            // cout << pre[mask].size() << endl;
        }
    }

    // cout << temp;

    for (int i = 0; i < n; i++){
        for (int mask = 0; mask <= maxMask; mask++){
            string s = "";
            int tempMask = mask;
            
            if (tempMask == 0){
                s += '0';
            }

            while(tempMask > 0){
                s += tempMask % 2 + '0';
                tempMask /= 2;
            }

            int tempSum = 0;

            for (int j = 0; j < s.size(); j++){
                if (s[j] == '1'){
                    tempSum += a[i][j];
                    // cout << a[i][j] << ' ';
                }
            }

            // cout << endl;

            sum[i][mask] = tempSum;

            // cout << mask << ' ' << s << ' ' << tempSum << endl;

        }
    }

    for (int mask = 0; mask <= maxMask; mask++){
        dp[0][mask] = sum[0][mask];
    }


    for (int i = 1; i < n; i++){
        for (int mask = 0; mask <= maxMask; mask++){
            for (auto preMask: pre[mask]){ 
                // if (dp[i][mask] < dp[i - 1][preMask] + sum[i][mask]){
                //     cout << i << endl;
                //     cout << mask << ' ' << preMask << endl;
                // }
                dp[i][mask] = max(dp[i][mask], dp[i - 1][preMask] + sum[i][mask]);
            }
        }
    }

    int ans = 0;

    for (int mask = 0; mask <= maxMask; mask++){
        // if (dp[n - 1][mask] > ans){
        //     cout << mask << endl;
        // }
        ans = max(ans, dp[n - 1][mask]);
    }

    if (ans == 0){
        cout << minAns;
        return 0;
    }
    
    cout << ans;

    return 0;
}