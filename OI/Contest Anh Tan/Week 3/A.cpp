#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int dp[20][20];
int cur[20][20];
void add(int &a, int b){
    (a += b) %= mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    k2--;
    swap(k1,k2);
    cur[0][0] = 1;
    cur[1][0] = 1;
    cur[0][1] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= k1; j++){
            for (int k = 0; k <= k2; k++){
                int tmp = cur[j][k];
                if (tmp == 0){
                    continue;
                }
                add(dp[0][k], tmp);
                add(dp[0][k + 1], tmp);
                add(dp[j + 1][k], tmp);
            }
        }
        for (int j = 0; j <= k1; j++){
            for (int k = 0; k <= k2; k++){
                cur[j][k] = dp[j][k];
                dp[j][k] = 0;
            }
        }
    }
    int res = 0;
    for (int j = 0; j <= k1; j++){
        for (int k = 0; k <= k2; k++){
            add(res, cur[j][k]);
        }
    }
    cout << res << endl;
    return 0;
}

/*
11
12
13
21
23
31
32
*/