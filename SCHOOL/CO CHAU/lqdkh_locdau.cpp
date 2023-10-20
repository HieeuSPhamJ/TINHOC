#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int ans[maxN];

signed main(){
    freopen("locdau.INP", "r", stdin);
    freopen("locdau.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    double res = 0;
    multiset <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(a[i]);
        if (i - k >= 1){
            s.erase(s.find(a[i - k]));
        }
        auto it = s.begin();

        res += *it;
    }

    cout << fixed << setprecision(4) << res / n << endl;

    return 0;
}

/*
dp[i]:
    = dp[i - k]
*/