#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 15100;

int dp[maxN];
int a[maxN];

int main(){
    freopen("DIACAN.INP", "r", stdin);
    freopen("DIACAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int maxSum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxSum += a[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int sum = m; sum >= 1; sum--){
            if (sum - a[i] >= 0){
            if (dp[sum - a[i]] == 1){
                dp[sum] = 1;
            }
            }
            // cout << dp[sum] << ' ';
        }
        // cout << endl;
    }
    if (dp[m] == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    


    return 0;
}