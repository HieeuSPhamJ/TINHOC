#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int inf = 1e18;

int a[maxN];
int b[maxN];
int dp[maxN][3];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            if (x == '1'){
                b[i] = 1;
            }
            else{
                b[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
            cin >> a[i];
        }

        if (b[n]){
            dp[n][1] = a[n];
        }

        for (int i = n - 1; i >= 1; i--){
            if (b[i]){
                dp[i][1] = max({dp[i][1], dp[i + 1][0] + a[i], dp[i + 1][1] + a[i], dp[i + 1][2] + a[i]});
            }
            if (b[i + 1]){
                dp[i][2] = max({dp[i][2], dp[i + 1][0] + a[i], dp[i + 1][1] + a[i], dp[i + 1][2] + a[i]});
            }
            dp[i][0] = max({dp[i][0], dp[i + 1][0], dp[i + 1][1], dp[i + 1][2]});
        }

        cout << max({dp[1][0], dp[1][1], dp[1][2]});

        cout << endl;
    }
    return 0;
}