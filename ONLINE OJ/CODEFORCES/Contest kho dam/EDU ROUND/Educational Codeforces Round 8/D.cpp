#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2010;
const int mod = 1e9 + 7;

int m,d;
int dp[maxN][maxN][4];

int cal(string s){
    cout << s << endl;
    int n = s.length() - 1;
    memset(dp,0,sizeof(dp));

    for (int i = 1; i <= 9; i++){
        if (i == d){
            continue;
        }
        int state = 0;
        if (i == s[0] - '0'){
            state = 1;
        }
        else if (i > s[0] - '0'){
            state = 2;
        }
        dp[0][i % m][state]++;
    }

    for (int i = 0; i < m; i++){
        cout << dp[0][i][0] << endl;
    }

    for (int i = 0; i < n - 1; i++){
        for (int div = 0; div < m; div++){
            for (int state = 0; state <= 2; state++){
                int now = dp[i][div][state];
                if (now == 0){
                    continue;
                }
                if (i % 2 == 0){
                    int newState = state;
                    if (newState == 1){
                        if (7 < s[i + 1] - '0'){
                            newState = 0;
                        }
                        else if (7 > s[i + 1] - '0'){
                            newState = 2;
                        }
                    }
                    dp[i + 1][(div * 10 + 7) % m][newState] += now;
                }
                else{
                    for (int dig = 0; dig <= 9; dig++){
                        if (dig == d){
                            continue;
                        }
                        int newState = state;
                        if (newState == 1){
                            if (dig < s[i + 1] - '0'){
                                newState = 0;
                            }
                            else if (dig > s[i + 1] - '0'){
                                newState = 2;
                            }
                        }
                        dp[i + 1][(div * 10 + dig) % m][newState] += now;
                    }
                }
            }
            
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++){
        res += dp[i][0][0];
        res += dp[i][0][1];
        res += dp[i][0][2];
    }
    
    res += dp[n][0][0] + dp[n][0][1];
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> d;
    string a, b;
    cin >> a >> b;
    int ans = cal(b) - cal(a);

    cout << ans;
    return 0;
}