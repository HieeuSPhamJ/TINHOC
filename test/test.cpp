#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

ii st[20010];
ii hs[1010];
int ans[1000];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    // freopen("PLAN.INP", "r", stdin);
    // freopen("PLAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> st[i].fi >> st[i].se;
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        ans[i] = 1e18;
        cin >> hs[i].fi >> hs[i].se;
    }
    for (int mask = 0; mask < (1 << m); mask++){
        int tres = 0;
        vector <int> ls;
        for (int i = 0; i < m; i++){
            if (mask & (1 << i)){
                ls.push_back(i);
                tres += st[i].se;
            }
        }
        for (int i = 1; i <= n; i++){
            int cur = hs[i].fi * hs[i].se;
            for (auto j: ls){
                if (st[j].fi <= hs[i].fi){
                    cur = min(cur, (hs[i].fi - st[j].fi) * hs[i].se);
                }
            }
            tres += cur;
            ans[i] = min(ans[i], tres);
        }
    }
    
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}

/*
dp[i][j]: số tiền nhỏ nhất để cho i thằng đầu về nhà với trạm bus cuối là j
dp[i][j] = dp[i - 1][j] + (hs[i].fi - st[j].fi) * hs[i].se
dp[i][j] = dp[i - 1][k] + (hs[i].fi - st[j].fi) * hs[i].se + st[j].se

*/