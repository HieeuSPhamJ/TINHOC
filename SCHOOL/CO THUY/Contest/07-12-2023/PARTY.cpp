#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2010;

int dp[maxN][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("PARTY.inp", "r")) {
        freopen("PARTY.inp", "r", stdin);
        freopen("PARTY.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    deque <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (ls.empty()){
            ls.push_back(x);
            continue;
        }
        if (ls.back() * x >= 0){
            ls[(int)ls.size() - 1] += x;
        }
        else{
            ls.push_back(x);
        }
    }

    while(ls.size() and ls.front() <= 0){
        ls.pop_front();
    }
    while(ls.size() and ls.back() <= 0){
        ls.pop_back();
    }
    if (ls.empty()){
        cout << 0 << endl;
        return 0;
    }

    // for (auto i: ls){
    //     cout << i << " ";
    // }
    // cout << endl;
    int res = 0;
    for (int i = 0; i < (int)ls.size(); i++){
        for (int j = 1; j <= k; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ls[i]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            res = max({res, dp[i + 1][j], dp[i + 1][j + 1]});
        }
    }

    cout << res << endl;
    return 0;
}