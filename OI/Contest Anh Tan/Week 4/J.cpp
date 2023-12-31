#include"bits/stdc++.h"
// #define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 510;
const int maxV = 500 * 500 + 10;

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
int dp[maxN][maxN];
int la[maxV];

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
    vector <int> ss;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            ss.push_back(a[i][j]);
        }
    }

    sort(all(ss));
    ss.erase(unique(all(ss)), ss.end());
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            a[i][j] = lower_bound(all(ss), a[i][j]) - ss.begin() + 1;
        }
    }
    int res = 0;
    for (int up = 1; up <= n; up++){
        for (int i = 1; i <= m; i++){
            la[a[up][i]] = 0;
        }
        // cout << "With: " << up << " " << up << endl;
        for (int i = 1; i <= m; i++){
            dp[up][i] = la[a[up][i]] + 1;
            maximize(dp[up][i], dp[up][i - 1]);
            // cout << dp[up][i] << " ";
            res = max(res, i - dp[up][i] + 1);
            la[a[up][i]] = i;
        }
        // cout << endl;
        for (int down = up - 1; down >= 1; down--){
            for (int i = 1; i <= m; i++){
                la[a[up][i]] = 0;
                la[a[down][i]] = 0;
            }
            // cout << "With: " << down << " " << up << endl;
            for (int i = 1; i <= m; i++){
                if (a[down][i] == a[up][i]){
                    dp[down][i] = i + 1;
                }
                maximize(dp[down][i], dp[down + 1][i]);
                maximize(dp[down][i], la[a[down][i]] + 1);
                maximize(dp[down][i], la[a[up][i]] + 1);
                maximize(dp[down][i], dp[down][i - 1]);
                la[a[down][i]] = i;
                la[a[up][i]] = i;
            }
            // for (int i = 1; i <= m; i++){
            //     cout << dp[down][i] << " ";
            // }
            // cout << endl;
            for (int i = 1; i <= m; i++){
                maximize(res, (i - dp[down][i] + 1) * (up - down + 1));
                // cout << " res: " << i << " " << res << endl;
            }
        }
    }

    cout << res << endl;
    return 0;
}

/*
1 120 723 035
*/