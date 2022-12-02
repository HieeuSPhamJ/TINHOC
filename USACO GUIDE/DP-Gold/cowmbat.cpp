#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int trans[30][30];
int ans[maxN];
int dp[maxN][30];

signed main(){
    //freopen("cowmbat.in", "r", stdin);
    //freopen("cowmbat.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - 'a' + 1;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            cin >> trans[i][j];
        }
    }

    for (int k = 1; k <= m; k++){
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= m; j++){
                trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
            }
        }
    }


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 26; j++){
            dp[i][j] = 1e18;
        }
    }

    for (int i = k; i <= n; i++){
        for (int j = 1; )
    }


    return 0;
}