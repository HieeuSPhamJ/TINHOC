#include<bits/stdc++.h>
#define ii pair <int,int>
#define num first
#define cost second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
ii dp[maxN][3];

int cal(int i){
    if (max(a[i - 1], a[i + 1]) < a[i]){
        return 0;
    }
    return max(a[i - 1], a[i + 1]) + 1 - a[i];
}

bool cmp(ii x, ii y){
    if (x.num == y.num){
        return x.cost < y.cost;
    }
    return x.num > y.num;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        
        dp[1][0] = {0,0};
        dp[1][1] = {0,0};

        for (int i = 2; i < n; i++){
            if (dp[i - 1][0].num == dp[i - 1][1].num){
                if (dp[i - 1][0].cost < dp[i - 1][1].cost){
                    dp[i][0] = dp[i - 1][0];
                }
                else{
                    dp[i][0] = dp[i - 1][1];
                }
            }
            else{
                if (dp[i - 1][0].num > dp[i - 1][1].num){
                    dp[i][0] = dp[i - 1][0];
                }
                else{
                    dp[i][0] = dp[i - 1][1];
                }
            }
            vector <ii> lists;
            lists.push_back(dp[i - 1][0]);
            lists.push_back(dp[i - 2][0]);
            lists.push_back(dp[i - 2][1]);
            sort(lists.begin(), lists.end(), cmp);
            ii temp = lists[0];
            dp[i][1] = {temp.num + 1, temp.cost + cal(i)};

        }

        dp[n][0] = dp[n - 1][0];
        dp[n][1] = dp[n - 1][1];

        int ans = 0;
        int ansNum = 0;

        // for (int i = 1; i <= n; i++){
        //     cout << "#" << i << endl;
        //     for (int j = 0; j <= 1; j++){
        //         cout << "TYPE: " << j << "|";
        //         cout << dp[i][j].num << " " << dp[i][j].cost << endl;
        //     }
        // }


        for (int i = 2; i < n; i++){
            for (int j = 0; j <= 1; j++){
                if (ansNum == dp[i][j].num){
                    ans = min(ans,dp[i][j].cost);
                }
                else if (ansNum < dp[i][j].num){
                    ansNum = dp[i][j].num;
                    ans = dp[i][j].cost;
                }
            }
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}