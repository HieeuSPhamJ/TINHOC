#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int dp[2510][5010];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    
    vector <int> listUsed;
    vector <int> listEmpty;

    for (int i = 0; i < 2510; i++){
        for (int j = 0; < 5010; j++){
            dp[i][j] = 1e18;
        }
    }

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        if (inp == 1){
            listUsed.push_back(i);
        }
        else{
            listEmpty.push_back(i);
        }
    }

    for (int j = 0; j < listEmpty.size(); j++){
        dp[j] = abs(listEmpty[j] - listUsed[0]);
    }

    for (int i = 1; i < listUsed.size(); i++){
        for (int j = 0; j < listEmpty.size(); j++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }


    return 0;
}