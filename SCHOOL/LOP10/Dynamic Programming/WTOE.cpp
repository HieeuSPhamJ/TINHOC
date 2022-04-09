#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;

int dp[maxN][maxN];
int a[maxN][maxN];
int last[maxN][maxN];

void backtracking(int index, int m){
    if (last[index][m] == -1){
        return;
    }
    backtracking(last[index][m], m - 1);
    cout << index << ' ';
}

int main(){
    freopen("WTOE.INP", "r", stdin);
    freopen("WTOE.OUT", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 2; i++){
        for (int j = 0; j <= m + 2; j++){
            dp[i][j] = 0;
            last[i][j] = -1;
        }
    }
    
    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            dp[i][j] = a[i][j];
            int temp = max({dp[i][j - 1], dp[i + 1][j - 1], dp[i - 1][j - 1]});
            
            if (dp[i][j - 1] == temp){
                last[i][j] = i;
            }
            else if (dp[i + 1][j - 1] == temp){
                last[i][j] = i + 1;
            }
            else if (dp[i - 1][j - 1] == temp){
                last[i][j] = i - 1;
            }
            dp[i][j] += temp;
        }
    }
    int ans = 0;
    int index = 0;
    for (int i = 1; i <= n; i++){
        if (dp[i][m] >= ans){
            ans = dp[i][m];
            index = i;
        }
    }
    cout << ans << ' ';
    // cout << index << ' ' << ans;
    cout << endl;
    backtracking(index, m);

    return 0;
}