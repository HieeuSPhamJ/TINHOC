#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 10;

int a[maxN];
int dp[maxN];
int last[maxN];
vector <int> bag[maxN];

int main(){
    // freopen("BALO1.INP", "r", stdin);
    // freopen("BALO1.OUT", "w", stdout);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
        last[i] = - 1;
        bag[i].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        if (dp[i] < dp[i - 1]){
            bag[i] = bag[i - 1];
            dp[i] = dp[i - 1];
        }
        for (int j = 1; j < i; j++){
            if (dp[j] + a[i] <= w){
                // dp[i] = max(dp[i], dp[j] + a[i]);
                if (dp[i] < dp[j] + a[i]){
                    dp[i] = dp[j] + a[i];
                    bag[i] = bag[j];
                    bag[i].push_back(i);
                }
            }

            if (a[j] + a[i] <= w){
                // dp[i] = max(dp[i], a[j] + a[i]);
                if (dp[i] < a[j] + a[i]){
                    dp[i] = a[j] + a[i];
                    vector <int> temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[j]);
                    bag[i] = temp;
                }

            } 
        }
    }
    cout << dp[n] << endl;
    for (int i = 0; i < bag[n].size(); i++){
        cout << a[bag[n][i]] << ' ';
    }

    return 0;
}