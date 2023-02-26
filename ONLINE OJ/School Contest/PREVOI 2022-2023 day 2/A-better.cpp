#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define high fi
#define at se
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e4 + 10;

ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <ii> s;
    set <ii> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i].at >> a[i].high;
        s.insert(a[i]);
        b.insert({a[i].at, a[i].high});
    }
    int ans = 0;
    
    while(b.size()){
        ans++;
        ii t = *s.rbegin();
        s.erase(t);
        auto mid1 = b.find({t.at,t.high});
        auto mid2 = mid1;
        while(mid1 != b.rend()){
            b.
        }
    }

    cout << ans << endl;

    return 0;
}