#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

int m, d;
ii dp[2020][2020][4];

void init(){
    for (int i = 0; i <= 2005; i++){
        for (int j = 0; j <= 2005; j++){
            for (int k = 0; k <= 9; k++){
                for (int s = 0; s <= 3; s++){
                    dp[i][j][s] = {0, 0};
                }
            }
        }
    }
}

int solve(string s){
    cout << "Solve: " << s << endl;
    int n = s.length();
    s = '-' + s;
    init();
    // for (int i = 0; i <= 9; i++){
    //     int state = 0;
    //     if (i == s[1] - '0'){
    //         state = 1;
    //     }
    //     if (i > s[1] - '0'){
    //         state = 2;
    //     }

    //     // dp[1][i % m][state] += (i == d);

    //     // cout << i << ": " << 1 << " " << i % m << " " << state << endl;
    //     // cout << dp[1][i % m][state] << endl;
    // }

    for (int i = 1; i <= n; i++){
        for (int divM = 0; divM < m; divM++){
            for (int state = 0; state <= 2; state++){
                ii now = dp[i][divM][state];
                // if (now == 0){
                //     continue;
                // }
                cout << "Set: " << i << " " << divM << " " << state << endl;
                cout << "dp: " << now.fi << " " << now.se << endl; 
                for (int dig = 0; dig <= 9; dig++){
                    int newState = state;
                    if (state == 1){
                        newState == 0;
                        if (dig == s[i + 1] - '0'){
                            newState = 1;
                        }
                        else if (dig > s[i + 1] - '0'){
                            newState = 2;
                        }
                    }
                    int temp = now.fi;
                    if (i % 2 and dig == d){
                        temp += now.se;
                    }
                    ii next = dp[i + 1][((divM * 10) + dig) % m][newState];
                    next.fi += temp;
                    next.se += now;
                    dp[i + 1][((divM * 10) + dig) % m][newState] = next;
                    cout << "Dig: " << dig << " State: " << newState << " dp:  " << next.fi << " " << next.se << endl;
                }
            }
        }
    }
    cout << "----" << endl;
    int ans = 0;
    for (int i = 1; i < n; i++){
        for (int state = 0; state <= 2; state++){
            (ans += dp[i][0][state]) %= mod;
            cout << i << " " << state << " " << dp[i][0][state] << endl;
        }
    }
    for (int state = 0; state <= 1; state++){
        (ans += dp[n][0][state]) %= mod;
        cout << n << " " << state << " " << dp[n][0][state] << endl;
    }
    cout << "=======" << endl << endl;
    return ans;
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
    int x = 0, y = 0;
    // x = solve(a).fi;
    y = solve(b).fi;
    cout << x << " " << y << endl;
    return 0;
}