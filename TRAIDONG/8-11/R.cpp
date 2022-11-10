#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[1510][1510];
int dp[1510][1510];

ii d[] = {
    {0, 1},
    {1, 0},
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++){
        dp[i][0] = -1e18;
        dp[0][i] = -1e18;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    int sum = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 and j == 1){
                dp[i][j] = a[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
            sum += dp[i][j];
        }
    }

    cout << sum << endl;
    char t;
    int x, y;
    
    while(cin >> t >> x >> y){
        if (t == 'U'){
            a[x][y]++;
        }
        else{
            a[x][y]--;
        }
        queue <ii> Q;

        Q.push({x - 1,y});

        while(!Q.empty()){
            ii tempV = Q.front();
            Q.pop();
            for (int i = 0; i < 2; i++){
                int u = tempV.fi + d[i].fi;
                int v = tempV.se + d[i].se;
                int temp;
                if (u == 1 and v == 1){
                    temp = a[u][v];
                }
                else {
                    temp = max(dp[u - 1][v], dp[u][v - 1]) + a[u][v];
                }
                // int temp = max(dp[u - 1][v], dp[u][v - 1]) + a[u][v];
                if (1 <= u and u <= n and 1 <= v and v <= n and temp - dp[u][v] != 0){
                    sum += temp - dp[u][v];
                    dp[u][v] = temp;
                    Q.push({u,v});
                }
                
            }
        }

        // for (int i = x; i <= n; i++){
        //     for (int j = y; j <= n; j++){
        //         int temp = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        //         sum += temp - dp[i][j];
        //         dp[i][j] = temp;
        //     }
        // }
        cout << sum << endl;
    }

    return 0;
}