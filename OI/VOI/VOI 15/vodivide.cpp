#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5010;

int n;
pair<ii,int> a[maxN];

bool cmp(pair<ii,int> x, pair<ii,int> y){
    if (x.fi.fi != y.fi.fi){
        return x.fi.fi > y.fi.fi;
    }
    return x.se < y.se;
}

int dp[maxN / 2];
int cur[maxN / 2];
int mk[maxN];
int path[maxN][maxN / 2];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi.fi;
        a[i].fi.se = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);

    
    // for (int i = 1; i <= n; i++){
    //     cout << a[i].se << ' ';
    // }
    // cout << endl;

    memset(cur, -1, sizeof(cur));
    memset(dp, -1, sizeof(dp));

    cur[1] = 0;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= n / 2; j++){
            if (cur[j] == -1){
                continue;
            }
            if (cur[j] > dp[j + 1]){
                dp[j + 1] = cur[j];
                path[i][j + 1] = j;
            }
            if (j){
                if (cur[j] + a[i].se > dp[j - 1]){
                    dp[j - 1] = cur[j] + a[i].se;
                    path[i][j - 1] = j;
                }
            }

        }
        for (int j = 0; j <= n / 2; j++){
            if (dp[j] == -1){
                continue;
            }
            // cout << i << " " << j << ": " << dp[j] << endl;
            cur[j] = dp[j];
            dp[j] = -1;
        }
    }

    cout << cur[0] << endl;    

    for (int i = n, la = 0; i >= 1; i--){
        if (path[i][la] > la){
            mk[i] = 1;
        }
        la = path[i][la];
    }

    vector <int> st;

    for (int i = 1; i <= n; i++){
        if (mk[i]){
            cout << a[i].fi.se << " " << a[st.back()].fi.se << endl;
            st.pop_back();
        }
        else{
            st.push_back(i);
        }
    }
    
    return 0;
}