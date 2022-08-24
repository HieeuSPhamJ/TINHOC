#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6;

set <int> tempA;
int dp[maxN * 4];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector <int> a;

    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        inp %= m;
        a.push_back(inp);
    }


    for (auto i: a){
        for (int j = maxSum; j >= 0; j--){
            if (j - i >= 0 and dp[j - i] == 1){
                dp[j] = 1;
            }
        }
    }

    for (int i = m; i <= maxSum; i+=m){
        if (dp[i] == 1){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}