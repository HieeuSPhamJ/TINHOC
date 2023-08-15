#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

void conv(ii &x){
    while(!(x.fi > 0 and x.se >= 0)){
        swap(x.fi, x.se);
        x.se = -x.se;
    }
}

map<ii,int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++){
        ii x;
        cin >> x.fi >> x.se;
        conv(x);
        int g = __gcd(x.fi, x.se);
        x.fi /= g;
        x.se /= g;
        cnt[x]++;
        res = max(res,cnt[x]);
    }
    cout << res << endl;
    return 0;
}