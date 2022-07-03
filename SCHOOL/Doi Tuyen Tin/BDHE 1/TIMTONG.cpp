#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int dp[maxN];
int a[maxN];

int main(){
    freopen("TIMTONG.INP", "r", stdin);
    freopen("TIMTONG.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int maxSum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxSum += a[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        for (int sum = maxSum; sum >= 1; sum--){
            if (sum - a[i] >= 0){
            if (dp[sum - a[i]] == 1){
                dp[sum] = 1;
            }
            }
            // cout << dp[sum] << ' ';
        }
        // cout << endl;
    }
    
    for (int i = 1; i <= maxSum + 10; i++){
        if (dp[i] == 0){
            cout << i;
            break;
        }
    }
    


    return 0;
}