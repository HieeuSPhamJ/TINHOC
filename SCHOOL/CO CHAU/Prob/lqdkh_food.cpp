#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int ans[maxN];

signed main(){
    freopen("food.INP", "r", stdin);
    freopen("food.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int res = 0;
    multiset <ii> s;
    for (int i = 1; i <= n; i++){
        s.insert({a[i],-i});
        if (i - k >= 1){
            s.erase(s.find({a[i - k], -(i - k)}));
        }
        auto it = s.begin();

        res += (*it).fi;
        ans[-(*it).se] += 2;
    }

    cout << res * 2<< endl;

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
dp[i]:
    = dp[i - k]
*/