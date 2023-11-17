#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e9 + 9;

int n, ma;

int add(int a, int b){
    return (a + b) % mod;
}

namespace sub1{
    int res = 0;
    int M5, M1, M2;
    void backtrack(int id){
        if (id > n){
            res++;
            return;
        }
        if (M5 < ma){
            M5++;
            backtrack(id + 1);
            M5--;
        }
        if (M5 and M1 != ma){
            M1++;
            M5--;
            backtrack(id + 1);
            M1--;
            M5++;
        }
        if (M5 and M1 and M2 != ma){
            M5--;
            M1--;
            M2++;
            backtrack(id + 1);
            M5++;
            M1++;
            M2--;
        }
        else if (M5 >= 3 and M2 != ma){
            M2++;
            M5 -= 3;
            backtrack(id + 1);
            M5 += 3;
            M2--;
        }
    }
    void solve(){
        cin >> M5 >> M1 >> M2;
        backtrack(1);
        cout << res << endl;
    }
}

    
namespace sub2{
    int M5, M1, M2;
    int dp[51][100][100][100];

    void print(int i, int m5, int m1, int m2){
        int cur = dp[i][m5][m1][m2];
        cout << i << " " << m5 << " " << m1 << " " << m2 << ": " << cur << endl;
    }

    void solve(){
        cin >> M5 >> M1 >> M2;
        int Ga2 = ma - M2;
        dp[0][M5][M1][0] = 1;
        ma = min(201ll,ma);
        for (int i = 0; i <= n; i++){
            // cout << "With: " << i + 1 << endl;
            for (int m5 = 0; m5 <= ma; m5++){
                for (int m1 = 0; m1 <= ma; m1++){
                    for (int m2 = 0; m2 <= Ga2; m2++){
                        int cur = dp[i][m5][m1][m2];
                        if (cur == 0){
                            continue;
                        }
                        // print(i,m5,m1,m2);
                        if (m5 != ma){
                            dp[i + 1][m5 + 1][m1][m2] = add(dp[i + 1][m5 + 1][m1][m2], cur);
                            // cout << "use 5" << endl << " ";
                            // print(i + 1, m5 + 1, m1, m2);
                        }
                        if (m5 and m1 != ma){
                            dp[i + 1][m5 - 1][m1 + 1][m2] = add(dp[i + 1][m5 - 1][m1 + 1][m2], cur);
                            // cout << "use 1" << endl << " ";
                            // print(i + 1, m5 - 1, m1 + 1, m2);
                        }
                        if (m2 != ma and m5 and m1){
                            dp[i + 1][m5 - 1][m1 - 1][m2 + 1] = add(dp[i + 1][m5 - 1][m1 - 1][m2 + 1], cur);
                            // cout << "use 2a" << endl << " ";
                            // print(i + 1, m5 - 1, m1 - 1, m2 + 1);
                        }
                        else if (m2 != ma and m5 >= 3){
                            dp[i + 1][m5 - 3][m1][m2 + 1] = add(dp[i + 1][m5 - 3][m1][m2 + 1], cur);
                            // cout << "use 2b" << endl << " ";
                            // print(i + 1, m5 - 3, m1, m2 + 1);
                        }
                    }
                }
            }
        }
        int res = 0;

        for (int i = 0; i <= ma; i++){
            for (int j = 0; j <= ma; j++){
                for (int k = 0; k <= ma; k++){
                    res = add(res, dp[n][i][j][k]);
                }
            }
        }
        cout << res << endl;
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("ICECREAM.inp", "r")) {
        freopen("ICECREAM.inp", "r", stdin);
        freopen("ICECREAM.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> ma;
    sub1::solve();

    return 0;
}

/*
dp[i][m5][m1][m2][]

2 + 2 * 0 + 4 * 0
1 + 2 * 1 + 4 * 0

*/