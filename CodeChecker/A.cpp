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
vector <int> st[maxN];
bool mk[maxN];

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
    int mv = ss.size();
    vector <pair<int,ii>> ls;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            a[i][j] = lower_bound(all(ss), a[i][j]) - ss.begin() + 1;
            ls.push_back({a[i][j], {i,j}});
        }
    }

    sort(rall(ls));

    // for (auto i: ls){
    //     cout << i.fi << " ";
    // }
    // cout << endl;

    for (int t = 1; t <= mv; t++){
        for (int i = 1; i <= n; i++){
            st[i].clear();
        }
        while(ls.size() and ls.back().fi == t){
            st[ls.back().se.fi].push_back(ls.back().se.se);
            ls.pop_back();
        }
        // cout << "With: " << t << endl;
        for (int up = 1; up <= n; up++){
            for (int i = 1; i <= m; i++){
                mk[i] = 0;
            }
            for (int down = up; down <= n; down++){
                // cout << up << " " << down << ": " << endl;
                int L = (int)st[down].size() - 1;
                for (int i = L, la = m + 1; i >= 0; i--){
                    // cout << st[down][i] << " ";
                    if (mk[st[down][i]] == 0){
                        dp[up][down][st[down][i]] = la - 1;
                        mk[st[down][i]] = 1;
                    }
                    else{
                        dp[up][down][st[down][i]] = st[down][i] - 1;
                    }
                    la = st[down][i];
                }
                // cout << endl;
            }
        }
    }

    for (int up = 1; up <= n; up++){
        for (int down = up + 1; down <= n; down++){
            for (int i = 1; i <= m; i++){
                if (minimize(dp[up][down][i], dp[up][down - 1][i]));
            }
        }
    }

    int res = 0;

    for (int up = 1; up <= n; up++){
        for (int down = up; down <= n; down++){
            for (int i = m - 1; i >= 1; i--){
                minimize(dp[up][down][i], dp[up][down][i + 1]);
            }
            // cout << up << " - " << down << ": " << endl;
            // for (int i = 1; i <= m; i++){
            //     cout << dp[up][down][i] << " ";
            // }
            // cout << endl;
        }
    }

    for (int up = 1; up <= n; up++){
        for (int down = up; down <= n; down++){
            for (int i = 1; i <= m; i++){
                    // cout << up << " " << down << " " << i << " :" << (down - up + 1) << endl;
                if (maximize(res, (down - up + 1) * (dp[up][down][i] - i + 1))){
                    // cout << up << " " << down << " " << i << " :" << res << endl;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}

/*
1 120 723 035
*/