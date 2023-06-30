#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int po[5];
int dp[maxN][6][2];
int a[maxN];
signed main(){
    po[0] = 1;
    po[1] = 10;
    po[2] = 100;
    po[3] = 1000;
    po[4] = 10000;
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        reverse(all(s));
        int n = s.length();
        for (int i = 0; i <= n; i++){
            for (int ma = 0; ma <= 4; ma++){
                for (int k = 0; k <= 1; k++){
                    dp[i][ma][k] = -1e18; 
                }   
            }
        }
        for (int i = 1; i <= n; i++){
            a[i] = s[i - 1] - 'A';
            // cout << a[i];
        }
        // cout << endl;
        
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++){
            for (int ma = 0; ma <= 4; ma++){
                for (int k = 0; k <= 1; k++){
                    int curr = dp[i][ma][k];
                    if (curr == -1e18){
                        continue;
                    }
                    // cout << i << " " << ma << " " << k << ": " << curr << endl;
                    if (ma <= a[i + 1]){
                        if (dp[i + 1][a[i + 1]][k] < curr + po[a[i + 1]]){
                            // cout << "-> " << i + 1 << " " << a[i + 1] << " " << k << " " <<  curr + po[a[i + 1]] << endl;
                        }
                        dp[i + 1][a[i + 1]][k] = max(dp[i + 1][a[i + 1]][k], curr + po[a[i + 1]]);
                    }
                    else{
                        if (dp[i + 1][ma][k] < curr - po[a[i + 1]]){
                            // cout << "-> " << i + 1 << " " << ma << " " << k << " " <<  curr - po[a[i + 1]] << endl;
                        }
                        dp[i + 1][ma][k] = max(dp[i + 1][ma][k], curr - po[a[i + 1]]);
                    }
                    if (k == 0){
                        for (int to = 0; to <= 4; to++){
                            if (to == a[i + 1]){
                                continue;
                            }
                            if (ma <= to){   
                                if (dp[i + 1][to][k + 1] < curr + po[to]){
                                    // cout << "-> " << i + 1 << " " << to << " " << k + 1 << " " << curr + po[to] << endl;
                                }
                                dp[i + 1][to][k + 1] = max(dp[i + 1][to][k + 1],curr + po[to]);
                            }
                            else{
                                if (dp[i + 1][ma][k + 1] < curr - po[to]){
                                    // cout << "-> " << i + 1 << " " << ma << " " << k + 1 << " " << curr - po[to] << endl;
                                }
                                dp[i + 1][ma][k + 1] = max(dp[i + 1][ma][k + 1], curr - po[to]);
                            }
                        }
                    }
                }   
            }
        }
        int res = -1e18;
        for (int ma = 0; ma <= 4; ma++){
            res = max({res, dp[n][ma][0], dp[n][ma][1]});
        }
        cout << res << endl;
    }
    return 0;
}

/*
1 2 3 4 5 6 7 8
0 2 3 1 0 0 0 3
        4
1 +100 +1000 -10 -1
*/