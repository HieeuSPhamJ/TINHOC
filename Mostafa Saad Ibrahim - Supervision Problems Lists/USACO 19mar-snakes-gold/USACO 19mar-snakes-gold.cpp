#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 410;

int a[maxN];

unordered_map <int,int> dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    vector <int> Nests;
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        Nests.push_back(a[i]);
    }

    sort(Nests.begin(), Nests.end());

    for (int i = 1; i <= n; i++){
        for (int turn = 0; turn <= k; turn++){
            for (auto nest: Nests){
                dp[i][turn][nest] = 1e18;
                if (turn == 0){
                    if (nest >= a[i]){
                        if (dp[i - 1][0][nest] != 1e18){
                            dp[i][0][nest] = dp[i - 1][0][nest] + (nest - a[i]);
                        }
                    }
                }
            }
        }
    }


    for (int i = 1; i <= n; i++){
        for (int turn = 1; turn <= k; turn++){
            for (auto nest: Nests){
                if (nest - a[i] < 0){
                    continue;
                }
                int tempAns = 1e18;
                for (auto lastNest: Nests){
                    if (lastNest == nest){
                        tempAns = min(tempAns, dp[i - 1][turn][lastNest] + (nest - a[i]));
                    }
                    else{
                        tempAns = min(tempAns, dp[i - 1][turn - 1][lastNest] + (nest - a[i]));    
                    }
                }
                dp[i][turn][nest] = tempAns;
            }
        }
    }

    int ans = 1e18;

    for (auto nest: Nests){
        for (int turn = 0; turn <= k; turn++){
            ans = min(ans, dp[n][turn][nest]);
        }
    }

    cout << ans;
    return 0;
}