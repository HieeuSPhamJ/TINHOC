#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int LCM(int a, int b){
    return a / __gcd(a,b) * b;
}

int dp[50];

int cal(int n){
    int res = 0;
    dp[2] = 1;
    for (int i = 3, lcm = 2; i <= min(42ll,n); i++){
        dp[i] = 1;
        for (int j = 1; j <= i; j++){
            if (i % j == 0){
            }
            else{
                dp[i] = dp[j] + 1;
                break;
            }
        }
        cout << i << ": " << dp[i] << " " << lcm << " " << LCM(i,lcm) << endl;
        int t = n / lcm - n / LCM(lcm,i) - (lcm == 2);
        cout << t * (dp[i] + 1) << endl;
        lcm = LCM(lcm, i);
        res += t * (dp[i] + 1);
        if (dp[i] == 2){
            cout << "+" << dp[i] << endl;
            res += dp[i];
        }
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << cal(b) - cal(a - 1);
    // cout << cal(b) << endl;
    return 0;
}

/*
5 342 931 457 063 200
219 060 189 739 591 200
*/