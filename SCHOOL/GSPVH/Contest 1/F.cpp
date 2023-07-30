#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;


const int maxN = 169;

int dp[maxN + 1][maxN + 1][maxN + 1][14];


signed main(){
    // freopen("grassjelly.INP", "r", stdin);
    // freopen("grassjelly.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int w = 1; w <= 13; w++){
        for (int a = w; a <= maxN; a++){
        for (int b = w; b <= a; b++){
        for (int c = w; c <= b; c++){
            int &res = dp[a][b][c][w];
            res = a * b * c / min({a,b,c});
            for (int k = w; a - k >= k; k++){
                res = max(res, dp[a - k][b][c][w] +dp[k][b][c][w]);
            }
            for (int k = w; k <= b - k >= k; k++){
                res = max(res, dp[a][b - k][c][w] +dp[a][k][c][w]);
            }
            for (int k = w; k <= c - k >= k; k++){
                res = max(res, dp[a][b][c - k][w] +dp[a][b][k][w]);
            }
            dp[c][b][a][w] = dp[c][a][b][w] = dp[b][c][a][w] = dp[b][a][c][w] = dp[a][c][b][w] = dp[a][b][c][w];
        }   
        }
        }   
    }
    while(test--){
        int a, b, c, w;
        cin >> a >> b >> c >> w;
        cout << dp[a][b][c][w] << endl;
    }
    // cout << "==END==";
    return 0;
}