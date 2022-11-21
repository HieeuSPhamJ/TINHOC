#pragma GCC optimize("Os")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int n;
int a[maxN];
int dp[maxN][110];
int realVal[maxN];
unordered_set <int> store;
unordered_map <int,int> conv;

void nenso(){
    for (int i = 1; i <= n; i++){
        store.insert(a[i]);
    }

    // for (auto i: store){
    //     cout << i << " ";
    // }
    // cout << endl;

    int cnt = 1;
    for (auto i: store){
        realVal[cnt] = i;
        conv[i] = cnt;
        cnt++;
    }

    for (int i = 1; i <= n; i++){
        a[i] = conv[a[i]];
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    nenso();

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int d = 1; d <= 100; d++){
            if (store.find(realVal[a[i]] - d) == store.end()){
                dp[a[i]][d] = max(dp[a[i]][d], 1);
                continue;
            }
            dp[a[i]][d] = max(dp[a[i]][d], dp[conv[realVal[a[i]] - d]][d] + 1);
            ans = max(ans, dp[a[i]][d]);
        }
    }
    cout << ans;

    return 0;
}