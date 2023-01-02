#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

vector <int> a[maxN];
int dp[maxN][4][12];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for (int j = 1, sum = 3; j <= m; j++){
            int c, d;
            cin >> c >> d;
            sum -= c;
            if (sum >= 0){
                a[i].push_back(d);
            }
        }
    }
    for (int i = 0; i < a[1].size(); i++){
        dp[1][i][i + 1] = dp[1][i][i] + a[1][i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < a[i].size(); j++){
            for (int k = 0; k < 10; k++){
              
            }
        }
    }

    int res = 0;

    for (int i = 0; i < a[n].size(); i++){
        for (int j = 0; j < 10; j++){
            res = max(res, dp[n][i][j]);
        }
    }

    cout << res;
    return 0;
}