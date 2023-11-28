#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int dp[maxN];

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

void init(){
    dp[1] = 1;
    for (int i = 2; i < maxN; i++){
        dp[i] = lcm(dp[i - 1],i);
        cout << dp[i] << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    
    int n;
    while(cin >> n){
        int x = dp[n];
        while(x % 10 == 0){
            x /= 10;
        }
        cout << x << " " << x % 10 << endl;
    }

    return 0;
}