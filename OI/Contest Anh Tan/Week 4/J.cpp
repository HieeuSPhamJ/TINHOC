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

const int maxN = 510;
const int maxV = 1e6 + 10;

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

int a[maxN][maxN];
int dp[maxN];
set <int> st[maxV];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("input.inp", "r")) {
        freopen("input.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int res = 0;
    unordered_set <int> s;
    for (int l = 1; l <= n; l++){
        for (auto i: s){
            st[i].clear();
        }
        s.clear();
        for (int i = 1; i <= m + 1; i++){
            dp[i] = m;
        }
        for (int r = l; r <= n; r++){
            // cout << "With: " << l << " " << r << endl;
            for (int i = 1; i <= m; i++){
                int c = a[r][i];
                auto it = st[c].upper_bound(i);
                // cout << i << ": ";
                // for (auto x: st[c]){
                //     cout << x << " ";
                // }
                // cout << endl;
                if (it != st[c].end()){
                    minimize(dp[i], (*it) - 1);
                }
                if (it != st[c].begin()){
                    it--;
                    minimize(dp[*it], i - 1);
                }
                st[c].insert(i);
                s.insert(c);
            }
            for (int i = m; i >= 1; i--){
                minimize(dp[i], dp[i + 1]);
                if (maximize(res, (dp[i] - i + 1) * (r - l + 1))){
                    // cout << i << ": " << res << endl;
                }
            }
            // for (int i = 1; i <= m; i++){
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
        }
    }

    cout << res << endl;
    return 0;
}

/*
1 120 723 035
*/