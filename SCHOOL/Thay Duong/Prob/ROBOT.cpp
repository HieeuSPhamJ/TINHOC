#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int px[maxN];
int py[maxN];

signed main(){
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <int> x;
    vector <int> y;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(-1e18);
    y.push_back(-1e18);  
    sort(all(x));
    sort(all(y));
    for (int i = 1; i <= n; i++){
        px[i] = px[i - 1] + x[i];
    }
    for (int i = 1; i <= n; i++){
        py[i] = py[i - 1] + y[i];
    }

    map <char,ii> di;
    di['S'] = {0,1};
    di['J'] = {0,-1};
    di['I'] = {1,0};
    di['Z'] = {-1,0};
    

    ii cur = {0,0};
    while(m--){ 
        int res = 0;
        char c;
        cin >> c;
        cur.fi += di[c].fi;
        cur.se += di[c].se;
        int ix = upper_bound(all(x), cur.fi) - x.begin() - 1;
        int iy = upper_bound(all(y), cur.se) - y.begin() - 1;
        // cout << cur.fi << "," << cur.se << endl;
        // cout << ix << " " << iy << endl;
        res += abs(cur.fi * ix - px[ix]) + abs(cur.se * iy - py[iy]);
        res += abs(cur.fi * (n - ix) - (px[n] - px[ix])) + abs(cur.se * (n - iy) - (py[n] - py[iy]));
        cout << res << endl;
    }
    return 0;
}