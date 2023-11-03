#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e3 + 10;

int n, m;
pair<vector<int>,int> a[maxN];
int dp[maxN];
vector <int> ls[maxN];
bool cmp(int i,int j){
    for(int t=0;t<m;t++){
        if (a[i].fi[t] > a[j].fi[t]) return false;
    }
    return true;
}

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            a[i].fi.push_back(x);
        }
        sort(all(a[i].fi));
        a[i].se = i; 
    }

    sort(a + 1, a + 1 + n);

    int res = 0;

    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=i-1;j>=1;j--){
            if (cmp(j,i) and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        res = max(res, dp[i]);
        ls[dp[i]].push_back(a[i].se);
    }

    cout << res << endl;

    for (int i = 1; i <= res; i++){
        cout << ls[i].size() << " ";
        for (auto x: ls[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}