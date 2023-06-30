#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ii a, b, c;
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;
        int cntab = abs(a.fi - b.fi) + abs(a.se - b.se);
        int cntac = abs(a.fi - c.fi) + abs(a.se - c.se);
        int cntbc = abs(b.fi - c.fi) + abs(b.se - c.se);
        cout << (cntab + cntac - cntbc + 3) / 2 << endl;
    }
    return 0;
}