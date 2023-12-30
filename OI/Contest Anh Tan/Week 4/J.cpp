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
int dp[maxN][maxN][maxN];
unordered_map <int,vector <int>> st[maxN];

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
            // cin >> a[i][j];
            a[i][j] = (i - 1) * m + j;
            ss.push_back(a[i][j]);
        }
    }

    sort(all(ss));
    ss.erase(unique(all(ss)), ss.end());
    int mv = ss.size();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            a[i][j] = lower_bound(all(ss), a[i][j]) - ss.begin();
            st[j][a[i][j]].push_back(i);
        }
    }

    for (int t = 1; t <= mv; t++){
        // cout << "with: " << t << endl;
        for (int up = 1; up <= n; up++){
            for (int down = up; down <= n; down++){
                vector <int> &ls =  st[down][t];
                int L = (int)ls.size() - 1;
                for (int i = L, la = m; i >= 0; i--){
                    dp[up][down][ls[i]] = la;
                    la = ls[i];
                }
            }
        }
    }

    // for (int up = 1; up <= n; up++){
    //     for (int down = up; down <= n; down++){
    //         cout << up << " - " << down << ": " << endl;
    //         for (int i = 1; i <= m; i++){
    //             cout << dp[up][down][i] << " ";
    //         }
    //         cout << endl;
    //     }
    // }


    int res = 0;


    cout << res << endl;
    return 0;
}

/*
1 120 723 035
*/