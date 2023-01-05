#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int a[maxN];

int pre[maxN];

int sum(int i, int j){
    return pre[j] - pre[i - 1];
}

int dp[maxN];

signed main(){
    freopen("Km1.INP", "r", stdin);
    freopen("Km1.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    multiset <int> q;

    for (int i = 1; i < c; i++){
        dp[i] = dp[i - 1] + a[i];
        q.insert(a[i]);
    }

    for (int i = c; i <= n; i++){
        q.insert(a[i]);
        dp[i] = min(dp[i - 1] + a[i], dp[i - c] + sum(i - c + 1, i) - *q.begin());
        q.erase(q.find(a[i - c + 1]));
    }

    cout << dp[n] << endl;

    return 0;
}