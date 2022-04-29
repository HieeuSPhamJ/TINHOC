#include<bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int a[maxN][maxN];
int sum[maxN][maxN];


int main(){
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

        }
    }
    int ans = 0;
    for (int i = m; i <= n; i++){
        for (int j = m; j <= n; j++){
            ans = max(ans, sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]);
        }
    }
    cout << ans;
    return 0;
}