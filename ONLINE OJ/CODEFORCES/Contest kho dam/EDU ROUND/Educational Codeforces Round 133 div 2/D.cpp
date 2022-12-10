#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

unordered_map <int, int> dp[maxN];
int maxVal[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        maxVal[i] = 0;
    }
    // cout << n << k << endl;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxVal[i]; j++){
            if (dp[i][j] == 0){
                continue;
            }
            // cout << i << "," << j << ": ";
            for (int x = 1; i + x * (k + j) <= n; x++){
                int newI = i + x * (k + j);
                // cout << newI << "," << j + 1 << " ";
                dp[newI][j + 1] += dp[i][j];
                maxVal[newI] = max(maxVal[newI], j + 1);
            }
            cout << endl;
        }
    }
    for (int i = 1; i <= n; i++){
        int ans = 0;
        for (int j = 0; j <= maxVal[i]; j++){
            ans += dp[i][j];
        }
        cout << ans << ' ';
    }
    return 0;
}

/*
    
*/