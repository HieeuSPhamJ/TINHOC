#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 1e9 + 7;

double dp[100][100];



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 10;
    for (int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            double t = 0;
            for (int k = 0; k < i; k++){
                 t += dp[k][j];
            }
            t *= j;
            t /= i;
            dp[i][j] = t;
        }
    }

    for (int j = 1; j <= n; j++){
        cout << j << ": ";
        for (int i = 1; i <= n; i++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
*/