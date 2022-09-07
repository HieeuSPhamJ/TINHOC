#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxMask = (1 << 8) - 1;
const int maxN = 1e4 + 10;

int n;
int minAns = -1e18;
int a[maxN][10];
int dp[maxN][maxMask + 10];
int sum[maxN][maxMask + 10];

vector <int> pre[maxN];

void init(){
    for (int mask = 0; mask <= maxMask; mask++){
        if ((mask & (mask >> 1)) == 0){
            for (int preMask = 0; preMask <= maxMask; preMask++){
                if ((preMask & (preMask >> 1)) == 0 and (mask & preMask) == 0){
                    pre[mask].push_back(preMask);
                }
            }
        }
    }
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
                }
            }
            sum[i][mask] = tempSum;
        }
    }
    for (int mask = 0; mask <= maxMask; mask++){
        dp[0][mask] = sum[0][mask];
    }
}

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

    init();

    for (int i = 1; i < n; i++){
        for (int mask = 0; mask <= maxMask; mask++){
            for (auto preMask: pre[mask]){ 
                dp[i][mask] = max(dp[i][mask], dp[i - 1][preMask] + sum[i][mask]);
            }
        }
    }

    int ans = 0;

    for (int mask = 0; mask <= maxMask; mask++){
        ans = max(ans, dp[n - 1][mask]);
    }

    if (ans == 0){
        cout << minAns;
        return 0;
    }
    
    cout << ans;

    return 0;
}
