#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

ii a[maxN];
int p[maxN];

double len(ii x, ii y){
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s, A, B;
    cin >> s >> A >> B;
    int base = B - A;
    int n;
    cin >> n;
    a[0] = {0,0};
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        p[i] = p[i - 1] + a[i].se - a[i].fi;
    }
    int test;
    cin >> test;
    while(test--){
        int x, y;
        cin >> x >> y;
        int k = 1.0 * (y - s) / y;
        int l = x - y * 1.0 * (x - A) / (y - s);
        int r = x + 
    }
    return 0;
}