#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int dp[maxN];
vector <int> divi[maxN];
int a[maxN];
int MA = 0;

void init(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= maxN; i++){
        dp[i] = 1e18;
    }
    for (int i = 2; i <= maxN; i++){
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 2; i * j <= maxN; j++){
            dp[i * j] = min(dp[i * j], dp[max(i,j)] + 1);
        }
    }
    for (int i = 4; i <= maxN; i++){
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
}

void initSmall(){
    int count = 0;
    for (int i = 2; i <= MA + 5; i++){
        for (int j = 2; i * j <= MA + 5; j++){
            divi[i * j].push_back(i);
        }
    }

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= MA + 5; i++){
        dp[i] = 1e18;
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (auto j: divi[i]){
            if (i % j == 0 and i / j != 1){
                // cout << j << endl;
                dp[i] = min(dp[i], dp[max(j, i / j)] + 1);
            }
        }
        // cout << "=" << dp[i] << endl;
        // cout << dp[i] << ", ";
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    // freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    
    for (int i = 1; i <= test; i++){
        cin >> a[i];
        MA = max(MA, a[i]);
    }
    
    if (MA <= 3000){
        initSmall();
    }
    else{
        init();
    }

    for (int i = 1; i <= test; i++){
        cout << dp[a[i]] << endl;
    }
    return 0;
}