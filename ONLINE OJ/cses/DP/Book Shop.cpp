#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e4;

int price[maxN];
int pages[maxN];
int dp[100010];
int tempdp[100010];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> pages[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            tempdp[j] = dp[j];
        }
        for (int j = 1; j <= k; j++){
            dp[j] = tempdp[j];
            if (price[i] <= j){
                dp[j] = max(dp[j], tempdp[j - price[i]] + pages[i]);
            }
        }
    }    
    cout << dp[k];

    return 0;
}