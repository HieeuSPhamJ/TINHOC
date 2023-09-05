#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int n;
int a[maxN];
int cnt[maxN];
int pre[maxN];
int la[maxN];

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
    int res = 0;
    for (int i = 1; i <= n; i++){
        pre[a[i]] += cnt[a[i]] * (i - la[a[i]]);
        // cout << i << ": " << pre[a[i]] << " " << la[a[i]] << endl;
        res += pre[a[i]] - cnt[a[i]];
        cnt[a[i]]++;
        la[a[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        int k = cnt[i];
        // cout << k << endl;
        res -= k * (k - 1) * (k - 2) / 6;
    }
    cout << res << endl;

    return 0;
}