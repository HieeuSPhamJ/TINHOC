#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int n, m;
vector<ii> ls;
ii a[maxN];

signed main(){
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a, a + m);
    int l = 1, r = 1e18 + 5;
    while (l < r){
        int mid = (l + r + 1) / 2, num = 0, cur = a[0].fi, i = 0;
        while (num < n){
            while (num < n and cur >= a[i].fi and cur <= a[i].se){
                num++, cur += mid;
            }
            if (i == m - 1){
                break;
            }
            i++;
            cur = max(cur, a[i].fi);
        }
        if (num >= n){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}