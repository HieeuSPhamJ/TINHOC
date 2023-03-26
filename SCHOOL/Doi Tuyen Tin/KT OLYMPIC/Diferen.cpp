#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 1e5 + 10;

int a[maxN];

signed main(){
    freopen("Diferen.INP", "r", stdin);
    freopen("Diferen.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        set <int> s;
        s.insert(a[i]);
        for (int j = i + 1; j <= n; j++){
            s.insert(a[j]);
            ans += abs(*s.begin() - *s.rbegin());
        }
    }

    cout << ans;
    return 0;
}