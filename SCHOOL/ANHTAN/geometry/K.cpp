#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int area(ii a, ii b, ii c){
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se);
}

ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int s = area(a[x],a[y], a[i]);
        if (s == 0){
            continue;
        }
        if (s > 0){
            res++;
        }
        else{
            res--;
        }
    }
    cout << abs(res);
    return 0;
}