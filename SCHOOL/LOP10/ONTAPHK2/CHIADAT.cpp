#include<bits/stdc++.h>
using namespace std;

const int maxN = 10010;

int a[maxN][maxN];
int sum[maxN][maxN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("CHIADAT.INP", "r", stdin);
    freopen("CHIADAT.OUT", "w", stdout);
    int n;
    cin >> n;
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
    int ans = 1e5;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int temp1 = sum[i][j];
            int temp2 = sum[i][n] - temp1;
            int temp3 = sum[n][j] - temp1;
            int temp4 = sum[n][n] - temp1 - temp2 - temp3;

            ans = min(max({temp1, temp2, temp3, temp4}) - min({temp1, temp2, temp3, temp4}), ans);        
        }
    }
    cout << ans;
    return 0;
}