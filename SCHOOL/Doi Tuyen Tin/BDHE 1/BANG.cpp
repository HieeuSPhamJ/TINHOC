#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 110;

int n, m;
int dp[maxN][maxN];
int a[maxN][maxN];

void printDP(){
    
    // cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("BANG.INP", "r", stdin);
    freopen("BANG.OUT", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
        }
    }
    
    // printDP();

    int ans = 0;

    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[i][m]);
    }

    cout << ans;

    return 0;
}