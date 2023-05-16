#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

ii a[maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    int SEGMINHTRI = -a[1].fi;
    int ans = -1e18;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i].se;
        ans = max(ans, pre[i] - a[i].fi - SEGMINHTRI);
        SEGMINHTRI = min(SEGMINHTRI, pre[i] - a[i + 1].fi);
    }   
    cout << ans << endl;
    return 0;
}