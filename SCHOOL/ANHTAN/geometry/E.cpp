#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int area(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}


ii a[200];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    double s = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        for (int j = i - 1; j >= 1; j--){
            for (int k = j - 1; k >= 1; k--){
                // cout << i << ' ' << j << ' ' << k << ": " << endl;
                s += abs(area(a[i], a[j], a[k]));
            }
        }
    }

    cout << fixed << setprecision(1) << s / 2 << endl;
    
    return 0;
}